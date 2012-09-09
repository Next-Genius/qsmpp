#ifndef QSMPP_BROADCAST_MESSAGE_CLASS_H
#define QSMPP_BROADCAST_MESSAGE_CLASS_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT BroadcastMessageClass : public TLV {
  quint8 value;
public:
  BroadcastMessageClass(quint8 value = 0);

  BroadcastMessageClass(const BroadcastMessageClass &other);

  bool operator ==(const BroadcastMessageClass &other) const;

  bool operator !=(const BroadcastMessageClass &other) const;

  BroadcastMessageClass &operator =(const BroadcastMessageClass &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_BROADCAST_MESSAGE_CLASS_H
