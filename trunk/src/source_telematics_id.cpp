#include <source_telematics_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceTelematicsId::SourceTelematicsId(quint8 value):
  TLV(constants::TLVtags::SOURCE_TELEMATICS_ID, 1), value(value) {

}

SourceTelematicsId::SourceTelematicsId(const SourceTelematicsId &other):
  TLV(other), value(other.getValue()) {

}

bool SourceTelematicsId::operator ==(const SourceTelematicsId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceTelematicsId::operator !=(const SourceTelematicsId &other) const {
  return !this->operator ==(other);
}

SourceTelematicsId &SourceTelematicsId::operator =(
  const SourceTelematicsId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceTelematicsId::setValue(quint8 value) {
  this->value = value;
}

quint8 SourceTelematicsId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
