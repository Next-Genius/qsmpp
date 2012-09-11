#ifndef SMPP_SEQUENCE_NUMBER_H
#define SMPP_SEQUENCE_NUMBER_H

#include <types.h>

namespace smpp {

class SequenceNumber {
  SequenceNumber();
  smpp::uint32 value;
public:
  enum {
    Min = 0x00000001, ///< minimum sequence number
    Max = 0x7fffffff  ///< maximum sequence number
  };

  static smpp::uint32 assign(const smpp::uint32 &p, bool allow_0 = false) {
    if(p > Max) return Max;
    if (allow_0 == false && p == 0) return Min;
    return p;
  }

  SequenceNumber(const smpp::uint32 &p, bool allow_0 = false) :
    value(assign(p, allow_0)) {}

  SequenceNumber &operator++() {
    value = (value == Max) ? Min : ++value;
    return *this;
  }

  SequenceNumber operator ++(int) {
    SequenceNumber t = *this;
    value = (value == Max) ? Min : ++value;
    return t;
  }

  operator smpp::uint32() const { return value; }
};

} // namespace smpp

#endif // SMPP_SEQUENCE_NUMBER_H
