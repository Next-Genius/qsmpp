#include <dest_subaddress.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestSubaddress::DestSubaddress(const octetString &value):
  TLV(constants::TLVtags::DEST_SUBADDRESS, value.size()), value(value) {

}

DestSubaddress::DestSubaddress(const DestSubaddress &other):
  TLV(other), value(other.getValue()) {

}

bool DestSubaddress::operator ==(const DestSubaddress &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestSubaddress::operator !=(const DestSubaddress &other) const {
  return !this->operator ==(other);
}

DestSubaddress &DestSubaddress::operator =(const DestSubaddress &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestSubaddress::setValue(const octetString &value) {
  this->value = value;
}

octetString DestSubaddress::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
