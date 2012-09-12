#ifndef SMPP_TLV_H
#define SMPP_TLV_H

#include <types.h>

namespace smpp {

class Tlv {
  uint16 tag;
  uint16 length;
  const uint8 *value;

  uint8* buildValue(const uint16 &l, const uint8 *v) {
    uint8 *t(new uint8[l]);
    std::copy(v, v + l, t);
    return t;
  }
public:
  enum {
    dest_addr_subunit            = 0x0005,
    dest_network_type            = 0x0006,
    dest_bearer_type             = 0x0007,
    dest_telematics_id           = 0x0008,
    source_addr_subunit          = 0x000D,
    source_network_type          = 0x000E,
    source_bearer_type           = 0x000F,
    source_telematics_id         = 0x0010,
    qos_time_to_live             = 0x0017,
    payload_type                 = 0x0019,
    additional_status_info_text  = 0x001D,
    receipted_message_id         = 0x001E,
    ms_msg_wait_facilities       = 0x0030,
    privacy_indicator            = 0x0201,
    source_subaddress            = 0x0202,
    dest_subaddress              = 0x0203,
    user_message_reference       = 0x0204,
    user_response_code           = 0x0205,
    source_port                  = 0x020A,
    dest_port                    = 0x020B,
    sar_msg_ref_num              = 0x020C,
    language_indicator           = 0x020D,
    sar_total_segments           = 0x020E,
    sar_segment_seqnum           = 0x020F,
    sc_interface_version         = 0x0210,
    callback_num_pres_ind        = 0x0302,
    callback_num_atag            = 0x0303,
    number_of_messages           = 0x0304,
    callback_num                 = 0x0381,
    dpf_result                   = 0x0420,
    set_dpf                      = 0x0421,
    ms_availability_status       = 0x0422,
    network_error_code           = 0x0423,
    message_payload              = 0x0424,
    delivery_failure_reason      = 0x0425,
    more_messages_to_send        = 0x0426,
    message_state                = 0x0427,
    congestion_state             = 0x0428,
    ussd_service_op              = 0x0501,
    broadcast_channel_indicator  = 0x0600,
    broadcast_content_type       = 0x0601,
    broadcast_content_type_info  = 0x0602,
    broadcast_message_class      = 0x0603,
    broadcast_rep_num            = 0x0604,
    broadcast_frequency_interval = 0x0605,
    broadcast_area_identifier    = 0x0606,
    broadcast_Error_status       = 0x0607,
    broadcast_area_success       = 0x0608,
    broadcast_end_time           = 0x0609,
    broadcast_service_group      = 0x060A,
    billing_identification       = 0x060B,
    source_network_id            = 0x060D,
    dest_network_id              = 0x060E,
    source_node_id               = 0x060F,
    dest_node_id                 = 0x0610,
    dest_addr_np_resolution      = 0x0611,
    dest_addr_np_information     = 0x0612,
    dest_addr_np_country         = 0x0613,
    display_time                 = 0x1201,
    sms_signal                   = 0x1203,
    ms_validity                  = 0x1204,
    alert_on_message_delivery    = 0x130C,
    its_reply_type               = 0x1380,
    its_session_info             = 0x1383
  };

public:
  Tlv() : tag(0), length(0), value(0) {}

  Tlv(const Tlv &tlv) :
      tag(tlv.tag),
      length(tlv.length),
      value(buildValue(tlv.length, tlv.value)) {
  }

  Tlv(const uint16 &t, const uint16 &l, const uint8 *v) :
    tag(t), length(l), value(buildValue(l, v)) {
  }

  virtual ~Tlv() { delete [] value; }

  Tlv &operator =(const Tlv &other) {
    if(this == &other)
      return *this;

    tag = other.tag;
    length = other.length;
    value = buildValue(other.length, other.value);
  }

  bool operator==(const uint16 &tag) const { return this->tag == tag; }

  operator bool() const { return tag != 0; }

  uint16 getTag() const { return tag; }

  uint16 getLength() const { return length; }

  const uint8* getValue() const { return value; }

  class CompareTag {
    const uint16 &tag;
  public:
    CompareTag(const uint16 &tag) : tag(tag) {}
    bool operator()(const Tlv *p) const {
      return p->getTag() == tag;
    }
  };

protected:
  Tlv(const uint16 &t,
      const uint16 &l,
      const uint8 *v,
      int x) :
    tag(t), length(l), value(v) {
  }
};

} // namespace smpp

#endif // TLV_H
