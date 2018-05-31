// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_REQUEST_PACKET_H_
#define LIB_COMMUNICATION_RAW_REQUEST_PACKET_H_

#include <stdint.h>
#include <array>
#include <string>

namespace communication {
namespace raw {

static const size_t packet_length = 64;

class RequestPacket {
 public:
  RequestPacket(std::array<uint32_t, packet_length> data, int max_retries);
  ~RequestPacket();
  int const MaxRetries();
  std::array<uint32_t, packet_length> const GetData();
 private:
  std::array<uint32_t, packet_length> m_data;
  int m_max_retries;
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_REQUEST_PACKET_H_
