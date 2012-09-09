#include <broadcast_error_status.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastErrorStatus::BroadcastErrorStatus(quint32 value):
  TLV(constants::TLVtags::BROADCAST_ERROR_STATUS, 4),
  value(value) {

}

BroadcastErrorStatus::BroadcastErrorStatus(
  const BroadcastErrorStatus &other):
    TLV(other),
    value(other.getValue()) {

}

bool BroadcastErrorStatus::operator ==(
  const BroadcastErrorStatus &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool BroadcastErrorStatus::operator !=(
  const BroadcastErrorStatus &other) const {
  return !this->operator ==(other);
}

BroadcastErrorStatus &BroadcastErrorStatus::operator =(
  const BroadcastErrorStatus &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastErrorStatus::setValue(quint32 value) {
  this->value = value;
}

quint32 BroadcastErrorStatus::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
