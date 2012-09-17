#ifndef SMPP_BROADCAST_SM_H
#define SMPP_BROADCAST_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class BroadcastSm : public TlvsHeader {
  ServiceType service_type;
  SmeAddress source_addr;
  MessageId message_id;
  PriorityFlag priority_flag;
  Time schedule_delivery_time;
  Time validity_period;
  ReplaceIfPresentFlag replace_if_present_flag;
  DataCoding data_coding;
  SmDefaultMsgId sm_default_msg_id;

public:
  const static int min_length = 27; // not including mandatory TLVs

  BroadcastSm();

  BroadcastSm(const SequenceNumber &sequence_number,
              const ServiceType &service_type,
              const SmeAddress &source_addr,
              const MessageId &message_id,
              const PriorityFlag &priority_flag,
              const Time &schedule_delivery_time,
              const Time &validity_period,
              const ReplaceIfPresentFlag &replace_if_present_flag,
              const DataCoding &data_coding,
              const SmDefaultMsgId &sm_default_msg_id);

  ~BroadcastSm();

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

  void setPriorityFlag(const int &p) { priority_flag = p; }

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

  void setReplaceIfPresentFlag(const ReplaceIfPresentFlag &p) {
    replace_if_present_flag = p;
  }

  void setDataCoding(const DataCoding &p) { data_coding = p; }

  void setSmDefaultMsgId(const SmDefaultMsgId &p) {
    sm_default_msg_id = p;
  }

  //
  // Accessing
  //

  const ServiceType &getServiceType() const { return service_type; }

  const SmeAddress &getSourceAddr() const { return source_addr; }

  const MessageId &getMessageId() const { return message_id; }

  const PriorityFlag &getPriorityFlag() const { return priority_flag; }

  const Time &getScheduleDeliveryTime() const {
    return schedule_delivery_time;
  }

  const Time &getValidityPeriod() const { return validity_period; }

  const ReplaceIfPresentFlag &getReplaceIfPresentFlag() const {
    return replace_if_present_flag;
  }

  const DataCoding &getDataCoding() const { return data_coding; }

  const SmDefaultMsgId &getSmDefaultMsgId() const {
    return sm_default_msg_id;
  }
};

} // namespace smpp

#endif // SMPP_BROADCAST_SM_H
