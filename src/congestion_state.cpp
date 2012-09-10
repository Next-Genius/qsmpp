#include <congestion_state.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

CongestionState::CongestionState(quint8 value):
  TLV(constants::TLVtags::CONGESTION_STATE, 1), value(value) {

}

CongestionState::CongestionState(const CongestionState &other):
  TLV(value), value(other.getValue()) {

}

bool CongestionState::operator ==(const CongestionState &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool CongestionState::operator !=(const CongestionState &other) const {
  return !this->operator ==(other);
}

CongestionState &CongestionState::operator =(const CongestionState &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void CongestionState::setValue(quint8 value) {
  this->value = value;
}

quint8 CongestionState::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

