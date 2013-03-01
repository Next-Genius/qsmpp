#ifndef SMPP_BIND_RECEIVER_H
#define SMPP_BIND_RECEIVER_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class BindReceiver : public Header {
  SystemId system_id;
  Password password;
  SystemType system_type;
  InterfaceVersion interface_version;
  Ton addr_ton;
  Npi addr_npi;
  AddressRange address_range;

public:
  const static int min_length = 23;

  BindReceiver();

  BindReceiver(const SequenceNumber &sequence_number,
               const SystemId &system_id,
               const Password &password,
               const SystemType &system_type,
               const InterfaceVersion &interface_version,
               const Ton &addr_ton,
               const Npi &addr_npi,
               const AddressRange &address_range);

  ~BindReceiver();

  //
  // Mutating
  //

  void setSystemId(const SystemId &p);

  void setSystemId(const char *p);

  void setPassword(const Password &p);

  void setPassword(const char *p);

  void setSystemType(const SystemType &p);

  void setSystemType(const char *p);

  void setInterfaceVersion(const int &p);

  void setAddrTon(const int &p);

  void setAddrNpi(const int &p);

  void setAddressRange(const AddressRange &p);

  void setAddressRange(const char *p);

  //
  // Accessing
  //

  const SystemId &getSystemId() const;

  const Password &getPassword() const;

  const SystemType &getSystemType() const;

  const InterfaceVersion &getInterfaceVersion() const;

  const Ton &getAddrTon() const;

  const Npi &getAddrNpi() const;

  const AddressRange &getAddressRange() const;
};

} // namespace smpp

#endif // SMPP_BIND_RECEIVER_H
