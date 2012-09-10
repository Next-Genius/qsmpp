#include <broadcast_rep_num.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

BroadcastRepNum::BroadcastRepNum(quint16 value):
  TLV(constants::TLVtags::BROADCAST_REP_NUM, 2), value(value) {

}

BroadcastRepNum::BroadcastRepNum(const BroadcastRepNum &other):
  TLV(other), value(other.getValue()) {

}

bool BroadcastRepNum::operator ==(const BroadcastRepNum &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool BroadcastRepNum::operator !=(const BroadcastRepNum &other) const {
  return !this->operator ==(other);
}

BroadcastRepNum &BroadcastRepNum::operator =(const BroadcastRepNum &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void BroadcastRepNum::setValue(quint16 value) {
  this->value = value;
}

quint16 BroadcastRepNum::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
