#ifndef QSMPP_OUTBIND_H
#define QSMPP_OUTBIND_H

#include <header.h>

namespace qsmpp {
namespace pdu {

class QSMPP_EXPORT Outbind : public Header {
  CoctetString system_id;
  CoctetString password;
public:
  Outbind(const Header &other_header,
              const CoctetString &system_id = "",
              const CoctetString &password = "");

  Outbind(const Outbind &other);

  bool operator ==(const Outbind &other) const;

  bool operator !=(const Outbind &other) const;

  Outbind &operator =(const Outbind &other);

  void setSystemId(const CoctetString &system_id);

  CoctetString getSystemId() const;

  void setPassword(const CoctetString &password);

  CoctetString getPassword() const;
};

} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_OUTBIND_H
