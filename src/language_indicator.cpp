#include <language_indicator.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

LanguageIndicator::LanguageIndicator(quint8 value):
  TLV(constants::TLVtags::LANGUAGE_INDICATOR, 1), value(value) {

}

LanguageIndicator::LanguageIndicator(const LanguageIndicator &other):
  TLV(other), value(other.getValue()) {

}

bool LanguageIndicator::operator ==(const LanguageIndicator &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool LanguageIndicator::operator !=(const LanguageIndicator &other) const {
  return !this->operator ==(other);
}

LanguageIndicator &LanguageIndicator::operator =(const LanguageIndicator &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void LanguageIndicator::setValue(quint8 value) {
  this->value = value;
}

quint8 LanguageIndicator::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
