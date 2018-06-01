// Copyright 2018 EAP
#ifndef COMMUNICATION_PROTOCOL_CARELINK_PACKET_H_
#define COMMUNICATION_PROTOCOL_CARELINK_PACKET_H_

#include <array>
#include "communication/raw/packet.h"
#include "communication/protocol/message_type.h"

namespace communication {
namespace protocol {

typedef std::array<uint8_t, communication::raw::kMaxPacketDataLength> packet_parameters_t;

// // https://github.com/ecc1/medtronic/blob/67e857035da4a6cfcb9bb3a53830cf79dcf4d09a/command.go#L90
struct carelink_packet_structure {
  // normally 0xA7 (https://github.com/ecc1/medtronic/blob/d58d87a20ca73f4bf4eab1da92f16e71fb01f93a/packet/types.go#L8)
  uint8_t device_type;
  // 3 bytes of pump_id
  uint8_t pump_id[3];
  // pump action
  uint8_t command_code;
  // 0 when no parameters
  uint8_t parameter_length;
  // empty when 0 parameters, otherwise data + padding with zeroes
  packet_parameters_t parameters;
  uint8_t crc;
};

class CarelinkPacket {
 public:
  explicit CarelinkPacket(communication::raw::packet_t packet, size_t length);
  MessageType GetCommand() const;
  communication::raw::packet_t GetPacket() const;
  bool IsValid() const;
  uint32_t GetPumpId() const;

 private:
  struct carelink_packet_structure m_packet_structure;
  size_t m_length;
};

}  // namespace protocol
}  // namespace communication

#endif  // COMMUNICATION_PROTOCOL_CARELINK_PACKET_H_
