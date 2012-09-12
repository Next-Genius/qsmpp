#ifndef SMPP_DATA_FUNCTIONS_H
#define SMPP_DATA_FUNCTIONS_H

#include <types.h>

namespace smpp {

inline bool is_big_endian() {
  const long x = 1;
  return *(const char *)&x ? false : true;
}

inline uint32 ntoh32(const uint32 &n) {
  if (is_big_endian())
      return n;
  return (n & 0x000000ff) << 24 |
         (n & 0x0000ff00) << 8 |
         (n & 0x00ff0000) >> 8 |
         (n & 0xff000000) >> 24;
}

inline uint32 hton32(const uint32 &n) {
  if (is_big_endian())
    return n;
  return (n & 0x000000ff) << 24 |
         (n & 0x0000ff00) << 8 |
         (n & 0x00ff0000) >> 8 |
         (n & 0xff000000) >> 24;
}

inline uint16 ntoh16(const uint16 &n) {
  if (is_big_endian())
    return n;
  return (n & 0x00ff) << 8 | (n & 0xff00) >> 8;
}

inline uint16 hton16(const uint16& n) {
  if (is_big_endian())
    return n;
  return (n & 0x00ff) << 8 | (n & 0xff00) >> 8;
}
inline uint16 ntoh16(const uint8 *b) {
  uint16 t;
  std::copy(b, b + 2, (uint8 *)&t);
  return ntoh16(t);
}

inline uint32 ntoh32(const uint8 *b) {
  uint32 t;
  std::copy(b, b + 4, (uint8 *)&t);
  return ntoh32(t);
}

} // namespace smpp

#endif // SMPP_DATA_FUNCTIONS_H
