#ifndef SMPP_HEADER_H
#define SMPP_HEADER_H

#include <command_id.h>
#include <command_length.h>
#include <command_status.h>
#include <sequence_number.h>
#include <tlv.h>
#include <data_functions.h>
#include <iterator>
#include <list>

namespace smpp {

typedef std::list<const Tlv *> TlvList;

class Header {
  CommandLength command_length;
  CommandId command_id;
  CommandStatus command_status;
  SequenceNumber sequence_number;
  struct CTlvList {
    struct Delete {
      void operator()(const Tlv *tlv) { delete tlv; }
    };

    struct Copy {
      Tlv *operator()(const Tlv *tp) { return new Tlv(*tp); }
    };

    TlvList list_;

    CTlvList() {}
    ~CTlvList() throw() {
      std::for_each(list_.begin(), list_.end(), Delete());
    }

    CTlvList(const CTlvList &t) {
      std::transform(t.list_.begin(),
                     t.list_.end(),
                     std::back_inserter(list_),
                     Copy());
    }

    CTlvList &operator =(const CTlvList &t) {
      if(this == &t) return *this;
      std::transform(t.list_.begin(),
                     t.list_.end(),
                     std::back_inserter(list_),
                     Copy());
      return *this;
    }
  } tlvs_;
  Header();

public:
  virtual ~Header();

  /* Accessing */

  uint32 getCommandLength() const { return command_length; }

  uint32 getCommandId() const { return command_id; }

  uint32 getSequenceNumber() const { return sequence_number; }

  virtual uint32 getCommandStatus() const = 0;

  /* Mutating */

  void setSequenceNumber(const uint32 &p, bool allow_0 = false) {
    sequence_number = SequenceNumber(p, allow_0);
  }

  virtual void setCommandStatus(const CommandStatus &command_status) = 0;

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
    return tlvs_.list_;
  }

  class ListFinder {
    TlvList &l_;
    uint16 tag_;
  public:
    ListFinder(TlvList& l, uint16 tag) : l_(l), tag_(tag) {}
    void operator()(const Tlv* tlv) {
      if(tlv->getTag() == tag_)
        l_.push_back(tlv);
    }

    const TlvList& getList() const { return l_; }
  };

  const TlvList findTlvList(uint16 tag) const {
    TlvList l;
    ListFinder t(l, tag);
    std::for_each(tlvs_.list_.begin(), tlvs_.list_.end(), t);
    return t.getList();
  }

  const Tlv* findTlv(uint16 tag) const {
    TlvList::const_iterator i = std::find_if(tlvs_.list_.begin(),
                                             tlvs_.list_.end(),
                                             Tlv::CompareTag(tag));
    if(i == tlvs_.list_.end())
      return 0;
    return *i;
  }

  void removeTlv(uint16 tag) {
    for(TlvList::iterator i = std::find_if(tlvs_.list_.begin(),
                                           tlvs_.list_.end(),
                                           Tlv::CompareTag(tag));
        i != tlvs_.list_.end();
        i = std::find_if(i, tlvs_.list_.end(), Tlv::CompareTag(tag))) {
      TlvList::iterator j = i;
      ++j;
      const Tlv* t = *i;
      tlvs_.list_.erase(i);
      updateLength(0 - (t->getLength() + 4));
      delete t;
      i = j;
    }
  }

protected:
  Header(const CommandLength &command_length,
         const CommandId &command_id,
         const CommandStatus &command_status,
         const SequenceNumber &sequence_number);

  const CommandStatus &getCommandStatusP() const {
    return command_status;
  }

  void setCommandStatusP(const CommandStatus &p) {
    command_status = p;
  }

  void setCommandLength(const uint32 &p) { command_length = p; }

  void updateLength(const int &p) { command_length += p; }

  void insertTlv(const Tlv *tlv) {
    tlvs_.list_.push_back(tlv);
    updateLength(tlv->getLength() + 4);
  }

  void insertAfterTlv(const Tlv *tlv, smpp::uint16 tag);

  void insertBeforeTlv(const Tlv *tlv, smpp::uint16 tag);
};

class Request : public Header {
  void setCommandStatus(const uint32 &command_status) {}
public:
  uint32 getCommandStatus() const { return Header::getCommandStatusP(); }
protected:
  Request(const CommandLength &command_length,
          const CommandId &command_id,
          const SequenceNumber &sequence_number);
};

class Response : public Header {
public:
  void setCommandStatus(const uint32 &p) {
    Header::setCommandStatus(p);
  }

  uint32 getCommandStatus() const {
    return Header::getCommandStatusP();
  }
protected:
  Response(const CommandLength &command_length,
           const CommandId &command_id,
           const CommandStatus &command_status,
           const SequenceNumber &sequence_number);
};

} // namespace smpp

#endif // SMPP_HEADER_H
