#include <ms_msg_wait_facilities.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MsMsgWaitFacilities::MsMsgWaitFacilities(quint8 value):
  TLV(constants::TLVtags::MS_MSG_WAIT_FACILITIES, 1), value(value) {

}

MsMsgWaitFacilities::MsMsgWaitFacilities(const MsMsgWaitFacilities &other):
  TLV(other), value(other.getValue()) {

}

bool MsMsgWaitFacilities::operator ==(const MsMsgWaitFacilities &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool MsMsgWaitFacilities::operator !=(const MsMsgWaitFacilities &other) const {
  return !this->operator ==(other);
}

MsMsgWaitFacilities &MsMsgWaitFacilities::operator =(
  const MsMsgWaitFacilities &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void MsMsgWaitFacilities::setValue(quint8 value) {
  this->value = value;
}

quint8 MsMsgWaitFacilities::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
