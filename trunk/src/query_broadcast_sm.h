#ifndef SMPP_QUERY_BROADCAST_SM_H
#define SMPP_QUERY_BROADCAST_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class QueryBroadcastSm : public TlvsHeader {
   MessageId message_id;
   SmeAddress source_addr;
 public:
  const static int min_length = 20;

  QueryBroadcastSm();

  QueryBroadcastSm(const SequenceNumber &sequence_number,
                   const MessageId &message_id,
                   const SmeAddress &source_addr);

  ~QueryBroadcastSm();

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

  void setSourceAddr(const SmeAddress &p) {
    int diff = p.getAddress().length() - source_addr.getAddress().length();
    source_addr = p;
    Header::updateLength(diff);
  }

  void setSourceAddr(const Address &p) {
    int diff = p.length() - source_addr.getAddress().length();
    source_addr = SmeAddress(Ton(Ton::Unknown), Npi(Npi::Unknown), p);
    Header::updateLength(diff);
  }

  //
  // Accessing
  //

  const MessageId &getMessageId() const { return message_id; }

  const SmeAddress &getSourceAddr() const { return source_addr; }
 };

} // namespace smpp

#endif // SMPP_QUERY_BROADCAST_SM_H
