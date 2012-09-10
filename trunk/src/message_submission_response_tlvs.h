#ifndef QSMPP_MESSAGE_SUBMISSION_RESPONSE_TLVS_H
#define QSMPP_MESSAGE_SUBMISSION_RESPONSE_TLVS_H

#include <additional_status_info_text.h>
#include <delivery_failure_reason.h>
#include <dpf_result.h>
#include <network_error_code.h>
#include <congestion_state.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

class QSMPP_EXPORT MessageSubmissionResponseTLVs {
public:
  MessageSubmissionResponseTLVs(
    const AdditionalStatusInfoText *additional_status_info_text = 0,
    const DeliveryFailureReason *delivery_failure_reason = 0,
    const DpfResult *dpf_result = 0,
    const NetworkErrorCode *network_error_code = 0);

  MessageSubmissionResponseTLVs(const MessageSubmissionResponseTLVs &other);

  ~MessageSubmissionResponseTLVs();

  bool operator ==(const MessageSubmissionResponseTLVs &other) const;

  bool operator !=(const MessageSubmissionResponseTLVs &other) const;

  MessageSubmissionResponseTLVs &operator =(
    const MessageSubmissionResponseTLVs &other);

  void setAdditionalStatusInfoText(
    const AdditionalStatusInfoText *additional_status_info_text);

  AdditionalStatusInfoText *getAdditionalStatusInfoText() const;

  void setDeliveryFailureReason(
    const DeliveryFailureReason *delivery_failure_reason);

  DeliveryFailureReason *getDeliveryFailureReason() const;

  void setDpfResult(const DpfResult *dpf_result);

  DpfResult *getDpfResult() const;

  void setNetworkErrorCode(const NetworkErrorCode *network_error_code);

  NetworkErrorCode *getNetworkErrorCode() const;

protected:
  AdditionalStatusInfoText *additional_status_info_text;
  DeliveryFailureReason *delivery_failure_reason;
  DpfResult *dpf_result;
  NetworkErrorCode *network_error_code;
};

} // namespace tlv
} // namespace pdu
} // namespace qsmpp

#endif // QSMPP_MESSAGE_SUBMISSION_RESPONSE_TLVS_H
