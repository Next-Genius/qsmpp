#include <more_messages_to_send.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MoreMessagesToSend::MoreMessagesToSend(quint8 value):
  TLV(constants::TLVtags::MORE_MESSAGES_TO_SEND, 1), value(value) {

}

MoreMessagesToSend::MoreMessagesToSend(const MoreMessagesToSend &other):
  TLV(other), value(other.getValue()) {

}

bool MoreMessagesToSend::operator ==(const MoreMessagesToSend &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool MoreMessagesToSend::operator !=(const MoreMessagesToSend &other) const {
  return !this->operator ==(other);
}

MoreMessagesToSend &MoreMessagesToSend::operator =(
  const MoreMessagesToSend &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void MoreMessagesToSend::setValue(quint8 value) {
  this->value = value;
}

quint8 MoreMessagesToSend::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
