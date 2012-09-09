#include <broadcast_area_success.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastAreaSuccess::BroadcastAreaSuccess(quint8 value):
  TLV(constants::TLVtags::BROADCAST_AREA_SUCCESS, 1),
  value(value) {

}

BroadcastAreaSuccess::BroadcastAreaSuccess(
  const BroadcastAreaSuccess &other):
    TLV(other),
    value(other.getValue()) {

}

bool BroadcastAreaSuccess::operator ==(
  const BroadcastAreaSuccess &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool BroadcastAreaSuccess::operator !=(
  const BroadcastAreaSuccess &other) const {
  return !this->operator ==(other);
}

BroadcastAreaSuccess &BroadcastAreaSuccess::operator =(
  const BroadcastAreaSuccess &other) {
  if(*this == other)
    return *this;
  TLV::operator = (other);
  value = other.getValue();
  return *this;
}

void BroadcastAreaSuccess::setValue(quint8 value) {
  this->value = value;
}

quint8 BroadcastAreaSuccess::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
