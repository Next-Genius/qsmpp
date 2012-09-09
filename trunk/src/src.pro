TEMPLATE = lib

QT -= gui
QT += core network

#VERSION = 1.0.0

CONFIG(debug, debug|release) {
  TARGET = qsmppd
  OBJECTS_DIR = $${OUT_PWD}/tmp/obj/debug
  MOC_DIR = $${OUT_PWD}/tmp/moc/debug
} else {
  TARGET = qsmpp
  OBJECTS_DIR = $${OUT_PWD}/tmp/obj/release
  MOC_DIR = $${OUT_PWD}/tmp/moc/release
}

PRECOMPILED_HEADER  = global.h

INCLUDEPATH += $$PWD

DEFINES += QSMPP_LIBRARY QSMPP_VERSION=\\\"$$QSMPP_VERSION\\\"

win32: DLLDESTDIR = ../lib

HEADERS += \
    global.h \
    header.h \
    constants.h \
    bind.h \
    tlv.h \
    sc_interface_version.h \
    bind_resp.h \
    outbind.h \
    ms_availability_status.h \
    additional_status_info_text.h \
    alert_on_message_delivery.h \
    billing_identification.h \
    broadcast_area_identifier.h \
    broadcast_end_time.h \
    broadcast_content_type_info.h \
    broadcast_content_type.h \
    broadcast_channel_indicator.h \
    broadcast_area_success.h \
    broadcast_service_group.h \
    broadcast_rep_num.h \
    broadcast_message_class.h \
    broadcast_frequency_interval.h \
    broadcast_error_status.h \
    callback_num.h \
    callback_num_atag.h \
    callback_num_pres_ind.h \
    congestion_state.h \
    delivery_failure_reason.h \
    dest_addr_np_country.h \
    dest_addr_np_information.h \
    dest_addr_np_resolution.h \
    dest_addr_subunit.h \
    dest_bearer_type.h \
    dest_network_id.h \
    dest_network_type.h \
    dest_node_id.h \
    dest_subaddress.h \
    dest_telematics_id.h \
    dest_port.h \
    display_time.h \
    dpf_result.h \
    its_reply_type.h \
    its_session_info.h \
    language_indicator.h \
    message_payload.h \
    message_state.h \
    more_messages_to_send.h \
    ms_msg_wait_facilities.h \
    ms_validity.h \
    network_error_code.h \
    number_of_messages.h \
    payload_type.h \
    privacy_indicator.h \
    qos_time_to_live.h \
    receipted_message_id.h \
    sar_msg_ref_num.h \
    sar_segment_seqnum.h \
    sar_total_segments.h \
    set_dpf.h \
    sms_signal.h \
    source_addr_subunit.h \
    source_bearer_type.h \
    source_network_id.h \
    source_network_type.h \
    source_node_id.h \
    source_port.h \
    source_subaddress.h \
    source_telematics_id.h \
    user_message_reference.h \
    user_response_code.h \
    ussd_service_op.h \
    submit_sm.h \
    submit_sm_resp.h \
    data_sm.h \
    data_sm_resp.h \
    submit_multi.h \
    submit_multi_resp.h \
    message_submission_request_tlvs.h \
    message_submission_response_tlvs.h \
    deliver_sm.h \
    deliver_sm_resp.h \
    broadcast_sm.h \
    broadcast_sm_resp.h \
    cancel_sm.h \
    query_sm.h \
    query_sm_resp.h \
    replace_sm.h \
    query_broadcast_sm.h \
    query_broadcast_sm_resp.h \
    cancel_broadcast_sm.h

SOURCES += \
    header.cpp \
    bind.cpp \
    tlv.cpp \
    sc_interface_version.cpp \
    bind_resp.cpp \
    outbind.cpp \
    ms_availability_status.cpp \
    additional_status_info_text.cpp \
    alert_on_message_delivery.cpp \
    billing_identification.cpp \
    broadcast_area_identifier.cpp \
    broadcast_end_time.cpp \
    broadcast_content_type_info.cpp \
    broadcast_content_type.cpp \
    broadcast_channel_indicator.cpp \
    broadcast_area_success.cpp \
    broadcast_service_group.cpp \
    broadcast_rep_num.cpp \
    broadcast_message_class.cpp \
    broadcast_frequency_interval.cpp \
    broadcast_error_status.cpp \
    callback_num.cpp \
    callback_num_atag.cpp \
    callback_num_pres_ind.cpp \
    congestion_state.cpp \
    delivery_failure_reason.cpp \
    dest_addr_np_country.cpp \
    dest_addr_np_information.cpp \
    dest_addr_np_resolution.cpp \
    dest_addr_subunit.cpp \
    dest_bearer_type.cpp \
    dest_network_id.cpp \
    dest_network_type.cpp \
    dest_node_id.cpp \
    dest_subaddress.cpp \
    dest_telematics_id.cpp \
    dest_port.cpp \
    display_time.cpp \
    dpf_result.cpp \
    its_reply_type.cpp \
    its_session_info.cpp \
    language_indicator.cpp \
    message_payload.cpp \
    message_state.cpp \
    more_messages_to_send.cpp \
    ms_msg_wait_facilities.cpp \
    ms_validity.cpp \
    network_error_code.cpp \
    number_of_messages.cpp \
    payload_type.cpp \
    privacy_indicator.cpp \
    qos_time_to_live.cpp \
    receipted_message_id.cpp \
    sar_msg_ref_num.cpp \
    sar_segment_seqnum.cpp \
    sar_total_segments.cpp \
    set_dpf.cpp \
    sms_signal.cpp \
    source_addr_subunit.cpp \
    source_bearer_type.cpp \
    source_network_id.cpp \
    source_network_type.cpp \
    source_node_id.cpp \
    source_port.cpp \
    source_subaddress.cpp \
    source_telematics_id.cpp \
    user_message_reference.cpp \
    user_response_code.cpp \
    ussd_service_op.cpp \
    submit_sm.cpp \
    submit_sm_resp.cpp \
    data_sm.cpp \
    data_sm_resp.cpp \
    submit_multi.cpp \
    submit_multi_resp.cpp \
    message_submission_request_tlvs.cpp \
    message_submission_response_tlvs.cpp \
    deliver_sm.cpp \
    deliver_sm_resp.cpp \
    broadcast_sm_resp.cpp \
    broadcast_sm.cpp \
    cancel_sm.cpp \
    query_sm.cpp \
    query_sm_resp.cpp \
    replace_sm.cpp \
    query_broadcast_sm.cpp \
    query_broadcast_sm_resp.cpp
