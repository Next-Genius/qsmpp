#include <source_node_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

SourceNodeId::SourceNodeId(const octetString &value):
  TLV(constants::TLVtags::SOURCE_NODE_ID, value.size()), value(value) {

}

SourceNodeId::SourceNodeId(const SourceNodeId &other):
  TLV(other), value(other.getValue()) {

}

bool SourceNodeId::operator ==(const SourceNodeId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool SourceNodeId::operator !=(const SourceNodeId &other) const {
  return !this->operator ==(other);
}

SourceNodeId &SourceNodeId::operator =(const SourceNodeId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void SourceNodeId::setValue(const octetString &value) {
  this->value = value;
}

octetString SourceNodeId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
