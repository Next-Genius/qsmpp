#include <tlv.h>

namespace qsmpp {
namespace pdu {
namespace tlv {

TLV::TLV(quint16 tag, quint16 length):
  tag(tag), length(length) {

}

TLV::TLV(const TLV &other):
  tag(other.getTag()), length(other.getLength()) {

}

bool TLV::operator ==(const TLV &other) const {
  return (tag == other.getTag() && length == other.getLength());
}

bool TLV::operator !=(const TLV &other) const {
  return !this->operator == (other);
}

TLV &TLV::operator = (const TLV &other) {
  if (*this == other)
    return *this;
  tag = other.getTag();
  length = other.getLength();
  return *this;
}

void TLV::setTag(quint16 tag) {
  this->tag = tag;
}

quint16 TLV::getTag() const {
  return tag;
}

void TLV::setLength(quint16 length) {
  this->length = length;
}

quint16 TLV::getLength() const {
  return length;
}

} // namespace tlv
} // namespace pdu
} // namespace qsmpp
