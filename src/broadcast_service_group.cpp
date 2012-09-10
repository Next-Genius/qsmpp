#include <broadcast_service_group.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastServiceGroup::BroadcastServiceGroup(const octetString &value):
  TLV(constants::TLVtags::BROADCAST_SERVICE_GROUP, value.size()),
  value(value) {

}

BroadcastServiceGroup::BroadcastServiceGroup(
  const BroadcastServiceGroup &other):
    TLV(other), value(other.getValue()) {

}

bool BroadcastServiceGroup::operator ==(
  const BroadcastServiceGroup &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool BroadcastServiceGroup::operator !=(
  const BroadcastServiceGroup &other) const {
  return !this->operator ==(other);
}

BroadcastServiceGroup &BroadcastServiceGroup::operator =(
  const BroadcastServiceGroup &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastServiceGroup::setValue(const octetString &value) {
  this->value = value;
}

octetString BroadcastServiceGroup::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
