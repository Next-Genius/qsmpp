#include <dest_addr_np_country.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestAddrNpCountry::DestAddrNpCountry(const octetString &value):
  TLV(constants::TLVtags::DEST_ADDR_NP_COUNTRY, value.size()), value(value) {

}

DestAddrNpCountry::DestAddrNpCountry(const DestAddrNpCountry &other):
  TLV(other), value(other.getValue()) {

}

bool DestAddrNpCountry::operator ==(const DestAddrNpCountry &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestAddrNpCountry::operator !=(const DestAddrNpCountry &other) const {
  return !this->operator ==(other);
}

DestAddrNpCountry &DestAddrNpCountry::operator =(
  const DestAddrNpCountry &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestAddrNpCountry::setValue(const octetString &value) {
  this->value = value;
}

octetString DestAddrNpCountry::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

