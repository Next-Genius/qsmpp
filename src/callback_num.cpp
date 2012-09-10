#include <callback_num.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

CallbackNum::CallbackNum(const octetString &value):
  TLV(constants::TLVtags::CALLBACK_NUM, value.size()), value(value) {

}

CallbackNum::CallbackNum(const CallbackNum &other):
  TLV(other), value(other.getValue()) {

}

bool CallbackNum::operator ==(const CallbackNum &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool CallbackNum::operator !=(const CallbackNum &other) const {
  return !this->operator ==(other);
}

CallbackNum &CallbackNum::operator =(const CallbackNum &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void CallbackNum::setValue(const octetString &value) {
  this->value = value;
}

octetString CallbackNum::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
