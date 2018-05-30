// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_RESPONSEPACKET_H_
#define LIB_COMMUNICATION_RAW_RESPONSEPACKET_H_

#include <stdint.h>
#include <array>
#include <string>

namespace communication {
namespace raw {

template <size_t length>

class ResponsePacket {
 private:
  std::array<uint32_t, length> m_data;

 public:
  ResponsePacket<length>(std::array<uint32_t, length> data, int max_retries);
  std::array<uint32_t, length> const getData();
  int const validate();
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_RESPONSEPACKET_H_
