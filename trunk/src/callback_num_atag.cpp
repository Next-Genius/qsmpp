#include <callback_num_atag.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

CallbackNumAtag::CallbackNumAtag(const octetString &value):
  TLV(constants::TLVtags::CALLBACK_NUM_ATAG,value.size()), value(value) {

}

CallbackNumAtag::CallbackNumAtag(const CallbackNumAtag &other):
  TLV(other), value(other.getValue()) {

}

bool CallbackNumAtag::operator ==(const CallbackNumAtag &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool CallbackNumAtag::operator !=(const CallbackNumAtag &other) const {
  return !this->operator ==(other);
}

CallbackNumAtag &CallbackNumAtag::operator =(const CallbackNumAtag &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void CallbackNumAtag::setValue(const octetString &value) {
  this->value = value;
}

octetString CallbackNumAtag::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

