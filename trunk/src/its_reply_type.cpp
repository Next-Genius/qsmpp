#include <its_reply_type.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

ItsReplyType::ItsReplyType(quint8 value):
  TLV(constants::TLVtags::ITS_REPLY_TYPE, 1), value(value) {

}

ItsReplyType::ItsReplyType(const ItsReplyType &other):
  TLV(other), value(other.getValue()) {

}

bool ItsReplyType::operator ==(const ItsReplyType &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool ItsReplyType::operator !=(const ItsReplyType &other) const {
  return !this->operator ==(other);
}

ItsReplyType &ItsReplyType::operator =(const ItsReplyType &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void ItsReplyType::setValue(quint8 value) {
  this->value = value;
}

quint8 ItsReplyType::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
