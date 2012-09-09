#include <additional_status_info_text.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

AdditionalStatusInfoText::AdditionalStatusInfoText(
  const CoctetString &value):
    TLV(constants::TLVtags::ADDITIONAL_STATUS_INFO_TEXT,
        value.size() + 1),
    value(value) {

}

AdditionalStatusInfoText::AdditionalStatusInfoText(
  const AdditionalStatusInfoText &other):
    TLV(other),
    value(other.getValue()) {

}

bool AdditionalStatusInfoText::operator ==(
  const AdditionalStatusInfoText &other) const {
  return (TLV::operator ==(other) &&
          value == other.getValue());
}

bool AdditionalStatusInfoText::operator !=(
  const AdditionalStatusInfoText &other) const {
  return !this->operator ==(other);
}

AdditionalStatusInfoText &AdditionalStatusInfoText::operator =(
  const AdditionalStatusInfoText &other) {
  if(*this == other)
      return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void AdditionalStatusInfoText::setValue(const CoctetString &value) {
  this->value = value;
}

CoctetString AdditionalStatusInfoText::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
