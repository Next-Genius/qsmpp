#ifndef BIND_TRANSCEIVER_H
#define BIND_TRANSCEIVER_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class BindTransceiver : public Request {
  SystemId system_id;
  Password password;
  SystemType system_type;
  InterfaceVersion interface_version;
  Ton addr_ton;
  Npi addr_npi;
  AddressRange address_range;

public:
  const static int min_length = 23;

  BindTransceiver();

  BindTransceiver(const SequenceNumber &sequence_number,
                  const SystemId &system_id,
                  const Password &password,
                  const SystemType &system_type,
                  const InterfaceVersion &interface_version,
                  const Ton &addr_ton,
                  const Npi &addr_npi,
                  const AddressRange &address_range);

  ~BindTransceiver();

  //
  // Mutating
  //

  void setSystemId(const SystemId &p) {
    int diff = p.length() - system_id.length();
    system_id = p;
    Header::updateLength(diff);
  }

  void setSystemId(const char *p) {
    int diff = strlen(p) - system_id.length();
    system_id = p;
    Header::updateLength(diff);
  }

  void setPassword(const Password &p) {
    int diff = p.length() - password.length();
    password = p;
    Header::updateLength(diff);
  }

  void setPassword(const char *p) {
    int diff = strlen(p) - password.length();
    password = p;
    Header::updateLength(diff);
  }

  void setSystemType(const SystemType &p) {
    int diff = p.length() - system_type.length();
    system_type = p;
    Header::updateLength(diff);
  }

  void setSystemType(const char *p) {
    int diff = strlen(p) - system_type.length();
    system_type = p;
    Header::updateLength(diff);
  }

  void setInterfaceVersion(const int &p) { interface_version = p; }

  void setAddrTon(const int &p) { addr_ton = p; }

  void setAddrNpi(const int &p) { addr_npi = p; }

  void setAddressRange(const AddressRange &p) {
    int diff = p.length() - address_range.length();
    address_range = p;
    Header::updateLength(diff);
  }

  void setAddressRange(const char *p) {
    int diff = strlen(p) - address_range.length();
    address_range = p;
    Header::updateLength(diff);
  }

  //
  // Accessing
  //

  const SystemId &getSystemId() const { return system_id; }

  const Password &getPassword() const { return password; }

  const SystemType &getSystemType() const { return system_type; }

  const InterfaceVersion &getInterfaceVersion() const {
    return interface_version;
  }

  const Ton &getAddrTon() const { return addr_ton; }

  const Npi &getAddrNpi() const { return addr_npi; }

  const AddressRange &getAddressRange() const { return address_range; }
};

} // namespace smpp

#endif // BIND_TRANSCEIVER_H
