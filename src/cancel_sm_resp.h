#ifndef SMPP_CANCEL_SM_RESP_H
#define SMPP_CANCEL_SM_RESP_H

#include <header.h>

namespace smpp {

class CancelSmResp : public Response {
public:
  const static int min_length = 16;

  CancelSmResp();

  CancelSmResp(const CommandStatus &command_status,
               const SequenceNumber &sequence_number);

  ~CancelSmResp();

};

} // namespace smpp

#endif // SMPP_CANCEL_SM_RESP_H
