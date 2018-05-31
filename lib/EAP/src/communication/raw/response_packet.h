// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_RESPONSE_PACKET_H_
#define COMMUNICATION_RAW_RESPONSE_PACKET_H_

#include <cstdint>
#include <array>
#include <string>

namespace communication {
namespace raw {

static const size_t packet_length = 64;

class ResponsePacket {
 public:
  ResponsePacket(std::array<uint32_t, packet_length> data, int max_retries);
  ~ResponsePacket();
  std::array<uint32_t, packet_length> const GetData();
  int const Validate();
 private:
  std::array<uint32_t, packet_length> m_data;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_RESPONSE_PACKET_H_
