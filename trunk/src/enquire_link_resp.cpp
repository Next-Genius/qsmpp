#include <enquire_link_resp.h>

namespace smpp {

EnquireLinkResp::EnquireLinkResp() :
  Header(CommandLength(min_length),
         CommandId(CommandId::EnquireLinkResp),
         CommandStatus(CommandStatus::ESME_ROK),
         SequenceNumber::Min) {

}

EnquireLinkResp::EnquireLinkResp(const CommandStatus &command_status,
                                 const SequenceNumber &sequence_number) :
  Header(CommandLength(min_length),
         CommandId(CommandId::EnquireLinkResp),
         command_status,
         sequence_number) {

}

EnquireLinkResp::~EnquireLinkResp() {

}

} // namespace smpp
