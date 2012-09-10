#include <network_error_code.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

NetworkErrorCode::NetworkErrorCode(const octetString &value):
  TLV(constants::TLVtags::NETWORK_ERROR_CODE, value.size()), value(value) {

}

NetworkErrorCode::NetworkErrorCode(const NetworkErrorCode &other):
  TLV(other), value(other.getValue()) {

}

bool NetworkErrorCode::operator ==(const NetworkErrorCode &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool NetworkErrorCode::operator !=(const NetworkErrorCode &other) const {
  return !this->operator ==(other);
}

NetworkErrorCode &NetworkErrorCode::operator =(const NetworkErrorCode &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void NetworkErrorCode::setValue(const octetString &value) {
  this->value = value;
}

octetString NetworkErrorCode::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
