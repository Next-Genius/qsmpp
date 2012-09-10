#include <ms_validity.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MsValidity::MsValidity(const octetString &value):
  TLV(constants::TLVtags::MS_VALIDITY, value.size()), value(value) {

}

MsValidity::MsValidity(const MsValidity &other):
  TLV(other), value(other.getValue()) {

}

bool MsValidity::operator ==(const MsValidity &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool MsValidity::operator !=(const MsValidity &other) const {
  return !this->operator ==(other);
}

MsValidity &MsValidity::operator =(const MsValidity &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void MsValidity::setValue(const octetString &value) {
  this->value = value;
}

octetString MsValidity::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
