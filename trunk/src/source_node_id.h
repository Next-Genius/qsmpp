#ifndef QSMPP_SOURCE_NODE_ID_H
#define QSMPP_SOURCE_NODE_ID_H

#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT SourceNodeId : public TLV {
  octetString value;
public:
  SourceNodeId(const octetString &value = octetString());

  SourceNodeId(const SourceNodeId &other);

  bool operator ==(const SourceNodeId &other) const;

  bool operator !=(const SourceNodeId &other) const;

  SourceNodeId &operator =(const SourceNodeId &other);

  void setValue(const octetString &value);

  octetString getValue() const;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_SOURCE_NODE_ID_H
