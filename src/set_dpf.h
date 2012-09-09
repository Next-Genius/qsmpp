#ifndef QSMPP_SET_DPF_H
#define QSMPP_SET_DPF_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SetDpf : public TLV {
  quint8 value;
public:
  SetDpf(quint8 value = 0);

  SetDpf(const SetDpf &other);

  bool operator ==(const SetDpf &other) const;

  bool operator !=(const SetDpf &other) const;

  SetDpf &operator =(const SetDpf &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SET_DPF_H
