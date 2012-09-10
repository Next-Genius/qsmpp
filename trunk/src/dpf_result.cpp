#include <dpf_result.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DpfResult::DpfResult(quint8 value):
  TLV(constants::TLVtags::DPF_RESULT, 1), value(value) {

}

DpfResult::DpfResult(const DpfResult &other):
  TLV(other), value(other.getValue()) {

}

bool DpfResult::operator ==(const DpfResult &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DpfResult::operator !=(const DpfResult &other) const {
  return !this->operator ==(other);
}

DpfResult &DpfResult::operator =(const DpfResult &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DpfResult::setValue(quint8 value) {
  this->value = value;
}

quint8 DpfResult::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
