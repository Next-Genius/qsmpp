#ifndef SMPP_TLV_H
#define SMPP_TLV_H

#include <types.h>

namespace smpp {

class Tlv {
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

private:
  smpp::uint16 tag;
  smpp::uint16 length;
  const smpp::uint8* value;

  smpp::uint8* buildValue(const smpp::uint16 &l, const smpp::uint8 *v) {
    smpp::uint8 *t(new smpp::uint8[l]);
    std::copy(v, v + l, t);
    return t;
  }

public:
  Tlv() : tag(0), length(0), value(0) {}

  Tlv(const Tlv &tlv) :
      tag(tlv.tag),
      length(tlv.length),
      value(buildValue(tlv.value, tlv.value)) {
  }

  Tlv(const smpp::uint16 &t, const smpp::uint16 &l, const smpp::uint8 *v) :
    tag(t), length(l), value(buildValue(l, v)) {
  }

  virtual ~Tlv() { delete [] value; }

  Tlv& operator =(const Tlv &rhs) {
    if(this == &rhs)
      return *this;

    tag_ = rhs.tag_;
    length_ = rhs.length_;
    value_ = build_value(rhs.length_, rhs.value_);
  }

  bool operator==(const smpp::uint16& tag) const { return tag == tag_; }

  operator bool() const { return tag_ != 0; }

  smpp::uint16 tag() const { return tag_; }

  smpp::uint16 length() const { return length_; }

  const smpp::uint8* value() const { return value_; }

  class CompareTag {
      const smpp::uint16& tag_;
    public:
      CompareTag(const smpp::uint16& tag) : tag_(tag) {}
      bool operator()(const Tlv* p) const {
          return p->tag() == tag_;
      }
  };

protected:
  Tlv(const smpp::uint16 &t,
      const smpp::uint16 &l,
      const smpp::uint8* v) :
      tag_(t), length_(l), value_(v) {
  }
};

} // namespace smpp

#endif // TLV_H
