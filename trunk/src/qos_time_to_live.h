#ifndef QSMPP_QOS_TIME_TO_LIVE_H
#define QSMPP_QOS_TIME_TO_LIVE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT QosTimeToLive : public TLV {
  quint32 value;
public:
  QosTimeToLive(const quint32 value = 0);

  QosTimeToLive(const QosTimeToLive &other);

  bool operator ==(const QosTimeToLive &other) const;

  bool operator !=(const QosTimeToLive &other) const;

  QosTimeToLive &operator =(const QosTimeToLive &other);

  void setValue(quint32 value);

  quint32 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_QOS_TIME_TO_LIVE_H
