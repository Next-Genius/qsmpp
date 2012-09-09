#ifndef QSMPP_RECEIPTED_MESSAGE_ID_H
#define QSMPP_RECEIPTED_MESSAGE_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT ReceiptedMessageId : public TLV {
  CoctetString value;
public:
  ReceiptedMessageId(const CoctetString &value = "");

  ReceiptedMessageId(const ReceiptedMessageId &other);

  bool operator ==(const ReceiptedMessageId &other) const;

  bool operator !=(const ReceiptedMessageId &other) const;

  ReceiptedMessageId &operator =(const ReceiptedMessageId &other);

  void setValue(const CoctetString &value);

  CoctetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_RECEIPTED_MESSAGE_ID_H
