#ifndef SMPP_HEADER_H
#define SMPP_HEADER_H

#include <command_id.h>
#include <command_length.h>
#include <command_status.h>
#include <sequence_number.h>

namespace smpp {

class Header {
  CommandLength command_length;
  CommandId command_id;
  CommandStatus command_status;
  SequenceNumber sequence_number;
  Header();

public:
  virtual ~Header();

  /* Accessing */

  smpp::uint32 command_length() const { return command_length; }

  smpp::uint32 command_id() const { return command_id; }

  smpp::uint32 sequence_number() const { return sequence_number; }

  /* Mutating */

  void setSequenceNumber(const smpp::uint32 &p, bool allow_0 = false) {
    sequence_number = SequenceNumber(p, allow_0);
  }

  virtual smpp::uint32 command_status() const = 0;

  virtual void command_status(const smpp::uint32 &p) = 0;

protected:
  Header(const CommandLength &command_length,
         const CommandId &command_id,
         const CommandStatus &command_status,
         const SequenceNumber &sequence_number);


  void setCommandLength(const smpp::uint32 &p) { command_length = p; }

  void update_length(const int &p) { command_length += p; }

  const CommandStatus &getCommandStatus(void) const {
    return command_status;
  }

  void setCommandStatus(const CommandStatus &p) {
    command_status = p;
  }
};

} // namespace smpp

#endif // SMPP_HEADER_H
