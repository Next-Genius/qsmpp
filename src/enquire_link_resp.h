#ifndef SMPP_ENQUIRE_LINK_RESP_H
#define SMPP_ENQUIRE_LINK_RESP_H

#include <header.h>

namespace smpp {

class EnquireLinkResp : public Header {
public:
  const static int min_length = 16;

  EnquireLinkResp();

  EnquireLinkResp(const CommandStatus &command_status,
                  const SequenceNumber &sequence_number);

  ~EnquireLinkResp();
};

} // namespace smpp

#endif // SMPP_ENQUIRE_LINK_RESP_H
