#include <receipted_message_id.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

ReceiptedMessageId::ReceiptedMessageId(const CoctetString &value):
  TLV(constants::TLVtags::RECEIPTED_MESSAGE_ID, value.size() + 1),
  value(value) {

}

ReceiptedMessageId::ReceiptedMessageId(const ReceiptedMessageId &other):
  TLV(other), value(other.getValue()) {

}

bool ReceiptedMessageId::operator ==(const ReceiptedMessageId &other) const {
  return (TLV::operator ==(other) && value == other.getValue());
}

bool ReceiptedMessageId::operator !=(const ReceiptedMessageId &other) const {
  return !this->operator ==(other);
}

ReceiptedMessageId &ReceiptedMessageId::operator =(
  const ReceiptedMessageId &other) {
  if(*this == other)
    return *this;
  TLV::operator =(other);
  value = other.getValue();
  return *this;
}

void ReceiptedMessageId::setValue(const CoctetString &value) {
  this->value = value;
}

CoctetString ReceiptedMessageId::getValue() const {
  return value;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
