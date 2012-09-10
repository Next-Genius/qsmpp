#include <set_dpf.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SetDpf::SetDpf(quint8 value):
  TLV(constants::TLVtags::SET_DPF, 1), value(value) {

}

SetDpf::SetDpf(const SetDpf &other): TLV(other), value(other.getValue()) {

}

bool SetDpf::operator ==(const SetDpf &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SetDpf::operator !=(const SetDpf &other) const {
  return !this->operator ==(other);
}

SetDpf &SetDpf::operator =(const SetDpf &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SetDpf::setValue(quint8 value) {
  this->value = value;
}

quint8 SetDpf::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
