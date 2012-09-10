#include <broadcast_channel_indicator.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastChannelIndicator::BroadcastChannelIndicator(quint8 value):
  TLV(constants::TLVtags::BROADCAST_CHANNEL_INDICATOR, 1), value(value) {

}

BroadcastChannelIndicator::BroadcastChannelIndicator(
  const BroadcastChannelIndicator &other):
    TLV(other), value(other.getValue()) {

}

bool BroadcastChannelIndicator::operator ==(
  const BroadcastChannelIndicator &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool BroadcastChannelIndicator::operator !=(
  const BroadcastChannelIndicator &other) const {
  return !this->operator ==(other);
}

BroadcastChannelIndicator &BroadcastChannelIndicator::operator =(
  const BroadcastChannelIndicator &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastChannelIndicator::setValue(quint8 value) {
  this->value = value;
}

quint8 BroadcastChannelIndicator::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
