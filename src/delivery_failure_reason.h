#ifndef QSMPP_DELIVERY_FAILURE_REASON_H
#define QSMPP_DELIVERY_FAILURE_REASON_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DeliveryFailureReason : public TLV {
  quint8 value;
public:
  DeliveryFailureReason(quint8 value = 0);

  DeliveryFailureReason(const DeliveryFailureReason &other);

  bool operator ==(const DeliveryFailureReason &other) const;

  bool operator !=(const DeliveryFailureReason &other) const;

  DeliveryFailureReason &operator =(const DeliveryFailureReason &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DELIVERY_FAILURE_REASON_H
