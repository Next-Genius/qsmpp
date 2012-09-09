#ifndef QSMPP_MS_MSG_WAIT_FACILITIES_H
#define QSMPP_MS_MSG_WAIT_FACILITIES_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MsMsgWaitFacilities : public TLV {
  quint8 value;
public:
  MsMsgWaitFacilities(const quint8 value = 0);

  MsMsgWaitFacilities(const MsMsgWaitFacilities &other);

  bool operator ==(const MsMsgWaitFacilities &other) const;

  bool operator !=(const MsMsgWaitFacilities &other) const;

  MsMsgWaitFacilities &operator =(const MsMsgWaitFacilities &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MS_MSG_WAIT_FACILITIES_H
