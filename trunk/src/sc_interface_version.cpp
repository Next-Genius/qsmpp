#include <sc_interface_version.h>

namespace qsmpp {
namespace pdu {

ScInterfaceVersion::ScInterfaceVersion(quint8 value):
  TLV(constants::TLVtags::SC_INTERFACE_VERSION, 1),
  value(value) {

}

ScInterfaceVersion::ScInterfaceVersion(const ScInterfaceVersion &other):
  TLV(other), value(other.getValue()) {

}

bool ScInterfaceVersion::operator ==(const ScInterfaceVersion &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool ScInterfaceVersion::operator !=(const ScInterfaceVersion &other) const {
  return !this->operator ==(other);
}

ScInterfaceVersion &ScInterfaceVersion::operator =(const ScInterfaceVersion &other) {
  if(*this == other)
      return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void ScInterfaceVersion::setValue(quint8 value) {
  this->value = value;
}

quint8 ScInterfaceVersion::getValue() const {
  return value;
}

} // namespace pdu
} // namespace qsmpp
