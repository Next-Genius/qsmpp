#ifndef QSMPP_MS_AVAILABILITY_STATUS_H
#define QSMPP_MS_AVAILABILITY_STATUS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MsAvailabilityStatus : public TLV {
  quint8 value;
public:
  MsAvailabilityStatus(quint8 value = 0);

  MsAvailabilityStatus(const MsAvailabilityStatus &other);

  bool operator ==(const MsAvailabilityStatus &other) const;

  bool operator !=(const MsAvailabilityStatus &other) const;

  MsAvailabilityStatus &operator =(const MsAvailabilityStatus &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MS_AVAILABILITY_STATUS_H
