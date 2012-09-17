#include <bind_receiver_resp.h>

namespace smpp {

BindReceiverResp::BindReceiverResp() :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::BindReceiverResp),
             CommandStatus(CommandStatus::ESME_ROK),
             SequenceNumber::Min) {
}

BindReceiverResp::BindReceiverResp(const CommandStatus &command_status,
                                   const SequenceNumber &sequence_number,
                                   const SystemId &system_id) :
  TlvsHeader(CommandLength(min_length),
             CommandId(CommandId::BindReceiverResp),
             command_status,
             sequence_number),
  system_id(system_id) {
  Header::updateLength(system_id.length());
}

BindReceiverResp::~BindReceiverResp() {

}

} // namespace smpp
