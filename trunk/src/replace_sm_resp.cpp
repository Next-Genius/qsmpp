#include <replace_sm_resp.h>

namespace smpp {

ReplaceSmResp::ReplaceSmResp() :
  Header(CommandLength(min_length),
         CommandId(CommandId::ReplaceSmResp),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

ReplaceSmResp::ReplaceSmResp(const CommandStatus &command_status,
                             const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::ReplaceSmResp),
         command_status,
         sequence_number) {

}

ReplaceSmResp::~ReplaceSmResp() {

}

} // namespace smpp
