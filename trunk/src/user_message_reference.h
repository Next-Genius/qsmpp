#ifndef QSMPP_USER_MESSAGE_REFERENCE_H
#define QSMPP_USER_MESSAGE_REFERENCE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT UserMessageReference : public TLV {
  quint16 value;
public:
  UserMessageReference(quint16 value = 0);

  UserMessageReference(const UserMessageReference &other);

  bool operator ==(const UserMessageReference &other) const;

  bool operator !=(const UserMessageReference &other) const;

  UserMessageReference &operator =(const UserMessageReference &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_USER_MESSAGE_REFERENCE_H
