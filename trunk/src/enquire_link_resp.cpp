#include <enquire_link_resp.h>

namespace smpp {

EnquireLinkResp::EnquireLinkResp() :
    Response(CommandLength(min_length),
              CommandId(CommandId::EnquireLinkResp),
              CommandStatus(CommandStatus::ESME_ROK),
              SequenceNumber::Min)
{
}

/// @brief Constructor that requires values for all the mandatory parameters.
/// @param command_status The command status to use.
/// @param sequence_number The sequence number to use.
EnquireLinkResp::EnquireLinkResp(const CommandStatus &command_status,
                      const SequenceNumber &sequence_number) :
    Response(CommandLength(min_length),
              CommandId(CommandId::EnquireLinkResp),
              command_status,
              sequence_number)
{
}

EnquireLinkResp::~EnquireLinkResp()
{
}

} // namespace smpp
