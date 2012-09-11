#ifndef SMPP_COMMAND_LENGTH_H
#define SMPP_COMMAND_LENGTH_H

#include <types.h>

namespace smpp {

class CommandLength {
  smpp::uint32 value;
  CommandLength();
public:

  CommandLength(const smpp::uint32 &p) : value(p) {}

  CommandLength &operator +=(int i) { value += i; return *this; }

  operator smpp::uint32() const { return value; }

};

} // namespace smpp

#endif // SMPP_COMMAND_LENGTH_H
