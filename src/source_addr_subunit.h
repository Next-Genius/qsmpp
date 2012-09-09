#ifndef QSMPP_SOURCE_ADDR_SUBUNIT_H
#define QSMPP_SOURCE_ADDR_SUBUNIT_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceAddrSubunit : public TLV {
  quint8 value;
public:
  SourceAddrSubunit(quint8 value = 0);

  SourceAddrSubunit(const SourceAddrSubunit &other);

  bool operator ==(const SourceAddrSubunit &other) const;

  bool operator !=(const SourceAddrSubunit &other) const;

  SourceAddrSubunit &operator =(const SourceAddrSubunit &other);

  void setValue(quint8 value);

  quint8 getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_ADDR_SUBUNIT_H
