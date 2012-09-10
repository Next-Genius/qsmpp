#include <its_session_info.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

ItsSessionInfo::ItsSessionInfo(quint16 value):
  TLV(constants::TLVtags::ITS_SESSION_INFO, 2), value(value) {

}

ItsSessionInfo::ItsSessionInfo(const ItsSessionInfo &other):
  TLV(other), value(other.getValue()) {

}

bool ItsSessionInfo::operator ==(const ItsSessionInfo &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool ItsSessionInfo::operator !=(const ItsSessionInfo &other) const {
  return !this->operator ==(other);
}

ItsSessionInfo &ItsSessionInfo::operator =(const ItsSessionInfo &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void ItsSessionInfo::setValue(quint16 value) {
  this->value = value;
}

quint16 ItsSessionInfo::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
