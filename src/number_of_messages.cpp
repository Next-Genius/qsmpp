#include <number_of_messages.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

NumberOfMessages::NumberOfMessages(quint8 value):
  TLV(constants::TLVtags::NUMBER_OF_MESSAGES, 1), value(value) {

}

NumberOfMessages::NumberOfMessages(const NumberOfMessages &other):
  TLV(other), value(other.getValue()) {

}

bool NumberOfMessages::operator ==(const NumberOfMessages &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool NumberOfMessages::operator !=(const NumberOfMessages &other) const {
  return !this->operator ==(other);
}

NumberOfMessages &NumberOfMessages::operator =(const NumberOfMessages &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void NumberOfMessages::setValue(quint8 value) {
  this->value = value;
}

quint8 NumberOfMessages::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
