#ifndef SMPP_REPLACE_SM_RESP_H
#define SMPP_REPLACE_SM_RESP_H

#include <header.h>

namespace smpp {

class ReplaceSmResp : public Response {
public:
  const static int min_length = 16;

  ReplaceSmResp();

  ReplaceSmResp(const CommandStatus &command_status,
                const SequenceNumber &sequence_number);

  ~ReplaceSmResp();
};

} // namespace smpp

#endif // SMPP_REPLACE_SM_RESP_H
