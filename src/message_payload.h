#ifndef QSMPP_MESSAGE_PAYLOAD_H
#define QSMPP_MESSAGE_PAYLOAD_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MessagePayload : public TLV {
  octetString value;
public:
  MessagePayload(const octetString &value);

  MessagePayload(const MessagePayload &other);

  bool operator ==(const MessagePayload &other) const;

  bool operator !=(const MessagePayload &other) const;

  MessagePayload &operator =(const MessagePayload &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MESSAGE_PAYLOAD_H
