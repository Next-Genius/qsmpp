#include <broadcast_area_identifier.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastAreaIdentifier::BroadcastAreaIdentifier(const octetString &value):
    TLV(constants::TLVtags::BROADCAST_AREA_IDENTIFIER, value.size()),
    value(value) {

}

BroadcastAreaIdentifier::BroadcastAreaIdentifier(
  const BroadcastAreaIdentifier &other):
    TLV(other), value(other.getValue()) {

}

bool BroadcastAreaIdentifier::operator ==(
    const BroadcastAreaIdentifier &other) const {
    return (TLV::operator ==(other) && value == other.getValue());
}

bool BroadcastAreaIdentifier::operator !=(
    const BroadcastAreaIdentifier &other) const {
    return !this->operator ==(other);
}

BroadcastAreaIdentifier &BroadcastAreaIdentifier::operator =(
    const BroadcastAreaIdentifier &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastAreaIdentifier::setValue(const octetString &value) {
  this->value = value;
}

octetString BroadcastAreaIdentifier::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
