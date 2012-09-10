#include <message_state.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MessageState::MessageState(quint8 value):
  TLV(constants::TLVtags::MESSAGE_STATE, 1), value(value) {

}

MessageState::MessageState(const MessageState &other):
  TLV(other), value(other.getValue()) {

}

bool MessageState::operator ==(const MessageState &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool MessageState::operator !=(const MessageState &other) const {
  return !this->operator ==(other);
}

MessageState &MessageState::operator =(const MessageState &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void MessageState::setValue(quint8 value) {
  this->value = value;
}

quint8 MessageState::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
