#ifndef SMPP_SUBMIT_SM_H
#define SMPP_SUBMIT_SM_H

#include <header.h>
#include <standart_parameters.h>

namespace smpp {

class SubmitSm : public Request {
  ServiceType service_type;
  SmeAddress source_addr;
  SmeAddress destination_addr;
  EsmClass esm_class;
  ProtocolId protocol_id;
  PriorityFlag priority_flag;
  Time schedule_delivery_time;
  Time validity_period;
  RegisteredDelivery registered_delivery;
  ReplaceIfPresentFlag replace_if_present_flag;
  DataCoding data_coding;
  SmDefaultMsgId sm_default_msg_id;
  ShortMessage short_message;

public:
  const static int min_length = 33;

  SubmitSm();

  SubmitSm(const SequenceNumber &sequence_number,
           const ServiceType &service_type,
           const SmeAddress &source_addr,
           const SmeAddress &destination_addr,
           const EsmClass &esm_class,
           const ProtocolId &protocol_id,
           const PriorityFlag &priority_flag,
           const Time &schedule_delivery_time,
           const Time &validity_period,
           const RegisteredDelivery &registered_delivery,
           const ReplaceIfPresentFlag &replace_if_present_flag,
           const DataCoding &data_coding,
           const SmDefaultMsgId &sm_default_msg_id,
           const ShortMessage &short_message);

  ~SubmitSm();

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
    source_addr = SmeAddress(Ton(Ton::Unknown), Npi(Npi::Unknown), p);
    Header::updateLength(diff);
  }

  void setDestinationAddr(const SmeAddress &p) {
    int diff =
        p.getAddress().length() - destination_addr.getAddress().length();
    destination_addr = p;
    Header::updateLength(diff);
  }

  void setDestinationAddr(const Address &p) {
    int diff = p.length() - destination_addr.getAddress().length();
    destination_addr = SmeAddress(Ton(Ton::Unknown), Npi(Npi::Unknown), p);
    Header::updateLength(diff);
  }

  void setEsmClass(const int &p) { esm_class = p; }

  void setProtocolId(const int &p) { protocol_id = p; }

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

  void setRegisteredDelivery(const RegisteredDelivery &p) {
    registered_delivery = p;
  }

  void setReplaceIfPresentFlag(const ReplaceIfPresentFlag &p) {
    replace_if_present_flag = p;
  }

  void setDataCoding(const DataCoding &p) { data_coding = p; }

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

  const ServiceType &getServiceType() const { return service_type; }

  const SmeAddress &getSourceAddr() const { return source_addr; }

  const SmeAddress &getDestinationAddr() const { return destination_addr; }

  const EsmClass &getEsmClass() const { return esm_class; }

  const ProtocolId &getProtocolId() const { return protocol_id; }

  const PriorityFlag &getPriorityFlag() const { return priority_flag; }

  const Time &getScheduleDeliveryTime() const {
      return schedule_delivery_time;
  }

  const Time &getValidityPeriod() const { return validity_period; }

  const RegisteredDelivery &getRegisteredDelivery() const {
      return registered_delivery;
  }

  const ReplaceIfPresentFlag &getReplaceIfPresentFlag() const {
      return replace_if_present_flag;
  }

  const DataCoding &getDataCoding() const { return data_coding; }

  const SmDefaultMsgId &getSmDefaultMsgId() const {
    return sm_default_msg_id;
  }

  const String::size_type getSmLength() const {
    return short_message.length();
  }

  const ShortMessage &getShortMessage() const { return short_message; }
};

} // namespace smpp

#endif // SMPP_SUBMIT_SM_H
