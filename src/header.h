#ifndef QSMPP_HEADER_H
#define QSMPP_HEADER_H

#include <constants.h>

namespace qsmpp {
namespace pdu {

class QSMPP_EXPORT Header {
public:
  Header(quint32 command_length = 0,
              quint32 command_id = 0,
              quint32 command_status = 0,
              quint32 sequence_number = 0);

  Header(const Header &other);

  bool operator ==(const Header &other) const;

  bool operator !=(const Header &other) const;

  Header &operator =(const Header &other);

  void setCommandLength(quint32 command_length);

  quint32 getCommandLength() const;

  void setCommandId(quint32 command_id);

  quint32 getCommandId() const;

  void setCommandStatus(quint32 command_status);

  quint32 getCommandStatus() const;

  void setSequenceNumber(quint32 sequence_number);

  quint32 getSequenceNumber() const;

protected:
  quint32 command_length;
  quint32 command_id;
  quint32 command_status;
  quint32 sequence_number;
};

} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_HEADER_H
