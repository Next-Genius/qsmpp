#include <message_payload.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MessagePayload::MessagePayload(const octetString &value):
  TLV(constants::TLVtags::MESSAGE_PAYLOAD, value.size()), value(value) {

}

MessagePayload::MessagePayload(const MessagePayload &other):
  TLV(other), value(other.getValue()) {

}

bool MessagePayload::operator ==(const MessagePayload &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool MessagePayload::operator !=(const MessagePayload &other) const {
  return !this->operator ==(other);
}

MessagePayload &MessagePayload::operator =(const MessagePayload &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void MessagePayload::setValue(const octetString &value) {
  this->value = value;
}

octetString MessagePayload::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
