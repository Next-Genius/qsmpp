#ifndef QSMPP_ALERT_ON_MESSAGE_DELIVERY_H
#define QSMPP_ALERT_ON_MESSAGE_DELIVERY_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT AlertOnMessageDelivery : public TLV {
  octetString value;
public:
  AlertOnMessageDelivery(const octetString &value = octetString());

  AlertOnMessageDelivery(const AlertOnMessageDelivery &other);

  bool operator ==(const AlertOnMessageDelivery &other) const;

  bool operator !=(const AlertOnMessageDelivery &other) const;

  AlertOnMessageDelivery &operator =(const AlertOnMessageDelivery &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_ALERT_ON_MESSAGE_DELIVERY_H
