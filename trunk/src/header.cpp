#include <header.h>

namespace smpp {

Header::Header(const CommandLength &command_length,
               const CommandId &command_id,
               const CommandStatus &command_status,
               const SequenceNumber &sequence_number) :
  command_length(command_length),
  command_id(command_id),
  command_status(command_status),
  sequence_number(sequence_number) {

}

TlvsHeader::TlvsHeader(const CommandLength &command_length,
                       const CommandId &command_id,
                       const CommandStatus &command_status,
                       const SequenceNumber &sequence_number) :
  Header(command_length,
         command_id,
         command_status,
         sequence_number) {

}

void TlvsHeader::insertAfterTlv(const Tlv *tlv, uint16 tag) {
  TlvList::reverse_iterator i;
  i = std::find_if(tlvs.list.rbegin(),
                   tlvs.list.rend(),
                   Tlv::CompareTag(tag));
//  if(i == tlvs.list.rend())
//    throw Error("Missing mandatory TLV");
  tlvs.list.insert(i.base(), tlv);
  updateLength(tlv->getLength() + 4);
}

void TlvsHeader::insertBeforeTlv(const Tlv *tlv, uint16 tag) {
  TlvList::iterator i;
  i = std::find_if(tlvs.list.begin(),
                   tlvs.list.end(),
                   Tlv::CompareTag(tag));
  //if(i == tlvs.list.end())
  //    throw Error("Missing mandatory TLV");
  tlvs.list.insert(i, tlv);
  updateLength(tlv->getLength() + 4);
}

} // namespace smpp
