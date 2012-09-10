#include <sar_msg_ref_num.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SarMsgRefNum::SarMsgRefNum(quint16 value):
  TLV(constants::TLVtags::SAR_MSG_REF_NUM, 2), value(value) {

}

SarMsgRefNum::SarMsgRefNum(const SarMsgRefNum &other):
  TLV(other), value(other.getValue()) {

}

bool SarMsgRefNum::operator ==(const SarMsgRefNum &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SarMsgRefNum::operator !=(const SarMsgRefNum &other) const {
  return !this->operator ==(other);
}

SarMsgRefNum &SarMsgRefNum::operator =(const SarMsgRefNum &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SarMsgRefNum::setValue(quint16 value) {
  this->value = value;
}

quint16 SarMsgRefNum::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
