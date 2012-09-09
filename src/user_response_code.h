#ifndef QSMPP_USER_RESPONSE_CODE_H
#define QSMPP_USER_RESPONSE_CODE_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT UserResponseCode : public TLV {
  quint8 value;
public:
  UserResponseCode(quint8 value = 0);

  UserResponseCode(const UserResponseCode &other);

  bool operator ==(const UserResponseCode &other) const;

  bool operator !=(const UserResponseCode &other) const;

  UserResponseCode &operator =(const UserResponseCode &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_USER_RESPONSE_CODE_H
