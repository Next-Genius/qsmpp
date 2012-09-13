#ifndef SMPP_QUERY_SM_RESP_H
#define SMPP_QUERY_SM_RESP_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class QuerySmResp : public Response {
  MessageId message_id;
  Time final_date;
  MessageState message_state;
  ErrorCode error_code;
public:

  const static int min_length = 20;

  QuerySmResp();

  QuerySmResp(const CommandStatus &command_status,
              const SequenceNumber &sequence_number,
              const MessageId &message_id,
              const Time &final_date,
              const MessageState &message_state,
              const ErrorCode &error_code);

  ~QuerySmResp();

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

  void setFinalDate(const Time &p) {
    int diff = p.length() - final_date.length();
    final_date = p;
    Header::updateLength(diff);
  }

  void setFinalDate(const char *p) {
    int diff = strlen(p) - final_date.length();
    final_date = p;
    Header::updateLength(diff);
  }

  void setMessageState(const MessageState &p) {
     message_state = p;
  }

  void setErrorCode(const ErrorCode &p) {
    error_code = p;
  }

  //
  // Accessing
  //

  const MessageId &getMessageId() const { return message_id; }

  const Time &getFinalDate() const { return final_date; }

  const MessageState &getMessageState() const { return message_state; }

  const ErrorCode &getErrorCode() const { return error_code; }
};

} // namespace smpp

#endif // SMPP_QUERY_SM_RESP_H
