// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_REQUEST_PACKET_H_
#define COMMUNICATION_RAW_REQUEST_PACKET_H_

#include <cstdint>
#include <array>
#include "communication/raw/packet.h"

namespace communication {
namespace raw {

class RequestPacket {
 public:
  RequestPacket() = delete;
  // data_size must be < kMaxPacketLength
  RequestPacket(packet_data_t data, size_t data_size, int max_retries);
  ~RequestPacket();
  int MaxRetries() const;
  packet_data_t GetData() const;
 private:
  packet_data_t m_data;
  int m_max_retries;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_REQUEST_PACKET_H_
