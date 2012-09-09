#ifndef QSMPP_BILLING_IDENTIFICATION_H
#define QSMPP_BILLING_IDENTIFICATION_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BillingIdentification : public TLV {
  octetString value;
public:
  BillingIdentification(const octetString &value = octetString());

  BillingIdentification(const BillingIdentification &other);

  bool operator ==(const BillingIdentification &other) const;

  bool operator !=(const BillingIdentification &other) const;

  BillingIdentification &operator =(const BillingIdentification &other);

  void setValue(const octetString &other);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BILLING_IDENTIFICATION_H
