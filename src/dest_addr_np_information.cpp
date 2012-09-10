#include <dest_addr_np_information.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestAddrNpInformation::DestAddrNpInformation(const octetString &value):
  TLV(constants::TLVtags::DEST_ADDR_NP_INFORMATION, value.size()),
  value(value) {

}

DestAddrNpInformation::DestAddrNpInformation(
  const DestAddrNpInformation &other):
    TLV(other), value(other.getValue()) {

}

bool DestAddrNpInformation::operator ==(
  const DestAddrNpInformation &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestAddrNpInformation::operator !=(
  const DestAddrNpInformation &other) const {
  return !this->operator ==(other);
}

DestAddrNpInformation &DestAddrNpInformation::operator =(
  const DestAddrNpInformation &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestAddrNpInformation::setValue(const octetString &value) {
  this->value = value;
}

octetString DestAddrNpInformation::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
