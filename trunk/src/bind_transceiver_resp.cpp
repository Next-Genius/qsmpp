#include <bind_transceiver_resp.h>

namespace smpp {

BindTransceiverResp::BindTransceiverResp() :
  Response(CommandLength(MinLength),
           CommandId(CommandId::BindTransceiverResp),
           CommandStatus(CommandStatus::ESME_ROK),
           SequenceNumber::Min) {
}

BindTransceiverResp::BindTransceiverResp(const CommandStatus &command_status,
                                         const SequenceNumber &sequence_number,
                                         const SystemId &system_id) :
  Response(CommandLength(MinLength),
           CommandId(CommandId::BindTransceiverResp),
           command_status,
           sequence_number),
  system_id(system_id) {
  Header::updateLength(system_id.length());
}

BindTransceiverResp::~BindTransceiverResp() {

}

} // namespace smpp
