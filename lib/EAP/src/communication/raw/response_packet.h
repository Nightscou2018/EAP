// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_RESPONSE_PACKET_H_
#define COMMUNICATION_RAW_RESPONSE_PACKET_H_

#include <cstdint>
#include <array>
#include <string>
#include "communication/raw/packet.h"

namespace communication {
namespace raw {

class ResponsePacket {
 public:
  ResponsePacket(packet_data_t data, int max_retries);
  ~ResponsePacket();
  packet_data_t const GetData();
  int const Validate();
 private:
  packet_data_t m_data;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_RESPONSE_PACKET_H_
