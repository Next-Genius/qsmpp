#include <message_submission_response_tlvs.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

MessageSubmissionResponseTLVs::MessageSubmissionResponseTLVs(
  const AdditionalStatusInfoText *additional_status_info_text,
  const DeliveryFailureReason *delivery_failure_reason,
  const DpfResult *dpf_result,
  const NetworkErrorCode *network_error_code):
    additional_status_info_text(0),
    delivery_failure_reason(0),
    dpf_result(0),
    network_error_code(0) {
  if(additional_status_info_text)
    this->additional_status_info_text =
      new AdditionalStatusInfoText(*additional_status_info_text);
  if(delivery_failure_reason)
    this->delivery_failure_reason =
      new DeliveryFailureReason(*delivery_failure_reason);
  if(dpf_result)
    this->dpf_result = new DpfResult(*dpf_result);
  if(network_error_code)
    this->network_error_code = new NetworkErrorCode(*network_error_code);
}

MessageSubmissionResponseTLVs::MessageSubmissionResponseTLVs(
  const MessageSubmissionResponseTLVs &other):
    additional_status_info_text(0),
    delivery_failure_reason(0),
    dpf_result(0),
    network_error_code(0) {
  if(other.getAdditionalStatusInfoText())
    additional_status_info_text =
      new AdditionalStatusInfoText(*other.getAdditionalStatusInfoText());
  if(other.getDeliveryFailureReason())
    delivery_failure_reason =
      new DeliveryFailureReason(*other.getDeliveryFailureReason());
  if(other.getDpfResult())
    dpf_result = new DpfResult(*other.getDpfResult());
  if(other.getNetworkErrorCode())
    network_error_code = new NetworkErrorCode(*other.getNetworkErrorCode());
}

MessageSubmissionResponseTLVs::~MessageSubmissionResponseTLVs() {
  if(additional_status_info_text)
    delete additional_status_info_text;
  if(delivery_failure_reason)
    delete delivery_failure_reason;
  if(dpf_result)
    delete dpf_result;
  if(network_error_code)
    delete network_error_code;
}

bool MessageSubmissionResponseTLVs::operator ==(
  const MessageSubmissionResponseTLVs &other) const {
  AdditionalStatusInfoText *other_additional_status_info_text(
    other.getAdditionalStatusInfoText());
  if (other_additional_status_info_text && additional_status_info_text) {
    if (*other_additional_status_info_text != *additional_status_info_text)
      return false;
  } else if(other_additional_status_info_text != 0 ||
            additional_status_info_text != 0) {
    return false;
  }
  DeliveryFailureReason *other_delivery_failure_reason(
    other.getDeliveryFailureReason());
  if (other_delivery_failure_reason && delivery_failure_reason) {
    if (*other_delivery_failure_reason != *delivery_failure_reason)
      return false;
  } else if(other_delivery_failure_reason != 0 ||
            delivery_failure_reason != 0) {
    return false;
  }
  DpfResult *other_dpf_result(other.getDpfResult());
  if (other_dpf_result && dpf_result) {
    if (*other_dpf_result != *dpf_result)
      return false;
  } else if(other_dpf_result != 0 ||
            dpf_result != 0) {
    return false;
  }
  NetworkErrorCode *other_network_error_code(other.getNetworkErrorCode());
  if (other_network_error_code && network_error_code) {
    if (*other_network_error_code != *network_error_code)
      return false;
  } else if(other_network_error_code != 0 ||
            network_error_code != 0) {
    return false;
  }
  return true;
}

bool MessageSubmissionResponseTLVs::operator !=(
  const MessageSubmissionResponseTLVs &other) const {
  return !this->operator ==(other);
}

MessageSubmissionResponseTLVs &MessageSubmissionResponseTLVs::operator =(
  const MessageSubmissionResponseTLVs &other) {
  setAdditionalStatusInfoText(other.getAdditionalStatusInfoText());
  setDeliveryFailureReason(other.getDeliveryFailureReason());
  setDpfResult(other.getDpfResult());
  setNetworkErrorCode(other.getNetworkErrorCode());
  return *this;
}

void MessageSubmissionResponseTLVs::setAdditionalStatusInfoText(
  const AdditionalStatusInfoText *additional_status_info_text) {
  if (this->additional_status_info_text && additional_status_info_text) {
    *(this->additional_status_info_text) = *additional_status_info_text;
  } else if (additional_status_info_text) {
    this->additional_status_info_text =
      new AdditionalStatusInfoText(*additional_status_info_text);
  } else if (this->additional_status_info_text) {
    delete this->additional_status_info_text;
    this->additional_status_info_text = 0;
  }
}

AdditionalStatusInfoText *
  MessageSubmissionResponseTLVs::getAdditionalStatusInfoText() const {
  return additional_status_info_text;
}

void MessageSubmissionResponseTLVs::setDeliveryFailureReason(
  const DeliveryFailureReason *delivery_failure_reason) {
  if (this->delivery_failure_reason && delivery_failure_reason) {
    *(this->delivery_failure_reason) = *delivery_failure_reason;
  } else if (delivery_failure_reason) {
    this->delivery_failure_reason =
      new DeliveryFailureReason(*delivery_failure_reason);
  } else if (this->delivery_failure_reason) {
    delete this->delivery_failure_reason;
    this->delivery_failure_reason = 0;
  }
}

DeliveryFailureReason *
  MessageSubmissionResponseTLVs::getDeliveryFailureReason() const {
  return delivery_failure_reason;
}

void MessageSubmissionResponseTLVs::setDpfResult(const DpfResult *dpf_result) {
  if (this->dpf_result && dpf_result) {
    *(this->dpf_result) = *dpf_result;
  } else if (dpf_result) {
    this->dpf_result = new DpfResult(*dpf_result);
  } else if (this->dpf_result) {
    delete this->dpf_result;
    this->dpf_result = 0;
  }
}

DpfResult *MessageSubmissionResponseTLVs::getDpfResult() const {
  return dpf_result;
}

void MessageSubmissionResponseTLVs::setNetworkErrorCode(
  const NetworkErrorCode *network_error_code) {
  if (this->network_error_code && network_error_code) {
    *(this->network_error_code) = *network_error_code;
  } else if (network_error_code) {
    this->network_error_code = new NetworkErrorCode(*network_error_code);
  } else if (this->network_error_code) {
    delete this->network_error_code;
    this->network_error_code = 0;
  }
}

NetworkErrorCode *MessageSubmissionResponseTLVs::getNetworkErrorCode() const {
  return network_error_code;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
