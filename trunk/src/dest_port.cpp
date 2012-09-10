#include <dest_port.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestPort::DestPort(quint16 value):
  TLV(constants::TLVtags::DEST_PORT, 2), value(value) {

}

DestPort::DestPort(const DestPort &other): TLV(other), value(other.getValue()) {

}

bool DestPort::operator ==(const DestPort &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestPort::operator !=(const DestPort &other) const {
  return !this->operator ==(other);
}

DestPort &DestPort::operator =(const DestPort &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestPort::setValue(quint16 value) {
  this->value = value;
}

quint16 DestPort::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
