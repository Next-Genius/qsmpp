#include <display_time.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DisplayTime::DisplayTime(quint8 value):
  TLV(constants::TLVtags::DISPLAY_TIME, 1), value(value) {

}

DisplayTime::DisplayTime(const DisplayTime &other):
  TLV(other), value(other.getValue()) {

}

bool DisplayTime::operator ==(const DisplayTime &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DisplayTime::operator !=(const DisplayTime &other) const {
  return !this->operator ==(other);
}

DisplayTime &DisplayTime::operator =(const DisplayTime &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DisplayTime::setValue(quint8 value) {
  this->value = value;
}

quint8 DisplayTime::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
