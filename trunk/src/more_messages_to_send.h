#ifndef QSMPP_MORE_MESSAGES_TO_SEND_H
#define QSMPP_MORE_MESSAGES_TO_SEND_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MoreMessagesToSend : public TLV {
  quint8 value;
public:
  MoreMessagesToSend(quint8 value = 0);

  MoreMessagesToSend(const MoreMessagesToSend &other);

  bool operator ==(const MoreMessagesToSend &other) const;

  bool operator !=(const MoreMessagesToSend &other) const;

  MoreMessagesToSend &operator =(const MoreMessagesToSend &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MORE_MESSAGES_TO_SEND_H
