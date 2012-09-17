#ifndef BIND_TRANSMITTER_RESP_H
#define BIND_TRANSMITTER_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class BindTransmitterResp : public TlvsHeader {
  SystemId system_id;
public:
  const static int min_length = 17;

  BindTransmitterResp();

  BindTransmitterResp(const CommandStatus &command_status,
                      const SequenceNumber &sequence_number,
                      const SystemId &system_id);

  ~BindTransmitterResp();

  //
  // Mutating
  //

  void setSystemId(const SystemId &p) {
    int diff = p.length() - system_id.length();
    system_id = p;
    Header::updateLength(diff);
  }

  void setSystemId(const char *p) {
    int diff = strlen(p) - system_id.length();
    system_id = p;
    Header::updateLength(diff);
  }

  //
  // Accessing
  //
  const SystemId &getSystemId() const { return system_id; }
};

} // namespace smpp

#endif // BIND_TRANSMITTER_RESP_H
