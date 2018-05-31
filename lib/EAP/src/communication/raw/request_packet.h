// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_REQUEST_PACKET_H_
#define COMMUNICATION_RAW_REQUEST_PACKET_H_

#include <cstdint>
#include <array>

namespace communication {
namespace raw {

static const size_t packet_length = 64;

class RequestPacket {
 public:
  RequestPacket() = delete;
  // data_size must be < packet_length
  RequestPacket(std::array<uint8_t, packet_length> data, size_t data_size, int max_retries);
  ~RequestPacket();
  int MaxRetries() const;
  std::array<uint8_t, packet_length> GetData() const;
 private:
  std::array<uint8_t, packet_length> m_data;
  int m_max_retries;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_REQUEST_PACKET_H_
