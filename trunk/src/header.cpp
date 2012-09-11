#include <header.h>

namespace smpp {
namespace pdu {

Header::Header(
  quint32 command_length,
  quint32 command_id,
  quint32 command_status,
  quint32 sequence_number):
    command_length(command_length),
    command_id(command_id),
    command_status(command_status),
    sequence_number(sequence_number) {

}

Header::Header(const Header &other):
  command_length(other.getCommandLength()),
  command_id(other.getCommandId()),
  command_status(other.getCommandStatus()),
  sequence_number(other.getSequenceNumber()) {

}

bool Header::operator ==(const Header &other) const {
  return ((command_length == other.getCommandLength()) &&
          (command_id == other.getCommandId()) &&
          (command_status == other.getCommandStatus()) &&
          (sequence_number == other.getSequenceNumber()));
}

bool Header::operator !=(const Header &other) const {
  return !operator ==(other);
}

Header &Header::operator =(const Header &other) {
  if (*this == other)
    return *this;
  command_length = other.getCommandLength();
  command_id = other.getCommandId();
  command_status = other.getCommandStatus();
  sequence_number = other.getSequenceNumber();
  return *this;
}

void Header::setCommandLength(quint32 command_length) {
  this->command_length = command_length;
}

quint32 Header::getCommandLength() const {
  return command_length;
 }

void Header::setCommandId(quint32 command_id) {
  this->command_id = command_id;
}

quint32 Header::getCommandId() const {
  return command_id;
}

void Header::setCommandStatus(quint32 command_status) {
  this->command_status = command_status;
}

quint32 Header::getCommandStatus() const {
  return command_status;
}

void Header::setSequenceNumber(quint32 sequence_number) {
  this->sequence_number = sequence_number;
}

quint32 Header::getSequenceNumber() const {
  return sequence_number;
}

} // namespace pdu
} // namespace smpp
