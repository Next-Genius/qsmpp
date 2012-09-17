#include <unbind_resp.h>

namespace smpp {

UnbindResp::UnbindResp() :
  Header(CommandLength(min_length),
         CommandId(CommandId::UnbindResp),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

UnbindResp::UnbindResp(const CommandStatus &command_status,
                       const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::UnbindResp),
         command_status,
         sequence_number) {

}

UnbindResp::~UnbindResp() {
}

} // namespace smpp
