#ifndef SMPP_HEADER_H
#define SMPP_HEADER_H

#include <command_id.h>
#include <command_length.h>
#include <command_status.h>
#include <sequence_number.h>
#include <tlv.h>
#include <iterator>
#include <list>

namespace smpp {

typedef std::list<const Tlv *> TlvList;

class Header {
  CommandLength command_length;
  CommandId command_id;
  CommandStatus command_status;
  SequenceNumber sequence_number;
  Header();

public:
  Header(const CommandLength &command_length,
         const CommandId &command_id,
         const CommandStatus &command_status,
         const SequenceNumber &sequence_number);

  ~Header() {}

  uint32 getCommandLength() const { return command_length; }

  uint32 getCommandId() const { return command_id; }

  uint32 getSequenceNumber() const { return sequence_number; }

  uint32 getCommandStatus() const{ return command_status; }

  void setCommandLength(const uint32 &p) { command_length = p; }

  void setCommandId(const uint32 &p) { command_id = p; }

  void setCommandStatus(const uint32 &p) { command_status = p; }

  void setSequenceNumber(const uint32 &p, bool allow_0 = false) {
    sequence_number = SequenceNumber(p, allow_0);
  }

protected:

  void updateLength(const int &p) { command_length += p; }
};

class TlvsHeader : public Header {
  struct CTlvList {
    struct Delete {
      void operator()(const Tlv *tlv) { delete tlv; }
    };

    struct Copy {
      Tlv *operator()(const Tlv *tp) { return new Tlv(*tp); }
    };

    TlvList list;

    CTlvList() {}
    ~CTlvList() throw() {
      std::for_each(list.begin(), list.end(), Delete());
    }

    CTlvList(const CTlvList &t) {
      std::transform(t.list.begin(),
                     t.list.end(),
                     std::back_inserter(list),
                     Copy());
    }

    CTlvList &operator =(const CTlvList &t) {
      if(this == &t) return *this;
      std::transform(t.list.begin(),
                     t.list.end(),
                     std::back_inserter(list),
                     Copy());
      return *this;
    }
  } tlvs;

public:
  TlvsHeader(const CommandLength &command_length,
             const CommandId &command_id,
             const CommandStatus &command_status,
             const SequenceNumber &sequence_number);

  void insertTlv(const Tlv &tlv) {
    insertTlv(new Tlv(tlv));
  }

  void insert8bitTlv(uint16 t, const uint8 &v) {
    insertTlv(new Tlv(t, 1, &v));
  }

  void insert16bitTlv(uint16 t, uint16 v) {
    uint16 i = hton16(v);
    insertTlv(new Tlv(t, 2, reinterpret_cast<uint8 *>(&i)));
  }

  void insert32bitTlv(uint16 t, uint32 v) {
    uint32 i = hton32(v);
    insertTlv(new Tlv(t, 4, reinterpret_cast<uint8 *>(&i)));
  }

  void insertStringTlv(uint16 t, const CString &v) {
    insertTlv(new Tlv(t,
                      v.length()+1,
                      reinterpret_cast<const uint8*>(v.data())));
  }

  void insertArrayTlv(uint16 t, uint16 l, const uint8 *v) {
    insertTlv(new Tlv(t, l, v));
  }

  const TlvList &getTlvList() const {
    return tlvs.list;
  }

  class ListFinder {
    TlvList &l;
    uint16 tag;
  public:
    ListFinder(TlvList &l, uint16 tag) : l(l), tag(tag) {}
    void operator()(const Tlv *tlv) {
      if(tlv->getTag() == tag)
        l.push_back(tlv);
    }

    const TlvList &getList() const { return l; }
  };

  const TlvList findTlvList(uint16 tag) const {
    TlvList l;
    ListFinder t(l, tag);
    std::for_each(tlvs.list.begin(), tlvs.list.end(), t);
    return t.getList();
  }

  const Tlv *findTlv(uint16 tag) const {
    TlvList::const_iterator i = std::find_if(tlvs.list.begin(),
                                             tlvs.list.end(),
                                             Tlv::CompareTag(tag));
    if(i == tlvs.list.end())
      return 0;
    return *i;
  }

  void removeTlv(uint16 tag) {
    for(TlvList::iterator i = std::find_if(tlvs.list.begin(),
                                           tlvs.list.end(),
                                           Tlv::CompareTag(tag));
        i != tlvs.list.end();
        i = std::find_if(i, tlvs.list.end(), Tlv::CompareTag(tag))) {
      TlvList::iterator j = i;
      ++j;
      const Tlv *t = *i;
      tlvs.list.erase(i);
      updateLength(0 - (t->getLength() + 4));
      delete t;
      i = j;
    }
  }

protected:
  void insertTlv(const Tlv *tlv) {
    tlvs.list.push_back(tlv);
    updateLength(tlv->getLength() + 4);
  }

  void insertAfterTlv(const Tlv *tlv, smpp::uint16 tag);

  void insertBeforeTlv(const Tlv *tlv, smpp::uint16 tag);
};

} // namespace smpp

#endif // SMPP_HEADER_H
