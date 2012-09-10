#include <dest_node_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

DestNodeId::DestNodeId(const octetString &value):
  TLV(constants::TLVtags::DEST_NODE_ID, value.size()), value(value) {

}

DestNodeId::DestNodeId(const DestNodeId &other):
  TLV(other), value(other.getValue()) {

}

bool DestNodeId::operator ==(const DestNodeId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool DestNodeId::operator !=(const DestNodeId &other) const {
  return !this->operator ==(other);
}

DestNodeId &DestNodeId::operator =(const DestNodeId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void DestNodeId::setValue(const octetString &value) {
  this->value = value;
}

octetString DestNodeId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
