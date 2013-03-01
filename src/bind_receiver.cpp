#include <bind_receiver.h>

namespace smpp {

BindReceiver::BindReceiver() :
  Header(CommandLength(min_length),
         CommandId(CommandId::BindReceiver),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

BindReceiver::BindReceiver(const SequenceNumber &sequence_number,
                           const SystemId &system_id,
                           const Password &password,
                           const SystemType &system_type,
                           const InterfaceVersion &interface_version,
                           const Ton &addr_ton,
                           const Npi &addr_npi,
                           const AddressRange &address_range) :
    Header(CommandLength(min_length),
           CommandId(CommandId::BindReceiver),
           CommandStatus(CommandStatus::ESME_ROK),
           sequence_number),
    system_id(system_id),
    password(password),
    system_type(system_type),
    interface_version(interface_version),
    addr_ton(addr_ton),
    addr_npi(addr_npi),
    address_range(address_range) {
  Header::updateLength(system_id.length() +
                       password.length() +
                       system_type.length() +
                       address_range.length());
}

BindReceiver::~BindReceiver() {

}

void BindReceiver::setSystemId(const SystemId &p) {
  int diff = p.length() - system_id.length();
  system_id = p;
  Header::updateLength(diff);
}

void BindReceiver::setSystemId(const char *p) {
  int diff = strlen(p) - system_id.length();
  system_id = p;
  Header::updateLength(diff);
}

void BindReceiver::setPassword(const Password &p) {
  int diff = p.length() - password.length();
  password = p;
  Header::updateLength(diff);
}

void BindReceiver::setPassword(const char *p) {
  int diff = strlen(p) - password.length();
  password = p;
  Header::updateLength(diff);
}

void BindReceiver::setSystemType(const SystemType &p) {
  int diff = p.length() - system_type.length();
  system_type = p;
  Header::updateLength(diff);
}

void BindReceiver::setSystemType(const char *p) {
  int diff = strlen(p) - system_type.length();
  system_type = p;
  Header::updateLength(diff);
}

void BindReceiver::setInterfaceVersion(const int &p) { interface_version = p; }

void BindReceiver::setAddrTon(const int &p) { addr_ton = p; }

void BindReceiver::setAddrNpi(const int &p) { addr_npi = p; }

void BindReceiver::setAddressRange(const AddressRange &p) {
  int diff = p.length() - address_range.length();
  address_range = p;
  Header::updateLength(diff);
}

void BindReceiver::setAddressRange(const char *p) {
  int diff = strlen(p) - address_range.length();
  address_range = p;
  Header::updateLength(diff);
}

const SystemId &BindReceiver::getSystemId() const { return system_id; }

const Password &BindReceiver::getPassword() const { return password; }

const SystemType &BindReceiver::getSystemType() const { return system_type; }

const InterfaceVersion &BindReceiver::getInterfaceVersion() const {
  return interface_version;
}

const Ton &BindReceiver::getAddrTon() const { return addr_ton; }

const Npi &BindReceiver::getAddrNpi() const { return addr_npi; }

const AddressRange &BindReceiver::getAddressRange() const { return address_range; }

} // namespace smpp
