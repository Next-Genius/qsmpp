#include <source_port.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourcePort::SourcePort(quint16 value):
  TLV(constants::TLVtags::SOURCE_PORT, 2), value(value) {

}

SourcePort::SourcePort(const SourcePort &other):
  TLV(other), value(other.getValue()) {

}

bool SourcePort::operator ==(const SourcePort &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourcePort::operator !=(const SourcePort &other) const {
  return !this->operator ==(other);
}

SourcePort &SourcePort::operator =(
  const SourcePort &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourcePort::setValue(quint16 value) {
  this->value = value;
}

quint16 SourcePort::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
