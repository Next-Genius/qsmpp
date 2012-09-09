#include <billing_identification.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BillingIdentification::BillingIdentification(
  const octetString &value):
    TLV(constants::TLVtags::BILLING_IDENTIFICATION,
        value.size()),
    value(value) {

}

BillingIdentification::BillingIdentification(
  const BillingIdentification &other):
    TLV(other),
    value(other.getValue()) {

}

bool BillingIdentification::operator ==(
  const BillingIdentification &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool BillingIdentification::operator !=(
  const BillingIdentification &other) const {
  return !this->operator ==(other);
}

BillingIdentification &BillingIdentification::operator =(
  const BillingIdentification &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BillingIdentification::setValue(const octetString &value) {
  this->value = value;
}

octetString BillingIdentification::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
