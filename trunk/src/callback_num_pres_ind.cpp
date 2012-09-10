#include <callback_num_pres_ind.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

CallbackNumPresInd::CallbackNumPresInd(quint8 value):
  TLV(constants::TLVtags::CALLBACK_NUM_PRES_IND, 1), value(value) {

}

CallbackNumPresInd::CallbackNumPresInd(const CallbackNumPresInd &other):
  TLV(other), value(other.getValue()) {

}

bool CallbackNumPresInd::operator ==(const CallbackNumPresInd &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool CallbackNumPresInd::operator !=(const CallbackNumPresInd &other) const {
  return !this->operator ==(other);
}

CallbackNumPresInd &CallbackNumPresInd::operator =(
  const CallbackNumPresInd &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void CallbackNumPresInd::setValue(quint8 value) {
  this->value = value;
}

quint8 CallbackNumPresInd::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

