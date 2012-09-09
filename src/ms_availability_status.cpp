#include <ms_availability_status.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MsAvailabilityStatus::MsAvailabilityStatus(quint8 value):
  TLV(constants::TLVtags::MS_AVAILABILITY_STATUS, 1),
  value(value) {

}

MsAvailabilityStatus::MsAvailabilityStatus(
  const MsAvailabilityStatus &other):
    TLV(other),
    value(other.getValue()) {

}

bool MsAvailabilityStatus::operator ==(
  const MsAvailabilityStatus &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool MsAvailabilityStatus::operator !=(
  const MsAvailabilityStatus &other) const {
  return !this->operator ==(other);
}

MsAvailabilityStatus &MsAvailabilityStatus::operator =(
  const MsAvailabilityStatus &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void MsAvailabilityStatus::setValue(quint8 value) {
  this->value = value;
}

quint8 MsAvailabilityStatus::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
