#ifndef SMPP_BIND_TRANSCEIVER_RESP_H
#define SMPP_BIND_TRANSCEIVER_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class BindTransceiverResp : public Response {
  SystemId system_id;
public:
  const static int min_length = 17;

  BindTransceiverResp();

  BindTransceiverResp(const CommandStatus &command_status,
                      const SequenceNumber &sequence_number,
                      const SystemId &system_id);

  ~BindTransceiverResp();

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

#endif // SMPP_BIND_TRANSCEIVER_RESP_H
