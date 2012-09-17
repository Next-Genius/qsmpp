#ifndef SMPP_QUERY_BROADCAST_SM_RESP_H
#define SMPP_QUERY_BROADCAST_SM_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class QueryBroadcastSmResp : public TlvsHeader {
  MessageId message_id;
  MessageState message_state;
public:
  const static int min_length = 18; // not including mandatory TLVs

  QueryBroadcastSmResp();

  QueryBroadcastSmResp(const CommandStatus &command_status,
                       const SequenceNumber &sequence_number,
                       const MessageId &message_id,
                       const MessageState &message_state);

  ~QueryBroadcastSmResp();

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

  void setMessageState(const MessageState &p) {
    message_state = p;
  }

  //
  // Accessing
  //

  const MessageId &getMessageId() const { return message_id; }

  const MessageState &getMessageState() const { return message_state; }
};

} // namespace smpp

#endif // SMPP_QUERY_BROADCAST_SM_RESP_H
