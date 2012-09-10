#include <message_submission_request_tlvs.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MessageSubmissionRequestTLVs::MessageSubmissionRequestTLVs(
  const AlertOnMessageDelivery *alert_on_message_delivery,
  const BillingIdentification *billing_identification,
  const CallbackNum *callback_num,
  const CallbackNumAtag *callback_num_atag,
  const CallbackNumPresInd *callback_num_pres_ind,
  const DestAddrNpCountry *dest_addr_np_country,
  const DestAddrNpInformation *dest_addr_np_information,
  const DestAddrNpResolution *dest_addr_np_resolution,
  const DestAddrSubunit *dest_addr_subunit,
  const DestBearerType *dest_bearer_type,
  const DestNetworkId *dest_network_id,
  const DestNetworkType *dest_network_type,
  const DestNodeId *dest_node_id,
  const DestSubaddress *dest_subaddress,
  const DestTelematicsId *dest_telematics_id,
  const DestPort *dest_port,
  const DisplayTime *display_time,
  const ItsReplyType *its_reply_type,
  const ItsSessionInfo *its_session_info,
  const LanguageIndicator *language_indicator,
  const MessagePayload *message_payload,
  const MoreMessagesToSend *more_messages_to_send,
  const MsMsgWaitFacilities *ms_msg_wait_facilities,
  const MsValidity *ms_validity,
  const NumberOfMessages *number_of_messages,
  const PayloadType *payload_type,
  const PrivacyIndicator *privacy_indicator,
  const QosTimeToLive *qos_time_to_live,
  const SarMsgRefNum *sar_msg_ref_num,
  const SarSegmentSeqnum *sar_segment_seqnum,
  const SarTotalSegments *sar_total_segments,
  const SetDpf *set_dpf,
  const SmsSignal *sms_signal,
  const SourceAddrSubunit *source_addr_subunit,
  const SourceBearerType *source_bearer_type,
  const SourceNetworkId *source_network_id,
  const SourceNetworkType *source_network_type,
  const SourceNodeId *source_node_id,
  const SourcePort *source_port,
  const SourceSubaddress *source_subaddress,
  const SourceTelematicsId *source_telematics_id,
  const UserMessageReference *user_message_reference,
  const UserResponseCode *user_response_code,
  const UssdServiceOp *ussd_service_op):
    alert_on_message_delivery(0),
    billing_identification(0),
    callback_num(0),
    callback_num_atag(0),
    callback_num_pres_ind(0),
    dest_addr_np_country(0),
    dest_addr_np_information(0),
    dest_addr_np_resolution(0),
    dest_addr_subunit(0),
    dest_bearer_type(0),
    dest_network_id(0),
    dest_network_type(0),
    dest_node_id(0),
    dest_subaddress(0),
    dest_telematics_id(0),
    dest_port(0),
    display_time(0),
    its_reply_type(0),
    its_session_info(0),
    language_indicator(0),
    message_payload(0),
    more_messages_to_send(0),
    ms_msg_wait_facilities(0),
    ms_validity(0),
    number_of_messages(0),
    payload_type(0),
    privacy_indicator(0),
    qos_time_to_live(0),
    sar_msg_ref_num(0),
    sar_segment_seqnum(0),
    sar_total_segments(0),
    set_dpf(0),
    sms_signal(0),
    source_addr_subunit(0),
    source_bearer_type(0),
    source_network_id(0),
    source_network_type(0),
    source_node_id(0),
    source_port(0),
    source_subaddress(0),
    source_telematics_id(0),
    user_message_reference(0),
    user_response_code(0),
    ussd_service_op(0) {
  if (alert_on_message_delivery)
    this->alert_on_message_delivery =
      new AlertOnMessageDelivery(*alert_on_message_delivery);
  if (billing_identification)
    this->billing_identification =
      new BillingIdentification(*billing_identification);
  if (callback_num)
    this->callback_num = new CallbackNum(*callback_num);
  if (callback_num_atag)
    this->callback_num_atag = new CallbackNumAtag(*callback_num_atag);
  if (callback_num_pres_ind)
    this->callback_num_pres_ind =
      new CallbackNumPresInd(*callback_num_pres_ind);
  if (dest_addr_np_country)
    this->dest_addr_np_country =
      new DestAddrNpCountry(*dest_addr_np_country);
  if (dest_addr_np_information)
    this->dest_addr_np_information =
      new DestAddrNpInformation(*dest_addr_np_information);
  if (dest_addr_np_resolution)
    this->dest_addr_np_resolution =
      new DestAddrNpResolution(*dest_addr_np_resolution);
  if (dest_addr_subunit)
    this->dest_addr_subunit = new DestAddrSubunit(*dest_addr_subunit);
  if (dest_bearer_type)
    this->dest_bearer_type = new DestBearerType(*dest_bearer_type);
  if (dest_network_id)
    this->dest_network_id = new DestNetworkId(*dest_network_id);
  if (dest_network_type)
    this->dest_network_type = new DestNetworkType(*dest_network_type);
  if (dest_node_id)
    this->dest_node_id = new DestNodeId(*dest_node_id);
  if (dest_subaddress)
    this->dest_subaddress = new DestSubaddress(*dest_subaddress);
  if (dest_telematics_id)
    this->dest_telematics_id = new DestTelematicsId(*dest_telematics_id);
  if (dest_port)
    this->dest_port = new DestPort(*dest_port);
  if (display_time)
    this->display_time = new DisplayTime(*display_time);
  if (its_reply_type)
    this->its_reply_type = new ItsReplyType(*its_reply_type);
  if (its_session_info)
    this->its_session_info = new ItsSessionInfo(*its_session_info);
  if (language_indicator)
    this->language_indicator = new LanguageIndicator(*language_indicator);
  if (message_payload)
    this->message_payload = new MessagePayload(*message_payload);
  if (more_messages_to_send)
    this->more_messages_to_send =
      new MoreMessagesToSend(*more_messages_to_send);
  if (ms_msg_wait_facilities)
    this->ms_msg_wait_facilities =
      new MsMsgWaitFacilities(*ms_msg_wait_facilities);
  if (ms_validity)
    this->ms_validity = new MsValidity(*ms_validity);
  if (number_of_messages)
    this->number_of_messages = new NumberOfMessages(*number_of_messages);
  if (payload_type)
    this->payload_type = new PayloadType(*payload_type);
  if (privacy_indicator)
    this->privacy_indicator = new PrivacyIndicator(*privacy_indicator);
  if (qos_time_to_live)
    this->qos_time_to_live = new QosTimeToLive(*qos_time_to_live);
  if (sar_msg_ref_num)
    this->sar_msg_ref_num = new SarMsgRefNum(*sar_msg_ref_num);
  if (sar_segment_seqnum)
    this->sar_segment_seqnum = new SarSegmentSeqnum(*sar_segment_seqnum);
  if (sar_total_segments)
    this->sar_total_segments = new SarTotalSegments(*sar_total_segments);
  if (set_dpf)
    this->set_dpf = new SetDpf(*set_dpf);
  if (sms_signal)
    this->sms_signal = new SmsSignal(*sms_signal);
  if (source_addr_subunit)
    this->source_addr_subunit = new SourceAddrSubunit(*source_addr_subunit);
  if (source_bearer_type)
    this->source_bearer_type = new SourceBearerType(*source_bearer_type);
  if (source_network_id)
    this->source_network_id = new SourceNetworkId(*source_network_id);
  if (source_network_type)
    this->source_network_type = new SourceNetworkType(*source_network_type);
  if (source_node_id)
    this->source_node_id = new SourceNodeId(*source_node_id);
  if (source_port)
    this->source_port = new SourcePort(*source_port);
  if (source_subaddress)
    this->source_subaddress = new SourceSubaddress(*source_subaddress);
  if (source_telematics_id)
    this->source_telematics_id = new SourceTelematicsId(*source_telematics_id);
  if (user_message_reference)
    this->user_message_reference =
      new UserMessageReference(*user_message_reference);
  if (user_response_code)
    this->user_response_code = new UserResponseCode(*user_response_code);
  if (ussd_service_op)
    this->ussd_service_op = new UssdServiceOp(*ussd_service_op);
}

MessageSubmissionRequestTLVs::MessageSubmissionRequestTLVs(
  const MessageSubmissionRequestTLVs &other):
    alert_on_message_delivery(0),
    billing_identification(0),
    callback_num(0),
    callback_num_atag(0),
    callback_num_pres_ind(0),
    dest_addr_np_country(0),
    dest_addr_np_information(0),
    dest_addr_np_resolution(0),
    dest_addr_subunit(0),
    dest_bearer_type(0),
    dest_network_id(0),
    dest_network_type(0),
    dest_node_id(0),
    dest_subaddress(0),
    dest_telematics_id(0),
    dest_port(0),
    display_time(0),
    its_reply_type(0),
    its_session_info(0),
    language_indicator(0),
    message_payload(0),
    more_messages_to_send(0),
    ms_msg_wait_facilities(0),
    ms_validity(0),
    number_of_messages(0),
    payload_type(0),
    privacy_indicator(0),
    qos_time_to_live(0),
    sar_msg_ref_num(0),
    sar_segment_seqnum(0),
    sar_total_segments(0),
    set_dpf(0),
    sms_signal(0),
    source_addr_subunit(0),
    source_bearer_type(0),
    source_network_id(0),
    source_network_type(0),
    source_node_id(0),
    source_port(0),
    source_subaddress(0),
    source_telematics_id(0),
    user_message_reference(0),
    user_response_code(0),
    ussd_service_op(0) {
  if (other.getAlertOnMessageDelivery())
    alert_on_message_delivery =
      new AlertOnMessageDelivery(*other.getAlertOnMessageDelivery());
  if (other.getBillingIdentification())
    billing_identification =
      new BillingIdentification(*other.getBillingIdentification());
  if (other.getCallbackNum())
    callback_num = new CallbackNum(*other.getCallbackNum());
  if (other.getCallbackNumAtag())
    callback_num_atag = new CallbackNumAtag(*other.getCallbackNumAtag());
  if (other.getCallbackNumPresInd())
    callback_num_pres_ind =
      new CallbackNumPresInd(*other.getCallbackNumPresInd());
  if (other.getDestAddrNpCountry())
    dest_addr_np_country =
      new DestAddrNpCountry(*other.getDestAddrNpCountry());
  if (other.getDestAddrNpInformation())
      dest_addr_np_information =
      new DestAddrNpInformation(*other.getDestAddrNpInformation());
  if (other.getDestAddrNpResolution())
    dest_addr_np_resolution =
      new DestAddrNpResolution(*other.getDestAddrNpResolution());
  if (other.getDestAddrSubunit())
    dest_addr_subunit = new DestAddrSubunit(*other.getDestAddrSubunit());
  if (other.getDestBearerType())
    dest_bearer_type = new DestBearerType(*other.getDestBearerType());
  if (other.getDestNetworkId())
    dest_network_id = new DestNetworkId(*other.getDestNetworkId());
  if (other.getDestNetworkType())
    dest_network_type = new DestNetworkType(*other.getDestNetworkType());
  if (other.getDestNodeId())
    dest_node_id = new DestNodeId(*other.getDestNodeId());
  if (other.getDestSubaddress())
    dest_subaddress = new DestSubaddress(*other.getDestSubaddress());
  if (other.getDestTelematicsId())
    dest_telematics_id = new DestTelematicsId(*other.getDestTelematicsId());
  if (other.getDestPort())
    dest_port = new DestPort(*other.getDestPort());
  if (other.getDisplayTime())
    display_time = new DisplayTime(*other.getDisplayTime());
  if (other.getItsReplyType())
    its_reply_type = new ItsReplyType(*other.getItsReplyType());
  if (other.getItsSessionInfo())
    its_session_info = new ItsSessionInfo(*other.getItsSessionInfo());
  if (other.getLanguageIndicator())
    language_indicator = new LanguageIndicator(*other.getLanguageIndicator());
  if (other.getMessagePayload())
    message_payload = new MessagePayload(*other.getMessagePayload());
  if (other.getMoreMessagesToSend())
    more_messages_to_send = new MoreMessagesToSend(
      *other.getMoreMessagesToSend());
  if (other.getMsMsgWaitFacilities())
    ms_msg_wait_facilities = new MsMsgWaitFacilities(
      *other.getMsMsgWaitFacilities());
  if (other.getMsValidity())
    ms_validity = new MsValidity(*other.getMsValidity());
  if (other.getNumberOfMessages())
    number_of_messages = new NumberOfMessages(*other.getNumberOfMessages());
  if (other.getPayloadType())
    payload_type = new PayloadType(*other.getPayloadType());
  if (other.getPrivacyIndicator())
    privacy_indicator = new PrivacyIndicator(*other.getPrivacyIndicator());
  if (other.getQosTimeToLive())
    qos_time_to_live = new QosTimeToLive(*other.getQosTimeToLive());
  if (other.getSarMsgRefNum())
    sar_msg_ref_num = new SarMsgRefNum(*other.getSarMsgRefNum());
  if (other.getSarSegmentSeqnum())
    sar_segment_seqnum = new SarSegmentSeqnum(*other.getSarSegmentSeqnum());
  if (other.getSarTotalSegments())
    sar_total_segments = new SarTotalSegments(*other.getSarTotalSegments());
  if (other.getSetDpf())
    set_dpf = new SetDpf(*other.getSetDpf());
  if (other.getSmsSignal())
    sms_signal = new SmsSignal(*other.getSmsSignal());
  if (other.getSourceAddrSubunit())
    source_addr_subunit = new SourceAddrSubunit(*other.getSourceAddrSubunit());
  if (other.getSourceBearerType())
    source_bearer_type = new SourceBearerType(*other.getSourceBearerType());
  if (other.getSourceNetworkId())
    source_network_id = new SourceNetworkId(*other.getSourceNetworkId());
  if (other.getSourceNetworkType())
    source_network_type = new SourceNetworkType(*other.getSourceNetworkType());
  if (other.getSourceNodeId())
    source_node_id = new SourceNodeId(*other.getSourceNodeId());
  if (other.getSourcePort())
    source_port = new SourcePort(*other.getSourcePort());
  if (other.getSourceSubaddress())
    source_subaddress = new SourceSubaddress(*other.getSourceSubaddress());
  if (other.getSourceTelematicsId())
    source_telematics_id = new SourceTelematicsId(
      *other.getSourceTelematicsId());
  if (other.getUserMessageReference())
    user_message_reference = new UserMessageReference(
      *other.getUserMessageReference());
  if (other.getUserResponseCode())
    user_response_code = new UserResponseCode(*other.getUserResponseCode());
  if (other.getUssdServiceOp())
    ussd_service_op = new UssdServiceOp(*other.getUssdServiceOp());
}

MessageSubmissionRequestTLVs::~MessageSubmissionRequestTLVs() {
  if (alert_on_message_delivery)
    delete alert_on_message_delivery;
  if (billing_identification)
    delete billing_identification;
  if (callback_num)
    delete callback_num;
  if (callback_num_atag)
    delete callback_num_atag;
  if (callback_num_pres_ind)
    delete callback_num_pres_ind;
  if (dest_addr_np_country)
    delete dest_addr_np_country;
  if (dest_addr_np_information)
    delete dest_addr_np_information;
  if (dest_addr_np_resolution)
    delete dest_addr_np_resolution;
  if (dest_addr_subunit)
    delete dest_addr_subunit;
  if (dest_bearer_type)
    delete dest_bearer_type;
  if (dest_network_id)
    delete dest_network_id;
  if (dest_network_type)
    delete dest_network_type;
  if (dest_node_id)
    delete dest_node_id;
  if (dest_subaddress)
    delete dest_subaddress;
  if (dest_telematics_id)
    delete dest_telematics_id;
  if (dest_port)
    delete dest_port;
  if (display_time)
    delete display_time;
  if (its_reply_type)
    delete its_reply_type;
  if (its_session_info)
    delete its_session_info;
  if (language_indicator)
    delete language_indicator;
  if (message_payload)
    delete message_payload;
  if (more_messages_to_send)
    delete more_messages_to_send;
  if (ms_msg_wait_facilities)
    delete ms_msg_wait_facilities;
  if (ms_validity)
    delete ms_validity;
  if (number_of_messages)
    delete number_of_messages;
  if (payload_type)
    delete payload_type;
  if (privacy_indicator)
    delete privacy_indicator;
  if (qos_time_to_live)
    delete qos_time_to_live;
  if (sar_msg_ref_num)
    delete sar_msg_ref_num;
  if (sar_segment_seqnum)
    delete sar_segment_seqnum;
  if (sar_total_segments)
    delete sar_total_segments;
  if (set_dpf)
    delete set_dpf;
  if (sms_signal)
    delete sms_signal;
  if (source_addr_subunit)
    delete source_addr_subunit;
  if (source_bearer_type)
    delete source_bearer_type;
  if (source_network_id)
    delete source_network_id;
  if (source_network_type)
    delete source_network_type;
  if (source_node_id)
    delete source_node_id;
  if (source_port)
    delete source_port;
  if (source_subaddress)
    delete source_subaddress;
  if (source_telematics_id)
    delete source_telematics_id;
  if (user_message_reference)
    delete user_message_reference;
  if (user_response_code)
    delete user_response_code;
  if (ussd_service_op)
    delete ussd_service_op;
}

bool MessageSubmissionRequestTLVs::operator ==(
  const MessageSubmissionRequestTLVs &other) const {
  AlertOnMessageDelivery *other_alert_on_message_delivery(
    other.getAlertOnMessageDelivery());
  if (other_alert_on_message_delivery && alert_on_message_delivery) {
    if (*other_alert_on_message_delivery != *alert_on_message_delivery)
      return false;
  } else if(other_alert_on_message_delivery != 0 ||
            alert_on_message_delivery != 0) {
    return false;
  }
  BillingIdentification *other_billing_identification(
    other.getBillingIdentification());
  if (other_billing_identification && billing_identification) {
    if (*other_billing_identification != *billing_identification)
      return false;
  } else if(other_billing_identification != 0 ||
            billing_identification != 0) {
    return false;
  }
  CallbackNum *other_callback_num(other.getCallbackNum());
  if (other_callback_num && callback_num) {
    if (*other_callback_num != *callback_num)
      return false;
  } else if(other_callback_num != 0 ||
            callback_num != 0) {
    return false;
  }
  CallbackNumAtag *other_callback_num_atag(other.getCallbackNumAtag());
  if (other_callback_num_atag && callback_num_atag) {
    if (*other_callback_num_atag != *callback_num_atag)
      return false;
  } else if(other_callback_num_atag != 0 ||
            callback_num_atag != 0) {
    return false;
  }
  CallbackNumPresInd *other_callback_num_pres_ind(
    other.getCallbackNumPresInd());
  if (other_callback_num_pres_ind && callback_num_pres_ind) {
    if (*other_callback_num_pres_ind != *callback_num_pres_ind)
      return false;
  } else if(other_callback_num_pres_ind != 0 ||
            callback_num_pres_ind != 0) {
    return false;
  }
  DestAddrNpCountry *other_dest_addr_np_country(other.getDestAddrNpCountry());
  if (other_dest_addr_np_country && dest_addr_np_country) {
    if (*other_dest_addr_np_country != *dest_addr_np_country)
      return false;
  } else if(other_dest_addr_np_country != 0 ||
            dest_addr_np_country != 0) {
    return false;
  }
  DestAddrNpInformation *other_dest_addr_np_information(
    other.getDestAddrNpInformation());
  if (other_dest_addr_np_information && dest_addr_np_information) {
    if (*other_dest_addr_np_information != *dest_addr_np_information)
      return false;
  } else if(other_dest_addr_np_information != 0 ||
            dest_addr_np_information != 0) {
    return false;
  }
  DestAddrNpResolution *other_dest_addr_np_resolution(
    other.getDestAddrNpResolution());
  if (other_dest_addr_np_resolution && dest_addr_np_resolution) {
    if (*other_dest_addr_np_resolution != *dest_addr_np_resolution)
      return false;
  } else if(other_dest_addr_np_resolution != 0 ||
            dest_addr_np_resolution != 0) {
    return false;
  }
  DestAddrSubunit *other_dest_addr_subunit(other.getDestAddrSubunit());
  if (other_dest_addr_subunit && dest_addr_subunit) {
    if (*other_dest_addr_subunit != *dest_addr_subunit)
      return false;
  } else if(other_dest_addr_subunit != 0 ||
            dest_addr_subunit != 0) {
    return false;
  }
  DestBearerType *other_dest_bearer_type(other.getDestBearerType());
  if (other_dest_bearer_type && dest_bearer_type) {
    if (*other_dest_bearer_type != *dest_bearer_type)
      return false;
  } else if(other_dest_bearer_type != 0 ||
            dest_bearer_type != 0) {
    return false;
  }
  DestNetworkId *other_dest_network_id(other.getDestNetworkId());
  if (other_dest_network_id && dest_network_id) {
    if (*other_dest_network_id != *dest_network_id)
      return false;
  } else if(other_dest_network_id != 0 ||
            dest_network_id != 0) {
    return false;
  }
  DestNetworkType *other_dest_network_type(other.getDestNetworkType());
  if (other_dest_network_type && dest_network_type) {
    if (*other_dest_network_type != *dest_network_type)
      return false;
  } else if(other_dest_network_type != 0 ||
            dest_network_type != 0) {
    return false;
  }
  DestNodeId *other_dest_node_id(other.getDestNodeId());
  if (other_dest_node_id && dest_node_id) {
    if (*other_dest_node_id != *dest_node_id)
      return false;
  } else if(other_dest_node_id != 0 ||
            dest_node_id != 0) {
    return false;
  }
  DestSubaddress *other_dest_subaddress(other.getDestSubaddress());
  if (other_dest_subaddress && dest_subaddress) {
    if (*other_dest_subaddress != *dest_subaddress)
      return false;
  } else if(other_dest_subaddress != 0 ||
            dest_subaddress != 0) {
    return false;
  }
  DestTelematicsId *other_dest_telematics_id(other.getDestTelematicsId());
  if (other_dest_telematics_id && dest_telematics_id) {
    if (*other_dest_telematics_id != *dest_telematics_id)
      return false;
  } else if(other_dest_telematics_id != 0 ||
            dest_telematics_id != 0) {
    return false;
  }
  DestPort *other_dest_port(other.getDestPort());
  if (other_dest_port && dest_port) {
    if (*other_dest_port != *dest_port)
      return false;
  } else if(other_dest_port != 0 ||
            dest_port != 0) {
    return false;
  }
  DisplayTime *other_display_time(other.getDisplayTime());
  if (other_display_time && display_time) {
    if (*other_display_time != *display_time)
      return false;
  } else if(other_display_time != 0 ||
            display_time != 0) {
    return false;
  }
  ItsReplyType *other_its_reply_type(other.getItsReplyType());
  if (other_its_reply_type && its_reply_type) {
    if (*other_its_reply_type != *its_reply_type)
      return false;
  } else if(other_its_reply_type != 0 ||
            its_reply_type != 0) {
    return false;
  }
  ItsSessionInfo *other_its_session_info(other.getItsSessionInfo());
  if (other_its_session_info && its_session_info) {
    if (*other_its_session_info != *its_session_info)
      return false;
  } else if(other_its_session_info != 0 ||
            its_session_info != 0) {
    return false;
  }
  LanguageIndicator *other_language_indicator(other.getLanguageIndicator());
  if (other_language_indicator && language_indicator) {
    if (*other_language_indicator != *language_indicator)
      return false;
  } else if(other_language_indicator != 0 ||
            language_indicator != 0) {
    return false;
  }
  MessagePayload *other_message_payload(other.getMessagePayload());
  if (other_message_payload && message_payload) {
    if (*other_message_payload != *message_payload)
      return false;
  } else if(other_message_payload != 0 ||
            message_payload != 0) {
    return false;
  }
  MoreMessagesToSend *other_more_messages_to_send(
    other.getMoreMessagesToSend());
  if (other_more_messages_to_send && more_messages_to_send) {
    if (*other_more_messages_to_send != *more_messages_to_send)
      return false;
  } else if(other_more_messages_to_send != 0 ||
            more_messages_to_send != 0) {
    return false;
  }
  MsMsgWaitFacilities *other_ms_msg_wait_facilities(
    other.getMsMsgWaitFacilities());
  if (other_ms_msg_wait_facilities && ms_msg_wait_facilities) {
    if (*other_ms_msg_wait_facilities != *ms_msg_wait_facilities)
      return false;
  } else if(other_ms_msg_wait_facilities != 0 ||
            ms_msg_wait_facilities != 0) {
    return false;
  }
  MsValidity *other_ms_validity(other.getMsValidity());
  if (other_ms_validity && ms_validity) {
    if (*other_ms_validity != *ms_validity)
      return false;
  } else if(other_ms_validity != 0 ||
            ms_validity != 0) {
    return false;
  }
  NumberOfMessages *other_number_of_messages(other.getNumberOfMessages());
  if (other_number_of_messages && number_of_messages) {
    if (*other_number_of_messages != *number_of_messages)
      return false;
  } else if(other_number_of_messages != 0 ||
            number_of_messages != 0) {
    return false;
  }
  PayloadType *other_payload_type(other.getPayloadType());
  if (other_payload_type && payload_type) {
    if (*other_payload_type != *payload_type)
      return false;
  } else if(other_payload_type != 0 ||
            payload_type != 0) {
    return false;
  }
  PrivacyIndicator *other_privacy_indicator(other.getPrivacyIndicator());
  if (other_privacy_indicator && privacy_indicator) {
    if (*other_privacy_indicator != *privacy_indicator)
      return false;
  } else if(other_privacy_indicator != 0 ||
            privacy_indicator != 0) {
    return false;
  }
  QosTimeToLive *other_qos_time_to_live(other.getQosTimeToLive());
  if (other_qos_time_to_live && qos_time_to_live) {
    if (*other_qos_time_to_live != *qos_time_to_live)
      return false;
  } else if(other_qos_time_to_live != 0 ||
            qos_time_to_live != 0) {
    return false;
  }
  SarMsgRefNum *other_sar_msg_ref_num(other.getSarMsgRefNum());
  if (other_sar_msg_ref_num && sar_msg_ref_num) {
    if (*other_sar_msg_ref_num != *sar_msg_ref_num)
      return false;
  } else if(other_sar_msg_ref_num != 0 ||
            sar_msg_ref_num != 0) {
    return false;
  }
  SarSegmentSeqnum *other_sar_segment_seqnum(other.getSarSegmentSeqnum());
  if (other_sar_segment_seqnum && sar_segment_seqnum) {
    if (*other_sar_segment_seqnum != *sar_segment_seqnum)
      return false;
  } else if(other_sar_segment_seqnum != 0 ||
            sar_segment_seqnum != 0) {
    return false;
  }
  SarTotalSegments *other_sar_total_segments(other.getSarTotalSegments());
  if (other_sar_total_segments && sar_total_segments) {
    if (*other_sar_total_segments != *sar_total_segments)
      return false;
  } else if(other_sar_total_segments != 0 ||
            sar_total_segments != 0) {
    return false;
  }
  SetDpf *other_set_dpf(other.getSetDpf());
  if (other_set_dpf && set_dpf) {
    if (*other_set_dpf != *set_dpf)
      return false;
  } else if(other_set_dpf != 0 ||
            set_dpf != 0) {
    return false;
  }
  SmsSignal *other_sms_signal(other.getSmsSignal());
  if (other_sms_signal && sms_signal) {
    if (*other_sms_signal != *sms_signal)
      return false;
  } else if(other_sms_signal != 0 ||
            sms_signal != 0) {
    return false;
  }
  SourceAddrSubunit *other_source_addr_subunit(other.getSourceAddrSubunit());
  if (other_source_addr_subunit && source_addr_subunit) {
    if (*other_source_addr_subunit != *source_addr_subunit)
      return false;
  } else if(other_source_addr_subunit != 0 ||
            source_addr_subunit != 0) {
    return false;
  }
  SourceBearerType *other_source_bearer_type(other.getSourceBearerType());
  if (other_source_bearer_type && source_bearer_type) {
    if (*other_source_bearer_type != *source_bearer_type)
      return false;
  } else if(other_source_bearer_type != 0 ||
            source_bearer_type != 0) {
    return false;
  }
  SourceNetworkId *other_source_network_id(other.getSourceNetworkId());
  if (other_source_network_id && source_network_id) {
    if (*other_source_network_id != *source_network_id)
      return false;
  } else if(other_source_network_id != 0 ||
            source_network_id != 0) {
    return false;
  }
  SourceNetworkType *other_source_network_type(other.getSourceNetworkType());
  if (other_source_network_type && source_network_type) {
    if (*other_source_network_type != *source_network_type)
      return false;
  } else if(other_source_network_type != 0 ||
            source_network_type != 0) {
    return false;
  }
  SourceNodeId *other_source_node_id(other.getSourceNodeId());
  if (other_source_node_id && source_node_id) {
    if (*other_source_node_id != *source_node_id)
      return false;
  } else if(other_source_node_id != 0 ||
            source_node_id != 0) {
    return false;
  }
  SourcePort *other_source_port(other.getSourcePort());
  if (other_source_port && source_port) {
    if (*other_source_port != *source_port)
      return false;
  } else if(other_source_port != 0 ||
            source_port != 0) {
    return false;
  }
  SourceSubaddress *other_source_subaddress(other.getSourceSubaddress());
  if (other_source_subaddress && source_subaddress) {
    if (*other_source_subaddress != *source_subaddress)
      return false;
  } else if(other_source_subaddress != 0 ||
            source_subaddress != 0) {
    return false;
  }
  SourceTelematicsId *other_source_telematics_id(other.getSourceTelematicsId());
  if (other_source_telematics_id && source_telematics_id) {
    if (*other_source_telematics_id != *source_telematics_id)
      return false;
  } else if(other_source_telematics_id != 0 ||
            source_telematics_id != 0) {
    return false;
  }
  UserMessageReference *other_user_message_reference(
    other.getUserMessageReference());
  if (other_user_message_reference && user_message_reference) {
    if (*other_user_message_reference != *user_message_reference)
      return false;
  } else if(other_user_message_reference != 0 ||
            user_message_reference != 0) {
    return false;
  }
  UserResponseCode *other_user_response_code(other.getUserResponseCode());
  if (other_user_response_code && user_response_code) {
    if (*other_user_response_code != *user_response_code)
      return false;
  } else if(other_user_response_code != 0 ||
            user_response_code != 0) {
    return false;
  }
  UssdServiceOp *other_ussd_service_op(other.getUssdServiceOp());
  if (other_ussd_service_op && ussd_service_op) {
    if (*other_ussd_service_op != *ussd_service_op)
      return false;
  } else if(other_ussd_service_op != 0 ||
            ussd_service_op != 0) {
    return false;
  }
  return true;
}

bool MessageSubmissionRequestTLVs::operator !=(
  const MessageSubmissionRequestTLVs &other) const {
  return !this->operator ==(other);
}

MessageSubmissionRequestTLVs &MessageSubmissionRequestTLVs::operator =(
  const MessageSubmissionRequestTLVs &other) {
  setAlertOnMessageDelivery(other.getAlertOnMessageDelivery());
  setBillingIdentification(other.getBillingIdentification());
  setCallbackNum(other.getCallbackNum());
  setCallbackNumAtag(other.getCallbackNumAtag());
  setCallbackNumPresInd(other.getCallbackNumPresInd());
  setDestAddrNpCountry(other.getDestAddrNpCountry());
  setDestAddrNpInformation(other.getDestAddrNpInformation());
  setDestAddrNpResolution(other.getDestAddrNpResolution());
  setDestAddrSubunit(other.getDestAddrSubunit());
  setDestBearerType(other.getDestBearerType());
  setDestNetworkId(other.getDestNetworkId());
  setDestNetworkType(other.getDestNetworkType());
  setDestNodeId(other.getDestNodeId());
  setDestSubaddress(other.getDestSubaddress());
  setDestTelematicsId(other.getDestTelematicsId());
  setDestPort(other.getDestPort());
  setDisplayTime(other.getDisplayTime());
  setItsReplyType(other.getItsReplyType());
  setItsSessionInfo(other.getItsSessionInfo());
  setLanguageIndicator(other.getLanguageIndicator());
  setMessagePayload(other.getMessagePayload());
  setMoreMessagesToSend(other.getMoreMessagesToSend());
  setMsMsgWaitFacilities(other.getMsMsgWaitFacilities());
  setMsValidity(other.getMsValidity());
  setNumberOfMessages(other.getNumberOfMessages());
  setPayloadType(other.getPayloadType());
  setPrivacyIndicator(other.getPrivacyIndicator());
  setQosTimeToLive(other.getQosTimeToLive());
  setSarMsgRefNum(other.getSarMsgRefNum());
  setSarSegmentSeqnum(other.getSarSegmentSeqnum());
  setSarTotalSegments(other.getSarTotalSegments());
  setSetDpf(other.getSetDpf());
  setSmsSignal(other.getSmsSignal());
  setSourceAddrSubunit(other.getSourceAddrSubunit());
  setSourceBearerType(other.getSourceBearerType());
  setSourceNetworkId(other.getSourceNetworkId());
  setSourceNetworkType(other.getSourceNetworkType());
  setSourceNodeId(other.getSourceNodeId());
  setSourcePort(other.getSourcePort());
  setSourceSubaddress(other.getSourceSubaddress());
  setSourceTelematicsId(other.getSourceTelematicsId());
  setUserMessageReference(other.getUserMessageReference());
  setUserResponseCode(other.getUserResponseCode());
  setUssdServiceOp(other.getUssdServiceOp());
  return *this;
}

void MessageSubmissionRequestTLVs::setAlertOnMessageDelivery(
  const AlertOnMessageDelivery *alert_on_message_delivery) {
  if (this->alert_on_message_delivery && alert_on_message_delivery) {
    *(this->alert_on_message_delivery) = *alert_on_message_delivery;
  } else if (alert_on_message_delivery) {
    this->alert_on_message_delivery =
      new AlertOnMessageDelivery(*alert_on_message_delivery);
  } else if (this->alert_on_message_delivery) {
    delete this->alert_on_message_delivery;
    this->alert_on_message_delivery = 0;
  }
}

AlertOnMessageDelivery *
  MessageSubmissionRequestTLVs::getAlertOnMessageDelivery() const {
  return alert_on_message_delivery;
}

void MessageSubmissionRequestTLVs::setBillingIdentification(
  const BillingIdentification *billing_identification) {
  if (this->billing_identification && billing_identification) {
    *(this->billing_identification) = *billing_identification;
  } else if (billing_identification) {
    this->billing_identification =
      new BillingIdentification(*billing_identification);
  } else if (this->billing_identification) {
    delete this->billing_identification;
    this->billing_identification = 0;
  }
}

BillingIdentification *
  MessageSubmissionRequestTLVs::getBillingIdentification() const {
  return billing_identification;
}

void MessageSubmissionRequestTLVs::setCallbackNum(
  const CallbackNum *callback_num) {
  if (this->callback_num && callback_num) {
    *(this->callback_num) = *callback_num;
  } else if (callback_num) {
    this->callback_num =
      new CallbackNum(*callback_num);
  } else if (this->callback_num) {
    delete this->callback_num;
    this->callback_num = 0;
  }
}

CallbackNum *MessageSubmissionRequestTLVs::getCallbackNum() const {
  return callback_num;
}

void MessageSubmissionRequestTLVs::setCallbackNumAtag(
  const CallbackNumAtag *callback_num_atag) {
  if (this->callback_num_atag && callback_num_atag) {
    *(this->callback_num_atag) = *callback_num_atag;
  } else if (callback_num_atag) {
    this->callback_num_atag = new CallbackNumAtag(*callback_num_atag);
  } else if (this->callback_num_atag) {
    delete this->callback_num_atag;
    this->callback_num_atag = 0;
  }
}

CallbackNumAtag *MessageSubmissionRequestTLVs::getCallbackNumAtag() const {
  return callback_num_atag;
}

void MessageSubmissionRequestTLVs::setCallbackNumPresInd(
  const CallbackNumPresInd *callback_num_pres_ind) {
  if (this->callback_num_pres_ind && callback_num_pres_ind) {
    *(this->callback_num_pres_ind) = *callback_num_pres_ind;
  } else if (callback_num_pres_ind) {
    this->callback_num_pres_ind =
      new CallbackNumPresInd(*callback_num_pres_ind);
  } else if (this->callback_num_pres_ind) {
    delete this->callback_num_pres_ind;
    this->callback_num_pres_ind = 0;
  }
}

CallbackNumPresInd *
  MessageSubmissionRequestTLVs::getCallbackNumPresInd() const {
  return callback_num_pres_ind;
}

void MessageSubmissionRequestTLVs::setDestAddrNpCountry(
  const DestAddrNpCountry *dest_addr_np_country) {
  if (this->dest_addr_np_country && dest_addr_np_country) {
    *(this->dest_addr_np_country) = *dest_addr_np_country;
  } else if (dest_addr_np_country) {
    this->dest_addr_np_country =
      new DestAddrNpCountry(*dest_addr_np_country);
  } else if (this->dest_addr_np_country) {
    delete this->dest_addr_np_country;
    this->dest_addr_np_country = 0;
  }
}

DestAddrNpCountry *MessageSubmissionRequestTLVs::getDestAddrNpCountry() const {
  return dest_addr_np_country;
}


void MessageSubmissionRequestTLVs::setDestAddrNpInformation(
  const DestAddrNpInformation *dest_addr_np_information) {
  if (this->dest_addr_np_information && dest_addr_np_information) {
    *(this->dest_addr_np_information) = *dest_addr_np_information;
  } else if (dest_addr_np_information) {
    this->dest_addr_np_information =
      new DestAddrNpInformation(*dest_addr_np_information);
  } else if (this->dest_addr_np_information) {
    delete this->dest_addr_np_information;
    this->dest_addr_np_information = 0;
  }
}

DestAddrNpInformation *
  MessageSubmissionRequestTLVs::getDestAddrNpInformation() const {
  return dest_addr_np_information;
}

void MessageSubmissionRequestTLVs::setDestAddrNpResolution(
  const DestAddrNpResolution *dest_addr_np_resolution) {
  if (this->dest_addr_np_resolution && dest_addr_np_resolution) {
    *(this->dest_addr_np_resolution) = *dest_addr_np_resolution;
  } else if (dest_addr_np_resolution) {
    this->dest_addr_np_resolution =
      new DestAddrNpResolution(*dest_addr_np_resolution);
  } else if (this->dest_addr_np_resolution) {
    delete this->dest_addr_np_resolution;
    this->dest_addr_np_resolution = 0;
  }
}

DestAddrNpResolution *
  MessageSubmissionRequestTLVs::getDestAddrNpResolution() const {
  return dest_addr_np_resolution;
}

void MessageSubmissionRequestTLVs::setDestAddrSubunit(
  const DestAddrSubunit *dest_addr_subunit) {
  if (this->dest_addr_subunit && dest_addr_subunit) {
    *(this->dest_addr_subunit) = *dest_addr_subunit;
  } else if (dest_addr_subunit) {
    this->dest_addr_subunit = new DestAddrSubunit(*dest_addr_subunit);
  } else if (this->dest_addr_subunit) {
    delete this->dest_addr_subunit;
    this->dest_addr_subunit = 0;
  }
}

DestAddrSubunit *MessageSubmissionRequestTLVs::getDestAddrSubunit() const {
  return dest_addr_subunit;
}

void MessageSubmissionRequestTLVs::setDestBearerType(
  const DestBearerType *dest_bearer_type) {
  if (this->dest_bearer_type && dest_bearer_type) {
    *(this->dest_bearer_type) = *dest_bearer_type;
  } else if (dest_bearer_type) {
    this->dest_bearer_type = new DestBearerType(*dest_bearer_type);
  } else if (this->dest_bearer_type) {
    delete this->dest_bearer_type;
    this->dest_bearer_type = 0;
  }
}

DestBearerType *MessageSubmissionRequestTLVs::getDestBearerType() const {
  return dest_bearer_type;
}

void MessageSubmissionRequestTLVs::setDestNetworkId(
  const DestNetworkId *dest_network_id) {
  if (this->dest_network_id && dest_network_id) {
    *(this->dest_network_id) = *dest_network_id;
  } else if (dest_network_id) {
    this->dest_network_id = new DestNetworkId(*dest_network_id);
  } else if (this->dest_network_id) {
    delete this->dest_network_id;
    this->dest_network_id = 0;
  }
}

DestNetworkId *MessageSubmissionRequestTLVs::getDestNetworkId() const {
  return dest_network_id;
}

void MessageSubmissionRequestTLVs::setDestNetworkType(
  const DestNetworkType *dest_network_type) {
  if (this->dest_network_type && dest_network_type) {
    *(this->dest_network_type) = *dest_network_type;
  } else if (dest_network_type) {
    this->dest_network_type = new DestNetworkType(*dest_network_type);
  } else if (this->dest_network_type) {
    delete this->dest_network_type;
    this->dest_network_type = 0;
  }
}

DestNetworkType *MessageSubmissionRequestTLVs::getDestNetworkType() const {
  return dest_network_type;
}

void MessageSubmissionRequestTLVs::setDestNodeId(
  const DestNodeId *dest_node_id) {
  if (this->dest_node_id && dest_node_id) {
    *(this->dest_node_id) = *dest_node_id;
  } else if (dest_node_id) {
    this->dest_node_id = new DestNodeId(*dest_node_id);
  } else if (this->dest_node_id) {
    delete this->dest_node_id;
    this->dest_node_id = 0;
  }
}

DestNodeId *MessageSubmissionRequestTLVs::getDestNodeId() const {
  return dest_node_id;
}

void MessageSubmissionRequestTLVs::setDestSubaddress(
  const DestSubaddress *dest_subaddress) {
  if (this->dest_subaddress && dest_subaddress) {
    *(this->dest_subaddress) = *dest_subaddress;
  } else if (dest_subaddress) {
    this->dest_subaddress = new DestSubaddress(*dest_subaddress);
  } else if (this->dest_subaddress) {
    delete this->dest_subaddress;
    this->dest_subaddress = 0;
  }
}

DestSubaddress *MessageSubmissionRequestTLVs::getDestSubaddress() const {
  return dest_subaddress;
}

void MessageSubmissionRequestTLVs::setDestTelematicsId(
  const DestTelematicsId *dest_telematics_id) {
  if (this->dest_telematics_id && dest_telematics_id) {
    *(this->dest_telematics_id) = *dest_telematics_id;
  } else if (dest_telematics_id) {
    this->dest_telematics_id = new DestTelematicsId(*dest_telematics_id);
  } else if (this->dest_telematics_id) {
    delete this->dest_telematics_id;
    this->dest_telematics_id = 0;
  }
}

DestTelematicsId *MessageSubmissionRequestTLVs::getDestTelematicsId() const {
  return dest_telematics_id;
}

void MessageSubmissionRequestTLVs::setDestPort(const DestPort *dest_port) {
  if (this->dest_port && dest_port) {
    *(this->dest_port) = *dest_port;
  } else if (dest_port) {
    this->dest_port = new DestPort(*dest_port);
  } else if (this->dest_port) {
    delete this->dest_port;
    this->dest_port = 0;
  }
}

DestPort *MessageSubmissionRequestTLVs::getDestPort() const {
  return dest_port;
}

void MessageSubmissionRequestTLVs::setDisplayTime(
  const DisplayTime *display_time) {
  if (this->display_time && display_time) {
    *(this->display_time) = *display_time;
  } else if (display_time) {
    this->display_time = new DisplayTime(*display_time);
  } else if (this->display_time) {
    delete this->display_time;
    this->display_time = 0;
  }
}

DisplayTime *MessageSubmissionRequestTLVs::getDisplayTime() const {
  return display_time;
}

void MessageSubmissionRequestTLVs::setItsReplyType(
  const ItsReplyType *its_reply_type) {
  if (this->its_reply_type && its_reply_type) {
    *(this->its_reply_type) = *its_reply_type;
  } else if (its_reply_type) {
    this->its_reply_type = new ItsReplyType(*its_reply_type);
  } else if (this->its_reply_type) {
    delete this->its_reply_type;
    this->its_reply_type = 0;
  }
}

ItsReplyType *MessageSubmissionRequestTLVs::getItsReplyType() const {
  return its_reply_type;
}

void MessageSubmissionRequestTLVs::setItsSessionInfo(
  const ItsSessionInfo *its_session_info) {
  if (this->its_session_info && its_session_info) {
    *(this->its_session_info) = *its_session_info;
  } else if (its_session_info) {
    this->its_session_info = new ItsSessionInfo(*its_session_info);
  } else if (this->its_session_info) {
    delete this->its_session_info;
    this->its_session_info = 0;
  }
}

ItsSessionInfo *MessageSubmissionRequestTLVs::getItsSessionInfo() const {
  return its_session_info;
}

void MessageSubmissionRequestTLVs::setLanguageIndicator(
  const LanguageIndicator *language_indicator) {
  if (this->language_indicator && language_indicator) {
    *(this->language_indicator) = *language_indicator;
  } else if (language_indicator) {
    this->language_indicator = new LanguageIndicator(*language_indicator);
  } else if (this->language_indicator) {
    delete this->language_indicator;
    this->language_indicator = 0;
  }
}

LanguageIndicator *MessageSubmissionRequestTLVs::getLanguageIndicator() const {
  return language_indicator;
}

void MessageSubmissionRequestTLVs::setMessagePayload(
  const MessagePayload *message_payload) {
  if (this->message_payload && message_payload) {
    *(this->message_payload) = *message_payload;
  } else if (message_payload) {
    this->message_payload = new MessagePayload(*message_payload);
  } else if (this->message_payload) {
    delete this->message_payload;
    this->message_payload = 0;
  }
}

MessagePayload *MessageSubmissionRequestTLVs::getMessagePayload() const {
  return message_payload;
}

void MessageSubmissionRequestTLVs::setMoreMessagesToSend(
  const MoreMessagesToSend *more_messages_to_send) {
  if (this->more_messages_to_send && more_messages_to_send) {
    *(this->more_messages_to_send) = *more_messages_to_send;
  } else if (more_messages_to_send) {
    this->more_messages_to_send =
      new MoreMessagesToSend(*more_messages_to_send);
  } else if (this->more_messages_to_send) {
    delete this->more_messages_to_send;
    this->more_messages_to_send = 0;
  }
}

MoreMessagesToSend *
  MessageSubmissionRequestTLVs::getMoreMessagesToSend() const {
  return more_messages_to_send;
}

void MessageSubmissionRequestTLVs::setMsMsgWaitFacilities(
  const MsMsgWaitFacilities *ms_msg_wait_facilities) {
  if (this->ms_msg_wait_facilities && ms_msg_wait_facilities) {
    *(this->ms_msg_wait_facilities) = *ms_msg_wait_facilities;
  } else if (ms_msg_wait_facilities) {
    this->ms_msg_wait_facilities =
      new MsMsgWaitFacilities(*ms_msg_wait_facilities);
  } else if (this->ms_msg_wait_facilities) {
    delete this->ms_msg_wait_facilities;
    this->ms_msg_wait_facilities = 0;
  }
}

MsMsgWaitFacilities *
  MessageSubmissionRequestTLVs::getMsMsgWaitFacilities() const {
  return ms_msg_wait_facilities;
}

void MessageSubmissionRequestTLVs::setMsValidity(
  const MsValidity *ms_validity) {
  if (this->ms_validity && ms_validity) {
    *(this->ms_validity) = *ms_validity;
  } else if (ms_validity) {
    this->ms_validity = new MsValidity(*ms_validity);
  } else if (this->ms_validity) {
    delete this->ms_validity;
    this->ms_validity = 0;
  }
}

MsValidity *MessageSubmissionRequestTLVs::getMsValidity() const {
  return ms_validity;
}

void MessageSubmissionRequestTLVs::setNumberOfMessages(
  const NumberOfMessages *number_of_messages) {
  if (this->number_of_messages && number_of_messages) {
    *(this->number_of_messages) = *number_of_messages;
  } else if (number_of_messages) {
    this->number_of_messages = new NumberOfMessages(*number_of_messages);
  } else if (this->number_of_messages) {
    delete this->number_of_messages;
    this->number_of_messages = 0;
  }
}

NumberOfMessages *MessageSubmissionRequestTLVs::getNumberOfMessages() const {
  return number_of_messages;
}

void MessageSubmissionRequestTLVs::setPayloadType(
  const PayloadType *payload_type) {
  if (this->payload_type && payload_type) {
    *(this->payload_type) = *payload_type;
  } else if (payload_type) {
    this->payload_type = new PayloadType(*payload_type);
  } else if (this->payload_type) {
    delete this->payload_type;
    this->payload_type = 0;
  }
}

PayloadType *MessageSubmissionRequestTLVs::getPayloadType() const {
  return payload_type;
}

void MessageSubmissionRequestTLVs::setPrivacyIndicator(
  const PrivacyIndicator *privacy_indicator) {
  if (this->privacy_indicator && privacy_indicator) {
    *(this->privacy_indicator) = *privacy_indicator;
  } else if (privacy_indicator) {
    this->privacy_indicator = new PrivacyIndicator(*privacy_indicator);
  } else if (this->privacy_indicator) {
    delete this->privacy_indicator;
    this->privacy_indicator = 0;
  }
}

PrivacyIndicator *MessageSubmissionRequestTLVs::getPrivacyIndicator() const {
  return privacy_indicator;
}

void MessageSubmissionRequestTLVs::setQosTimeToLive(
  const QosTimeToLive *qos_time_to_live) {
  if (this->qos_time_to_live && qos_time_to_live) {
    *(this->qos_time_to_live) = *qos_time_to_live;
  } else if (qos_time_to_live) {
    this->qos_time_to_live = new QosTimeToLive(*qos_time_to_live);
  } else if (this->qos_time_to_live) {
    delete this->qos_time_to_live;
    this->qos_time_to_live = 0;
  }
}

QosTimeToLive *MessageSubmissionRequestTLVs::getQosTimeToLive() const {
  return qos_time_to_live;
}

void MessageSubmissionRequestTLVs::setSarMsgRefNum(
  const SarMsgRefNum *sar_msg_ref_num) {
  if (this->sar_msg_ref_num && sar_msg_ref_num) {
    *(this->sar_msg_ref_num) = *sar_msg_ref_num;
  } else if (sar_msg_ref_num) {
    this->sar_msg_ref_num = new SarMsgRefNum(*sar_msg_ref_num);
  } else if (this->sar_msg_ref_num) {
    delete this->sar_msg_ref_num;
    this->sar_msg_ref_num = 0;
  }
}

SarMsgRefNum *MessageSubmissionRequestTLVs::getSarMsgRefNum() const {
  return sar_msg_ref_num;
}

void MessageSubmissionRequestTLVs::setSarSegmentSeqnum(
  const SarSegmentSeqnum *sar_segment_seqnum) {
  if (this->sar_segment_seqnum && sar_segment_seqnum) {
    *(this->sar_segment_seqnum) = *sar_segment_seqnum;
  } else if (sar_segment_seqnum) {
    this->sar_segment_seqnum = new SarSegmentSeqnum(*sar_segment_seqnum);
  } else if (this->sar_segment_seqnum) {
    delete this->sar_segment_seqnum;
    this->sar_segment_seqnum = 0;
  }
}

SarSegmentSeqnum *MessageSubmissionRequestTLVs::getSarSegmentSeqnum() const {
  return sar_segment_seqnum;
}

void MessageSubmissionRequestTLVs::setSarTotalSegments(
  const SarTotalSegments *sar_total_segments) {
  if (this->sar_total_segments && sar_total_segments) {
    *(this->sar_total_segments) = *sar_total_segments;
  } else if (sar_total_segments) {
    this->sar_total_segments = new SarTotalSegments(*sar_total_segments);
  } else if (this->sar_total_segments) {
    delete this->sar_total_segments;
    this->sar_total_segments = 0;
  }
}

SarTotalSegments *MessageSubmissionRequestTLVs::getSarTotalSegments() const {
  return sar_total_segments;
}

void MessageSubmissionRequestTLVs::setSetDpf(const SetDpf *set_dpf) {
  if (this->set_dpf && set_dpf) {
    *(this->set_dpf) = *set_dpf;
  } else if (set_dpf) {
    this->set_dpf = new SetDpf(*set_dpf);
  } else if (this->set_dpf) {
    delete this->set_dpf;
    this->set_dpf = 0;
  }
}

SetDpf *MessageSubmissionRequestTLVs::getSetDpf() const {
  return set_dpf;
}

void MessageSubmissionRequestTLVs::setSmsSignal(const SmsSignal *sms_signal) {
  if (this->sms_signal && sms_signal) {
    *(this->sms_signal) = *sms_signal;
  } else if (sms_signal) {
    this->sms_signal = new SmsSignal(*sms_signal);
  } else if (this->sms_signal) {
    delete this->sms_signal;
    this->sms_signal = 0;
  }
}

SmsSignal *MessageSubmissionRequestTLVs::getSmsSignal() const {
  return sms_signal;
}

void MessageSubmissionRequestTLVs::setSourceAddrSubunit(
  const SourceAddrSubunit *source_addr_subunit) {
  if (this->source_addr_subunit && source_addr_subunit) {
    *(this->source_addr_subunit) = *source_addr_subunit;
  } else if (source_addr_subunit) {
    this->source_addr_subunit = new SourceAddrSubunit(*source_addr_subunit);
  } else if (this->source_addr_subunit) {
    delete this->source_addr_subunit;
    this->source_addr_subunit = 0;
  }
}

SourceAddrSubunit *MessageSubmissionRequestTLVs::getSourceAddrSubunit() const {
  return source_addr_subunit;
}

void MessageSubmissionRequestTLVs::setSourceBearerType(
  const SourceBearerType *source_bearer_type) {
  if (this->source_bearer_type && source_bearer_type) {
    *(this->source_bearer_type) = *source_bearer_type;
  } else if (source_bearer_type) {
    this->source_bearer_type = new SourceBearerType(*source_bearer_type);
  } else if (this->source_bearer_type) {
    delete this->source_bearer_type;
    this->source_bearer_type = 0;
  }
}

SourceBearerType *MessageSubmissionRequestTLVs::getSourceBearerType() const {
  return source_bearer_type;
}

void MessageSubmissionRequestTLVs::setSourceNetworkId(
  const SourceNetworkId *source_network_id) {
  if (this->source_network_id && source_network_id) {
    *(this->source_network_id) = *source_network_id;
  } else if (source_network_id) {
    this->source_network_id = new SourceNetworkId(*source_network_id);
  } else if (this->source_network_id) {
    delete this->source_network_id;
    this->source_network_id = 0;
  }
}

SourceNetworkId *MessageSubmissionRequestTLVs::getSourceNetworkId() const {
  return source_network_id;
}

void MessageSubmissionRequestTLVs::setSourceNetworkType(
  const SourceNetworkType *source_network_type) {
  if (this->source_network_type && source_network_type) {
    *(this->source_network_type) = *source_network_type;
  } else if (source_network_type) {
    this->source_network_type = new SourceNetworkType(*source_network_type);
  } else if (this->source_network_type) {
    delete this->source_network_type;
    this->source_network_type = 0;
  }
}

SourceNetworkType *MessageSubmissionRequestTLVs::getSourceNetworkType() const {
  return source_network_type;
}


void MessageSubmissionRequestTLVs::setSourceNodeId(
  const SourceNodeId *source_node_id) {
  if (this->source_node_id && source_node_id) {
    *(this->source_node_id) = *source_node_id;
  } else if (source_node_id) {
    this->source_node_id = new SourceNodeId(*source_node_id);
  } else if (this->source_node_id) {
    delete this->source_node_id;
    this->source_node_id = 0;
  }
}

SourceNodeId *MessageSubmissionRequestTLVs::getSourceNodeId() const {
  return source_node_id;
}

void MessageSubmissionRequestTLVs::setSourcePort(
  const SourcePort *source_port) {
  if (this->source_port && source_port) {
    *(this->source_port) = *source_port;
  } else if (source_port) {
    this->source_port = new SourcePort(*source_port);
  } else if (this->source_port) {
    delete this->source_port;
    this->source_port = 0;
  }
}

SourcePort *MessageSubmissionRequestTLVs::getSourcePort() const {
  return source_port;
}

void MessageSubmissionRequestTLVs::setSourceSubaddress(
  const SourceSubaddress *source_subaddress) {
  if (this->source_subaddress && source_subaddress) {
    *(this->source_subaddress) = *source_subaddress;
  } else if (source_subaddress) {
    this->source_subaddress = new SourceSubaddress(*source_subaddress);
  } else if (this->source_subaddress) {
    delete this->source_subaddress;
    this->source_subaddress = 0;
  }
}

SourceSubaddress *MessageSubmissionRequestTLVs::getSourceSubaddress() const {
  return source_subaddress;
}

void MessageSubmissionRequestTLVs::setSourceTelematicsId(
  const SourceTelematicsId *source_telematics_id) {
  if (this->source_telematics_id && source_telematics_id) {
    *(this->source_telematics_id) = *source_telematics_id;
  } else if (source_telematics_id) {
    this->source_telematics_id = new SourceTelematicsId(*source_telematics_id);
  } else if (this->source_telematics_id) {
    delete this->source_telematics_id;
    this->source_telematics_id = 0;
  }
}

SourceTelematicsId *
  MessageSubmissionRequestTLVs::getSourceTelematicsId() const {
  return source_telematics_id;
}

void MessageSubmissionRequestTLVs::setUserMessageReference(
  const UserMessageReference *user_message_reference) {
  if (this->user_message_reference && user_message_reference) {
    *(this->user_message_reference) = *user_message_reference;
  } else if (user_message_reference) {
    this->user_message_reference =
      new UserMessageReference(*user_message_reference);
  } else if (this->user_message_reference) {
    delete this->user_message_reference;
    this->user_message_reference = 0;
  }
}

UserMessageReference *
  MessageSubmissionRequestTLVs::getUserMessageReference() const {
  return user_message_reference;
}

void MessageSubmissionRequestTLVs::setUserResponseCode(
  const UserResponseCode *user_response_code) {
  if (this->user_response_code && user_response_code) {
    *(this->user_response_code) = *user_response_code;
  } else if (user_response_code) {
    this->user_response_code = new UserResponseCode(*user_response_code);
  } else if (this->user_response_code) {
    delete this->user_response_code;
    this->user_response_code = 0;
  }
}

UserResponseCode *MessageSubmissionRequestTLVs::getUserResponseCode() const {
  return user_response_code;
}

void MessageSubmissionRequestTLVs::setUssdServiceOp(
  const UssdServiceOp *ussd_service_op) {
  if (this->ussd_service_op && ussd_service_op) {
    *(this->ussd_service_op) = *ussd_service_op;
  } else if (ussd_service_op) {
    this->ussd_service_op = new UssdServiceOp(*ussd_service_op);
  } else if (this->ussd_service_op) {
    delete this->ussd_service_op;
    this->ussd_service_op = 0;
  }
}

UssdServiceOp *MessageSubmissionRequestTLVs::getUssdServiceOp() const {
  return ussd_service_op;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
