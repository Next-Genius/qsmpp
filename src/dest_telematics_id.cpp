#include <dest_telematics_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestTelematicsId::DestTelematicsId(quint16 value):
  TLV(constants::TLVtags::DEST_TELEMATICS_ID, 2), value(value) {

}

DestTelematicsId::DestTelematicsId(const DestTelematicsId &other):
  TLV(other), value(other.getValue()) {

}

bool DestTelematicsId::operator ==(const DestTelematicsId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestTelematicsId::operator !=(const DestTelematicsId &other) const {
  return !this->operator ==(other);
}

DestTelematicsId &DestTelematicsId::operator =(const DestTelematicsId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestTelematicsId::setValue(quint16 value) {
  this->value = value;
}

quint16 DestTelematicsId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
