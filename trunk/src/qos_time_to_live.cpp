#include <qos_time_to_live.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

QosTimeToLive::QosTimeToLive(quint32 value):
  TLV(constants::TLVtags::QOS_TIME_TO_LIVE, 1), value(value) {

}

QosTimeToLive::QosTimeToLive(const QosTimeToLive &other):
  TLV(other), value(other.getValue()) {

}

bool QosTimeToLive::operator ==(const QosTimeToLive &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool QosTimeToLive::operator !=(const QosTimeToLive &other) const {
  return !this->operator ==(other);
}

QosTimeToLive &QosTimeToLive::operator =(const QosTimeToLive &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void QosTimeToLive::setValue(quint32 value) {
  this->value = value;
}

quint32 QosTimeToLive::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
