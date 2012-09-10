#include <privacy_indicator.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

PrivacyIndicator::PrivacyIndicator(quint8 value):
  TLV(constants::TLVtags::PRIVACY_INDICATOR, 1), value(value) {

}

PrivacyIndicator::PrivacyIndicator(const PrivacyIndicator &other):
  TLV(other), value(other.getValue()) {

}

bool PrivacyIndicator::operator ==(const PrivacyIndicator &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool PrivacyIndicator::operator !=(const PrivacyIndicator &other) const {
  return !this->operator ==(other);
}

PrivacyIndicator &PrivacyIndicator::operator =(const PrivacyIndicator &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void PrivacyIndicator::setValue(quint8 value) {
  this->value = value;
}

quint8 PrivacyIndicator::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
