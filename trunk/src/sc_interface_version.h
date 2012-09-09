#ifndef QSMPP_SC_INTERFACE_VERSION_H
#define QSMPP_SC_INTERFACE_VERSION_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT ScInterfaceVersion : public TLV {
  quint8 value;
public:
  ScInterfaceVersion(quint8 value = constants::InterfaceVersion::SMPP_VER_5_0);

  ScInterfaceVersion(const ScInterfaceVersion &other);

  bool operator ==(const ScInterfaceVersion &other) const;

  bool operator !=(const ScInterfaceVersion &other) const;

  ScInterfaceVersion &operator =(const ScInterfaceVersion &other);

  void setValue(quint8);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SC_INTERFACE_VERSION_H
