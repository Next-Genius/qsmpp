#include <broadcast_end_time.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastEndTime::BroadcastEndTime(const CoctetString &value):
  TLV(constants::TLVtags::BROADCAST_END_TIME, value.size() + 1),
  value(value) {

}

BroadcastEndTime::BroadcastEndTime(
  const BroadcastEndTime &other):
    TLV(other),
    value(other.getValue()) {

}

bool BroadcastEndTime::operator ==(
  const BroadcastEndTime &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool BroadcastEndTime::operator !=(
  const BroadcastEndTime &other) const {
  return !this->operator ==(other);
}

BroadcastEndTime &BroadcastEndTime::operator =(
  const BroadcastEndTime &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastEndTime::setValue(const CoctetString &value) {
  this->value = value;
}

CoctetString BroadcastEndTime::getValue() const {
  return value;
}

} //namespace tlv
} // namespace pdu
} // namespace qsmpp
