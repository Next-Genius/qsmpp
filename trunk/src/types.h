#ifndef SMPP_TYPES_H
#define SMPP_TYPES_H

#include <string>
#include <vector>

namespace smpp {

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef std::basic_string<char> CString;
typedef std::vector<smpp::uint8> String;

} // namespace smpp

#endif // SMPP_TYPES_H
