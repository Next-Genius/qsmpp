#ifndef SMPP_BIND_RESP_H
#define SMPP_BIND_RESP_H

#include <header.h>
#include <sc_interface_version.h>

namespace smpp {
namespace pdu {

class SMPP_EXPORT BindResp : public Header {
  CoctetString system_id;
  tlv::ScInterfaceVersion *sc_interface_version;
public:
  BindResp(const Header &other_header = Header(),
           const CoctetString &system_id = "",
           const tlv::ScInterfaceVersion *sc_interface_version = 0);

  BindResp(const BindResp &other);

  ~BindResp();

  bool operator ==(const BindResp &other) const;

  bool operator !=(const BindResp &other) const;

  BindResp &operator =(const BindResp &other);

  void setSystemId(const CoctetString &system_id);

  CoctetString getSystemId() const;

  void setScInterfaceVersion(
    const tlv::ScInterfaceVersion *sc_interface_version);

  tlv::ScInterfaceVersion *getScInterfaceVersion() const;
};

} // namespace pdu
} // namespace smpp

#endif // SMPP_BIND_RESP_H
