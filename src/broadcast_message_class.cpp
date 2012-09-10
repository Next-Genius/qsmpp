#include <broadcast_message_class.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastMessageClass::BroadcastMessageClass(quint8 value):
  TLV(constants::TLVtags::BROADCAST_MESSAGE_CLASS, 1), value(value) {

}

BroadcastMessageClass::BroadcastMessageClass(
  const BroadcastMessageClass &other):
    TLV(other), value(other.getValue()) {

}

bool BroadcastMessageClass::operator ==(
  const BroadcastMessageClass &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool BroadcastMessageClass::operator !=(
  const BroadcastMessageClass &other) const {
  return !this->operator ==(other);
}

BroadcastMessageClass &BroadcastMessageClass::operator =(
  const BroadcastMessageClass &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastMessageClass::setValue(quint8 value) {
  this->value = value;
}

quint8 BroadcastMessageClass::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
