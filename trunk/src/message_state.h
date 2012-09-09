#ifndef QSMPP_MESSAGE_STATE_H
#define QSMPP_MESSAGE_STATE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MessageState : public TLV {
  quint8 value;
public:
  MessageState(quint8 value = 0);

  MessageState(const MessageState &other);

  bool operator ==(const MessageState &other) const;

  bool operator !=(const MessageState &other) const;

  MessageState &operator =(const MessageState &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MESSAGE_STATE_H
