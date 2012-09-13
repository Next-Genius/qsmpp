#ifndef SMPP_UNBIND_RESP_H
#define SMPP_UNBIND_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class UnbindResp : public Response {
public:

  const static int min_length = 16;

  UnbindResp();

  UnbindResp(const CommandStatus &command_status,
             const SequenceNumber &sequence_number);

  ~UnbindResp();
};

} // namespace smpp

#endif // SMPP_UNBIND_RESP_H
