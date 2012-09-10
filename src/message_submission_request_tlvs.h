#ifndef QSMPP_MESSAGE_SUBMISSION_REQUEST_TLVS_H
#define QSMPP_MESSAGE_SUBMISSION_REQUEST_TLVS_H

#include <alert_on_message_delivery.h>
#include <billing_identification.h>
#include <callback_num.h>
#include <callback_num_atag.h>
#include <callback_num_pres_ind.h>
#include <dest_addr_np_country.h>
#include <dest_addr_np_information.h>
#include <dest_addr_np_resolution.h>
#include <dest_addr_subunit.h>
#include <dest_bearer_type.h>
#include <dest_network_id.h>
#include <dest_network_type.h>
#include <dest_node_id.h>
#include <dest_subaddress.h>
#include <dest_telematics_id.h>
#include <dest_port.h>
#include <display_time.h>
#include <its_reply_type.h>
#include <its_session_info.h>
#include <language_indicator.h>
#include <message_payload.h>
#include <more_messages_to_send.h>
#include <ms_msg_wait_facilities.h>
#include <ms_validity.h>
#include <number_of_messages.h>
#include <payload_type.h>
#include <privacy_indicator.h>
#include <qos_time_to_live.h>
#include <sar_msg_ref_num.h>
#include <sar_segment_seqnum.h>
#include <sar_total_segments.h>
#include <set_dpf.h>
#include <sms_signal.h>
#include <source_addr_subunit.h>
#include <source_bearer_type.h>
#include <source_network_id.h>
#include <source_network_type.h>
#include <source_node_id.h>
#include <source_port.h>
#include <source_subaddress.h>
#include <source_telematics_id.h>
#include <user_message_reference.h>
#include <user_response_code.h>
#include <ussd_service_op.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MessageSubmissionRequestTLVs {
public:
  MessageSubmissionRequestTLVs(
    const AlertOnMessageDelivery *alert_on_message_delivery = 0,
    const BillingIdentification *billing_identification = 0,
    const CallbackNum *callback_num = 0,
    const CallbackNumAtag *callback_num_atag = 0,
    const CallbackNumPresInd *callback_num_pres_ind = 0,
    const DestAddrNpCountry *dest_addr_np_country = 0,
    const DestAddrNpInformation *dest_addr_np_information = 0,
    const DestAddrNpResolution *dest_addr_np_resolution = 0,
    const DestAddrSubunit *dest_addr_subunit = 0,
    const DestBearerType *dest_bearer_type = 0,
    const DestNetworkId *dest_network_id = 0,
    const DestNetworkType *dest_network_type = 0,
    const DestNodeId *dest_node_id = 0,
    const DestSubaddress *dest_subaddress = 0,
    const DestTelematicsId *dest_telematics_id = 0,
    const DestPort *dest_port = 0,
    const DisplayTime *display_time = 0,
    const ItsReplyType *its_reply_type = 0,
    const ItsSessionInfo *its_session_info = 0,
    const LanguageIndicator *language_indicator = 0,
    const MessagePayload *message_payload = 0,
    const MoreMessagesToSend *more_messages_to_send = 0,
    const MsMsgWaitFacilities *ms_msg_wait_facilities = 0,
    const MsValidity *ms_validity = 0,
    const NumberOfMessages *number_of_messages = 0,
    const PayloadType *payload_type = 0,
    const PrivacyIndicator *privacy_indicator = 0,
    const QosTimeToLive *qos_time_to_live = 0,
    const SarMsgRefNum *sar_msg_ref_num = 0,
    const SarSegmentSeqnum *sar_segment_seqnum = 0,
    const SarTotalSegments *sar_total_segments = 0,
    const SetDpf *set_dpf = 0,
    const SmsSignal *sms_signal = 0,
    const SourceAddrSubunit *source_addr_subunit = 0,
    const SourceBearerType *source_bearer_type = 0,
    const SourceNetworkId *source_network_id = 0,
    const SourceNetworkType *source_network_type = 0,
    const SourceNodeId *source_node_id = 0,
    const SourcePort *source_port = 0,
    const SourceSubaddress *source_subaddress = 0,
    const SourceTelematicsId *source_telematics_id = 0,
    const UserMessageReference *user_message_reference = 0,
    const UserResponseCode *user_response_code = 0,
    const UssdServiceOp *ussd_service_op = 0);

  MessageSubmissionRequestTLVs(const MessageSubmissionRequestTLVs &other);

  ~MessageSubmissionRequestTLVs();

  bool operator ==(const MessageSubmissionRequestTLVs &other) const;

  bool operator !=(const MessageSubmissionRequestTLVs &other) const;

  MessageSubmissionRequestTLVs &operator =(
    const MessageSubmissionRequestTLVs &other);

  void setAlertOnMessageDelivery(
    const AlertOnMessageDelivery *alert_on_message_delivery);

  AlertOnMessageDelivery *getAlertOnMessageDelivery() const;

  void setBillingIdentification(
    const BillingIdentification *billing_identification);

  BillingIdentification *getBillingIdentification() const;

  void setCallbackNum(const CallbackNum *callback_num);

  CallbackNum *getCallbackNum() const;

  void setCallbackNumAtag(const CallbackNumAtag *callback_num_atag);

  CallbackNumAtag *getCallbackNumAtag() const;

  void setCallbackNumPresInd(const CallbackNumPresInd *callback_num_pres_ind);

  CallbackNumPresInd *getCallbackNumPresInd() const;

  void setDestAddrNpCountry(const DestAddrNpCountry *dest_addr_np_country);

  DestAddrNpCountry *getDestAddrNpCountry() const;

  void setDestAddrNpInformation(
    const DestAddrNpInformation *dest_addr_np_information);

  DestAddrNpInformation *getDestAddrNpInformation() const;

  void setDestAddrNpResolution(
    const DestAddrNpResolution *dest_addr_np_resolution);

  DestAddrNpResolution *getDestAddrNpResolution() const;

  void setDestAddrSubunit(const DestAddrSubunit *dest_addr_subunit);

  DestAddrSubunit *getDestAddrSubunit() const;

  void setDestBearerType(const DestBearerType *dest_bearer_type);

  DestBearerType *getDestBearerType() const;

  void setDestNetworkId(const DestNetworkId *dest_network_id);

  DestNetworkId *getDestNetworkId() const;

  void setDestNetworkType(const DestNetworkType *dest_network_type);

  DestNetworkType *getDestNetworkType() const;

  void setDestNodeId(const DestNodeId *dest_node_id);

  DestNodeId *getDestNodeId() const;

  void setDestSubaddress(const DestSubaddress *dest_subaddress);

  DestSubaddress *getDestSubaddress() const;

  void setDestTelematicsId(const DestTelematicsId *dest_telematics_id);

  DestTelematicsId *getDestTelematicsId() const;

  void setDestPort(const DestPort *dest_port);

  DestPort *getDestPort() const;

  void setDisplayTime(const DisplayTime *display_time);

  DisplayTime *getDisplayTime() const;

  void setItsReplyType(const ItsReplyType *its_reply_type);

  ItsReplyType *getItsReplyType() const;

  void setItsSessionInfo(const ItsSessionInfo *its_session_info);

  ItsSessionInfo *getItsSessionInfo() const;

  void setLanguageIndicator(const LanguageIndicator *language_indicator);

  LanguageIndicator *getLanguageIndicator() const;

  void setMessagePayload(const MessagePayload *message_payload);

  MessagePayload *getMessagePayload() const;

  void setMoreMessagesToSend(const MoreMessagesToSend *more_messages_to_send);

  MoreMessagesToSend *getMoreMessagesToSend() const;

  void setMsMsgWaitFacilities(
    const MsMsgWaitFacilities *ms_msg_wait_facilities);

  MsMsgWaitFacilities *getMsMsgWaitFacilities() const;

  void setMsValidity(const MsValidity *ms_validity);

  MsValidity *getMsValidity() const;

  void setNumberOfMessages(const NumberOfMessages *number_of_messages);

  NumberOfMessages *getNumberOfMessages() const;

  void setPayloadType(const PayloadType *payload_type);

  PayloadType *getPayloadType() const;

  void setPrivacyIndicator(const PrivacyIndicator *privacy_indicator);

  PrivacyIndicator *getPrivacyIndicator() const;

  void setQosTimeToLive(const QosTimeToLive *qos_time_to_live);

  QosTimeToLive *getQosTimeToLive() const;

  void setSarMsgRefNum(const SarMsgRefNum *sar_msg_ref_num);

  SarMsgRefNum *getSarMsgRefNum() const;

  void setSarSegmentSeqnum(const SarSegmentSeqnum *sar_segment_seqnum);

  SarSegmentSeqnum *getSarSegmentSeqnum() const;

  void setSarTotalSegments(const SarTotalSegments *sar_total_segments);

  SarTotalSegments *getSarTotalSegments() const;

  void setSetDpf(const SetDpf *set_dpf);

  SetDpf *getSetDpf() const;

  void setSmsSignal(const SmsSignal *sms_signal);

  SmsSignal *getSmsSignal() const;

  void setSourceAddrSubunit(const SourceAddrSubunit *source_addr_subunit);

  SourceAddrSubunit *getSourceAddrSubunit() const;

  void setSourceBearerType(const SourceBearerType *source_bearer_type);

  SourceBearerType *getSourceBearerType() const;

  void setSourceNetworkId(const SourceNetworkId *source_network_id);

  SourceNetworkId *getSourceNetworkId() const;

  void setSourceNetworkType(const SourceNetworkType *source_network_type);

  SourceNetworkType *getSourceNetworkType() const;

  void setSourceNodeId(const SourceNodeId *source_node_id);

  SourceNodeId *getSourceNodeId() const;

  void setSourcePort(const SourcePort *source_port);

  SourcePort *getSourcePort() const;

  void setSourceSubaddress(const SourceSubaddress *source_subaddress);

  SourceSubaddress *getSourceSubaddress() const;

  void setSourceTelematicsId(const SourceTelematicsId *source_telematics_id);

  SourceTelematicsId *getSourceTelematicsId() const;

  void setUserMessageReference(
    const UserMessageReference *user_message_reference);

  UserMessageReference *getUserMessageReference() const;

  void setUserResponseCode(const UserResponseCode *user_response_code);

  UserResponseCode *getUserResponseCode() const;

  void setUssdServiceOp(const UssdServiceOp *ussd_service_op);

  UssdServiceOp *getUssdServiceOp() const;

protected:
  AlertOnMessageDelivery *alert_on_message_delivery;
  BillingIdentification *billing_identification;
  CallbackNum *callback_num;
  CallbackNumAtag *callback_num_atag;
  CallbackNumPresInd *callback_num_pres_ind;
  DestAddrNpCountry *dest_addr_np_country;
  DestAddrNpInformation *dest_addr_np_information;
  DestAddrNpResolution *dest_addr_np_resolution;
  DestAddrSubunit *dest_addr_subunit;
  DestBearerType *dest_bearer_type;
  DestNetworkId *dest_network_id;
  DestNetworkType *dest_network_type;
  DestNodeId *dest_node_id;
  DestSubaddress *dest_subaddress;
  DestTelematicsId *dest_telematics_id;
  DestPort *dest_port;
  DisplayTime *display_time;
  ItsReplyType *its_reply_type;
  ItsSessionInfo *its_session_info;
  LanguageIndicator *language_indicator;
  MessagePayload *message_payload;
  MoreMessagesToSend *more_messages_to_send;
  MsMsgWaitFacilities *ms_msg_wait_facilities;
  MsValidity *ms_validity;
  NumberOfMessages *number_of_messages;
  PayloadType *payload_type;
  PrivacyIndicator *privacy_indicator;
  QosTimeToLive *qos_time_to_live;
  SarMsgRefNum *sar_msg_ref_num;
  SarSegmentSeqnum *sar_segment_seqnum;
  SarTotalSegments *sar_total_segments;
  SetDpf *set_dpf;
  SmsSignal *sms_signal;
  SourceAddrSubunit *source_addr_subunit;
  SourceBearerType *source_bearer_type;
  SourceNetworkId *source_network_id;
  SourceNetworkType *source_network_type;
  SourceNodeId *source_node_id;
  SourcePort *source_port;
  SourceSubaddress *source_subaddress;
  SourceTelematicsId *source_telematics_id;
  UserMessageReference *user_message_reference;
  UserResponseCode *user_response_code;
  UssdServiceOp *ussd_service_op;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MESSAGE_SUBMISSION_REQUEST_TLVS_H
