#include <broadcast_frequency_interval.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastFrequencyInterval::BroadcastFrequencyInterval(
  const octetString &value):
    TLV(constants::TLVtags::BROADCAST_FREQUENCY_INTERVAL, value.size()),
    value(value) {

}

BroadcastFrequencyInterval::BroadcastFrequencyInterval(
  const BroadcastFrequencyInterval &other):
    TLV(other),
    value(other.getValue()) {

}

bool BroadcastFrequencyInterval::operator ==(
  const BroadcastFrequencyInterval &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool BroadcastFrequencyInterval::operator !=(
  const BroadcastFrequencyInterval &other) const {
  return !this->operator ==(other);
}

BroadcastFrequencyInterval &BroadcastFrequencyInterval::operator =(
  const BroadcastFrequencyInterval &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastFrequencyInterval::setValue(const octetString &value) {
  this->value = value;
}

octetString BroadcastFrequencyInterval::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
