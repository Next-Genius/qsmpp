#include <ussd_service_op.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

UssdServiceOp::UssdServiceOp(quint8 value):
  TLV(constants::TLVtags::USSD_SERVICE_OP, 1), value(value) {

}

UssdServiceOp::UssdServiceOp(const UssdServiceOp &other):
  TLV(other), value(other.getValue()) {

}

bool UssdServiceOp::operator ==(const UssdServiceOp &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool UssdServiceOp::operator !=(const UssdServiceOp &other) const {
  return !this->operator ==(other);
}

UssdServiceOp &UssdServiceOp::operator =(
  const UssdServiceOp &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void UssdServiceOp::setValue(quint8 value) {
  this->value = value;
}

quint8 UssdServiceOp::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
