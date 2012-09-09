#ifndef QSMPP_ITS_SESSION_INFO_H
#define QSMPP_ITS_SESSION_INFO_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class ItsSessionInfo : public TLV {
  quint16 value;
public:
  ItsSessionInfo(const quint16 value = 0);

  ItsSessionInfo(const ItsSessionInfo &other);

  bool operator ==(const ItsSessionInfo &other) const;

  bool operator !=(const ItsSessionInfo &other) const;

  ItsSessionInfo &operator =(const ItsSessionInfo &other);

  void setValue(quint16 value);

  quint16 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_ITS_SESSION_INFO_H
