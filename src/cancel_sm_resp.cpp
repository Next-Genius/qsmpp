#include <cancel_sm_resp.h>

namespace smpp {

CancelSmResp::CancelSmResp() :
  Header(CommandLength(min_length),
         CommandId(CommandId::CancelSmResp),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

CancelSmResp::CancelSmResp(const CommandStatus &command_status,
                           const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::CancelSmResp),
         command_status,
         sequence_number) {

}

CancelSmResp::~CancelSmResp() {

}

} // namespace smpp
