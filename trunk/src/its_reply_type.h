#ifndef QSMPP_ITS_REPLY_TYPE_H
#define QSMPP_ITS_REPLY_TYPE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT ItsReplyType : public TLV {
  quint8 value;
public:
  ItsReplyType(quint8 value = 0);

  ItsReplyType(const ItsReplyType &other);

  bool operator ==(const ItsReplyType &other) const;

  bool operator !=(const ItsReplyType &other) const;

  ItsReplyType &operator =(const ItsReplyType &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_ITS_REPLY_TYPE_H
