#include <source_subaddress.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceSubaddress::SourceSubaddress(const octetString &value):
  TLV(constants::TLVtags::SOURCE_SUBADDRESS, value.size()), value(value) {

}

SourceSubaddress::SourceSubaddress(const SourceSubaddress &other):
  TLV(other), value(other.getValue()) {

}

bool SourceSubaddress::operator ==(const SourceSubaddress &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceSubaddress::operator !=(const SourceSubaddress &other) const {
  return !this->operator ==(other);
}

SourceSubaddress &SourceSubaddress::operator =(const SourceSubaddress &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceSubaddress::setValue(const octetString &value) {
  this->value = value;
}

octetString SourceSubaddress::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
