#ifndef QSMPP_HEADER_H
#define QSMPP_HEADER_H

namespace qsmpp {
namespace pdu {

class QSMPP_EXPORT Header {
public:
  Header(const quint32 nCommandLength = 0,
              const quint32 nCommandId = 0,
              const quint32 nCommandStatus = 0,
              const quint32 nSequenceNumber = 0);

  Header(const Header &);

  bool operator ==(const Header &) const;

  bool operator !=(const Header &) const;

  Header &operator =(const Header &);

  void setCommandLength(const quint32);

  const quint32 getCommandLength() const;

  void setCommandId(const quint32);

  const quint32 getCommandId() const;

  void setCommandStatus(const quint32);

  const quint32 getCommandStatus() const;

  void setSequenceNumber(const quint32);

  const quint32 getSequenceNumber() const;

  protected:
  quint32 _CommandLength;
  quint32 _CommandId;
  quint32 _CommandStatus;
  quint32 _SequenceNumber;
};

}
}

#endif // QSMPP_HEADER_H
