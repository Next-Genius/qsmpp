#include <bind_resp.h>

namespace qsmpp {
namespace pdu {

BindResp::BindResp(const Header &other_header,
                   const CoctetString &system_id,
                   const tlv::ScInterfaceVersion *sc_interface_version):
  Header(other_header),
  system_id(system_id),
  sc_interface_version(0) {
  if (sc_interface_version) {
    this->sc_interface_version =
      new tlv::ScInterfaceVersion(*sc_interface_version);
  }
}

BindResp::BindResp(const BindResp &other):
  Header(other),
  system_id(other.getSystemId()),
  sc_interface_version(0) {
  const tlv::ScInterfaceVersion *other_sc_interface_version(
    other.getScInterfaceVersion());
  if (other_sc_interface_version) {
    sc_interface_version =
      new tlv::ScInterfaceVersion(*other_sc_interface_version);
  }
}

BindResp::~BindResp() {
  if (sc_interface_version) {
    delete sc_interface_version;
    sc_interface_version = 0;
  }
}

bool BindResp::operator ==(const BindResp &other) const {
  return (Header::operator ==(other) &&
          system_id == other.getSystemId() &&
          *sc_interface_version == *other.getScInterfaceVersion());
}

bool BindResp::operator !=(const BindResp &other) const {
  return !this->operator ==(other);
}

BindResp &BindResp::operator =(const BindResp &other) {
  if (*this == other)
    return *this;
  Header::operator =(other);
  system_id = other.getSystemId();
  if(this->sc_interface_version) {
    delete this->sc_interface_version;
    this->sc_interface_version = 0;
  }
  if (sc_interface_version) {
    this->sc_interface_version =
      new tlv::ScInterfaceVersion(*sc_interface_version);
  }
  return *this;
}

void BindResp::setSystemId(const CoctetString &system_id){
  this->system_id = system_id;
}

CoctetString BindResp::getSystemId() const {
  return system_id;
}

void BindResp::setScInterfaceVersion(
  const tlv::ScInterfaceVersion *sc_interface_version) {
  if (this->sc_interface_version) {
    delete this->sc_interface_version;
    this->sc_interface_version = 0;
  }
  if (sc_interface_version) {
    this->sc_interface_version =
      new tlv::ScInterfaceVersion(*sc_interface_version);
  }
}

const tlv::ScInterfaceVersion *BindResp::getScInterfaceVersion() const {
  return sc_interface_version;
}

} // namespace pdu
} // namespace qsmpp
