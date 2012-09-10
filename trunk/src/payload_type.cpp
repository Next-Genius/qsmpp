#include <payload_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

PayloadType::PayloadType(quint8 value):
  TLV(constants::TLVtags::PAYLOAD_TYPE, 1), value(value) {

}

PayloadType::PayloadType(const PayloadType &other):
  TLV(other), value(other.getValue()) {

}

bool PayloadType::operator ==(const PayloadType &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool PayloadType::operator !=(const PayloadType &other) const {
  return !this->operator ==(other);
}

PayloadType &PayloadType::operator =(const PayloadType &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void PayloadType::setValue(quint8 value) {
  this->value = value;
}

quint8 PayloadType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
