#ifndef SMPP_REPLACE_SM_H
#define SMPP_REPLACE_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class ReplaceSm : public TlvsHeader {
  MessageId message_id;
  SmeAddress source_addr;
  Time schedule_delivery_time;
  Time validity_period;
  RegisteredDelivery registered_delivery;
  SmDefaultMsgId sm_default_msg_id;
  ShortMessage short_message;

public:
  const static int min_length = 25;

  ReplaceSm();

  ReplaceSm(const SequenceNumber &sequence_number,
            const MessageId &service_type,
            const SmeAddress &source_addr,
            const Time &schedule_delivery_time,
            const Time &validity_period,
            const RegisteredDelivery &registered_delivery,
            const SmDefaultMsgId &sm_default_msg_id,
            const ShortMessage &short_message);

  ~ReplaceSm();

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

  void setScheduleDeliveryTime(const Time &p) {
    int diff = p.length() - schedule_delivery_time.length();
    schedule_delivery_time = p;
    Header::updateLength(diff);
  }

  void setScheduleDeliveryTime(const char *p) {
    int diff = strlen(p) - schedule_delivery_time.length();
    schedule_delivery_time = p;
    Header::updateLength(diff);
  }

  void setValidityPeriod(const Time &p) {
    int diff = p.length() - validity_period.length();
    validity_period = p;
    Header::updateLength(diff);
  }

  void setValidityPeriod(const char *p) {
    int diff = strlen(p) - validity_period.length();
    validity_period = p;
    Header::updateLength(diff);
  }

  void setRegisteredDelivery(const RegisteredDelivery &p) {
    registered_delivery = p;
  }

  void setSmDefaultMsgId(const SmDefaultMsgId &p) {
    sm_default_msg_id = p;
  }

  void setShortMessage(const uint8 *p, uint8 l) {
    int diff = l - short_message.length();
    short_message = ShortMessage(p, l);
    Header::updateLength(diff);
  }

  //
  // Accessing
  //

  const MessageId &getMessageId() const { return message_id; }

  const SmeAddress &getSourceAddr() const { return source_addr; }

  const Time &getScheduleDeliveryTime() const {
    return schedule_delivery_time;
  }

  const Time &getValidityPeriod() const { return validity_period; }

  const RegisteredDelivery &getRegisteredDelivery() const {
    return registered_delivery;
  }

  const SmDefaultMsgId &getSmDefaultMsgId() const {
    return sm_default_msg_id;
  }

  const String::size_type getSmLength() const {
    return short_message.length();
  }

  const ShortMessage &getShortMessage() const { return short_message; }
};

} // namespace smpp

#endif // SMPP_REPLACE_SM_H
