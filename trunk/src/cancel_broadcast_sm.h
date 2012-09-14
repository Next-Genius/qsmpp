#ifndef SMPP_CANCEL_BROADCAST_SM_H
#define SMPP_CANCEL_BROADCAST_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class CancelBroadcastSm : public Request {
  ServiceType service_type;
  MessageId message_id;
  SmeAddress source_addr;

public:
  const static int min_length = 21;

  CancelBroadcastSm();

  CancelBroadcastSm(const SequenceNumber &sequence_number,
                    const ServiceType &service_type,
                    const MessageId &message_id,
                    const SmeAddress &source_addr);

  ~CancelBroadcastSm();

  //
  // Mutating
  //

  void setServiceType(const ServiceType &p) {
    int diff = p.length() - service_type.length();
    service_type = p;
    Header::updateLength(diff);
  }

  void setServiceType(const char *p) {
    int diff = strlen(p) - service_type.length();
    service_type = p;
    Header::updateLength(diff);
  }

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
    source_addr = SmeAddress(Ton(Ton::Unknown),
                             Npi(Npi::Unknown),
                             p);
    Header::updateLength(diff);
  }

  //
  // Accessing
  //

  const ServiceType &getServiceType() const { return service_type; }

  const MessageId &getMessageId() const { return message_id; }

  const SmeAddress &getSourceAddr() const { return source_addr; }
};

} // namespace smpp

#endif // SMPP_CANCEL_BROADCAST_SM_H
