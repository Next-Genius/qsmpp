#include <source_addr_subunit.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceAddrSubunit::SourceAddrSubunit(quint8 value):
  TLV(constants::TLVtags::SOURCE_ADDR_SUBUNIT, 1), value(value) {

}

SourceAddrSubunit::SourceAddrSubunit(const SourceAddrSubunit &other):
  TLV(other), value(other.getValue()) {

}

bool SourceAddrSubunit::operator ==(const SourceAddrSubunit &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceAddrSubunit::operator !=(const SourceAddrSubunit &other) const {
  return !this->operator ==(other);
}

SourceAddrSubunit &SourceAddrSubunit::operator =(
  const SourceAddrSubunit &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceAddrSubunit::setValue(quint8 value) {
  this->value = value;
}

quint8 SourceAddrSubunit::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
