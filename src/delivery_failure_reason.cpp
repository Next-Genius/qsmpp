#include <delivery_failure_reason.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DeliveryFailureReason::DeliveryFailureReason(quint8 value):
  TLV(constants::TLVtags::DELIVERY_FAILURE_REASON, 1), value(value) {

}

DeliveryFailureReason::DeliveryFailureReason(
  const DeliveryFailureReason &other):
    TLV(other), value(other.getValue()) {

}

bool DeliveryFailureReason::operator ==(
  const DeliveryFailureReason &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DeliveryFailureReason::operator !=(
  const DeliveryFailureReason &other) const {
  return !this->operator ==(other);
}

DeliveryFailureReason &DeliveryFailureReason::operator =(
  const DeliveryFailureReason &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DeliveryFailureReason::setValue(quint8 value) {
  this->value = value;
}

quint8 DeliveryFailureReason::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

