#ifndef SMPP_SUBMIT_MULTI_RESP_H
#define SMPP_SUBMIT_MULTI_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class SubmitMultiResp : public Response {
  MessageId message_id;
  UnsuccessSmeColl unsuccess_sme;
public:
  const static int min_length = 18;

  SubmitMultiResp();

  SubmitMultiResp(
          const CommandStatus &command_status,
          const SequenceNumber &sequence_number,
          const MessageId &message_id);

  ~SubmitMultiResp();

  //
  // Mutating
  //

  void setMessageId(const MessageId &p) {
    int diff = p.length() - message_id.length();
    message_id = p;
    Header::updateLength(diff);
  }

  void setMessageId(const char *p) {
    int diff = strlen(p) - message_id.length();
    message_id = p;
    Header::updateLength(diff);
  }

  void setUnsuccessSme(const UnsuccessSme &p) {
    Header::updateLength(unsuccess_sme.add(p));
  }

  //
  // Accessing
  //

  const MessageId &getMessageId() const { return message_id; }
};

} // namespace smpp

#endif // SMPP_SUBMIT_MULTI_RESP_H
