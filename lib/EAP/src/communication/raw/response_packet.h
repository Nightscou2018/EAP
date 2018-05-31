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
  ResponsePacket();
  ResponsePacket(packet_data_t data, size_t data_size);
  packet_data_t GetData() const;
  int Validate() const;
 private:
  packet_data_t m_data;
  size_t m_size;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_RESPONSE_PACKET_H_
