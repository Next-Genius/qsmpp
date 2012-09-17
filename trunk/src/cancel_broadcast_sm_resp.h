#ifndef SMPP_CANCEL_BROADCAST_SM_RESP_H
#define SMPP_CANCEL_BROADCAST_SM_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class CancelBroadcastSmResp : public Header {
public:
  const static int min_length = 16;

  CancelBroadcastSmResp();

  CancelBroadcastSmResp(const CommandStatus &command_status,
                        const SequenceNumber &sequence_number);

  ~CancelBroadcastSmResp();
};

} // namespace smpp

#endif // SMPP_CANCEL_BROADCAST_SM_RESP_H
