#include <cancel_broadcast_sm_resp.h>

namespace smpp {

CancelBroadcastSmResp::CancelBroadcastSmResp() :
  Header(CommandLength(min_length),
         CommandId(CommandId::CancelBroadcastSmResp),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

CancelBroadcastSmResp::CancelBroadcastSmResp(
  const CommandStatus &command_status,
  const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::CancelBroadcastSmResp),
         command_status,
         sequence_number) {

}

CancelBroadcastSmResp::~CancelBroadcastSmResp() {

}

} // namespace smpp
