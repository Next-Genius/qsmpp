#include <sms_signal.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SmsSignal::SmsSignal(quint16 value):
  TLV(constants::TLVtags::SMS_SIGNAL, 2), value(value) {

}

SmsSignal::SmsSignal(const SmsSignal &other):
  TLV(other), value(other.getValue()) {

}

bool SmsSignal::operator ==(const SmsSignal &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SmsSignal::operator !=(const SmsSignal &other) const {
  return !this->operator ==(other);
}

SmsSignal &SmsSignal::operator =(const SmsSignal &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SmsSignal::setValue(quint16 value) {
  this->value = value;
}

quint16 SmsSignal::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
