#ifndef QSMPP_DPF_RESULT_H
#define QSMPP_DPF_RESULT_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT DpfResult : public TLV {
  quint8 value;
public:
  DpfResult(quint8 value = 0);

  DpfResult(const DpfResult &other);

  bool operator ==(const DpfResult &other) const;

  bool operator !=(const DpfResult &other) const;

  DpfResult &operator =(const DpfResult &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_DPF_RESULT_H
