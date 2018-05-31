// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_RESPONSE_PACKET_H_
#define LIB_COMMUNICATION_RAW_RESPONSE_PACKET_H_

#include <stdint.h>
#include <array>
#include <string>

namespace communication {
namespace raw {

template <size_t length>

class ResponsePacket {
 public:
  ResponsePacket<length>(std::array<uint32_t, length> data, int max_retries);
  ~ResponsePacket();
  std::array<uint32_t, length> const GetData();
  int const Validate();
 private:
  std::array<uint32_t, length> m_data;
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_RESPONSE_PACKET_H_
