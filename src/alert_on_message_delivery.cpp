#include <alert_on_message_delivery.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

AlertOnMessageDelivery::AlertOnMessageDelivery(
  const octetString &value):
    TLV(constants::TLVtags::ALERT_ON_MESSAGE_DELIVERY,
        value.size()),
    value(value) {

}

AlertOnMessageDelivery::AlertOnMessageDelivery(
  const AlertOnMessageDelivery &other):
    TLV(other),
    value(other.getValue()) {

}

bool AlertOnMessageDelivery::operator ==(
  const AlertOnMessageDelivery &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool AlertOnMessageDelivery::operator !=(
  const AlertOnMessageDelivery &other) const {
  return !this->operator ==(other);
}

AlertOnMessageDelivery &AlertOnMessageDelivery::operator =(
  const AlertOnMessageDelivery &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void AlertOnMessageDelivery::setValue(const octetString &value) {
  this->value = value;
}

octetString AlertOnMessageDelivery::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
