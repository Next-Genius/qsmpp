#include <header.h>

using namespace qsmpp::pdu;

Header::Header(const quint32 nCommandLength,const quint32 nCommandId,
const quint32 nCommandStatus, const quint32 nSequenceNumber):
_CommandLength(nCommandLength),
_CommandId(nCommandId),
_CommandStatus(nCommandStatus),
_SequenceNumber(nSequenceNumber){}

Header::Header(const Header &nHeader):
_CommandLength(nHeader.getCommandLength()),
_CommandId(nHeader.getCommandId()),
_CommandStatus(nHeader.getCommandStatus()),
_SequenceNumber(nHeader.getSequenceNumber()){}

bool Header::operator ==(const Header &nHeader) const{
    return ((_CommandLength == nHeader.getCommandLength())&&
        (_CommandId == nHeader.getCommandId())&&
        (_CommandStatus == nHeader.getCommandStatus())&&
        (_SequenceNumber == nHeader.getSequenceNumber()));
}

bool Header::operator !=(const Header &nHeader) const{
    return !operator ==(nHeader);
}

Header &Header::operator =(const Header &nHeader){
    if(*this == nHeader)
        return *this;
    _SequenceNumber = nHeader.getSequenceNumber();
    _CommandId = nHeader.getCommandId();
    _CommandStatus = nHeader.getCommandStatus();
    _SequenceNumber = nHeader.getSequenceNumber();
    return *this;
}

void Header::setCommandLength(const quint32 nCommandLength){
    _CommandLength = nCommandLength;
}

const quint32 Header::getCommandLength() const{
    return _CommandLength;
}

void Header::setCommandId(const quint32 nCommandId){
    _CommandId = nCommandId;
}

const quint32 Header::getCommandId() const{
    return _CommandId;
}

void Header::setCommandStatus(const quint32 nCommandStatus){
    _CommandStatus = nCommandStatus;
}

const quint32 Header::getCommandStatus() const{
    return _CommandStatus;
}

void Header::setSequenceNumber(const quint32 nSequenceNumber){
    _SequenceNumber = nSequenceNumber;
}

const quint32 Header::getSequenceNumber() const{
    return _SequenceNumber;
}
