#include <dest_addr_subunit.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestAddrSubunit::DestAddrSubunit(quint8 value):
  TLV(constants::TLVtags::DEST_ADDR_SUBUNIT, 1), value(value) {

}

DestAddrSubunit::DestAddrSubunit(const DestAddrSubunit &other):
  TLV(other), value(other.getValue()) {

}

bool DestAddrSubunit::operator ==(const DestAddrSubunit &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestAddrSubunit::operator !=(const DestAddrSubunit &other) const {
  return !this->operator ==(other);
}

DestAddrSubunit &DestAddrSubunit::operator =(const DestAddrSubunit &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestAddrSubunit::setValue(quint8 value) {
  this->value = value;
}

quint8 DestAddrSubunit::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
