// Copyright 2018 EAP

#include <cassert>
#include <algorithm>
#include "communication/protocol/carelink_packet.h"
#include "communication/raw/validation/crc.h"

namespace communication {
namespace protocol {

static constexpr int kDeviceIdIndex = 0;
static constexpr int kPumpIdStartIndex = 1;
static constexpr int kPumpIdEndIndex = 3;
static constexpr int kCommandCodeIndex = 4;
static constexpr int kParameterLengthIndex = 5;
static constexpr int kParameterStartIndex = 6;

CarelinkPacket::CarelinkPacket(communication::raw::packet_t packet, size_t length)
: m_length(length) {
  constexpr auto kMinSize = communication::raw::kPacketHeaderSize
    + communication::raw::kPacketCrcSize;
  constexpr auto kMaxSize = communication::raw::kMaxPacketSize;
  assert(length >= kMinSize);
  assert(length <= kMaxSize);
  m_packet_structure.parameters.fill(0);
  m_packet_structure.device_type = packet[kDeviceIdIndex];
  for (size_t packet_index = kPumpIdStartIndex, pump_id_index = 0;
    packet_index <= kPumpIdEndIndex; packet_index++, pump_id_index++) {
      m_packet_structure.pump_id[pump_id_index] = packet[packet_index];
  }
  m_packet_structure.command_code = packet[kCommandCodeIndex];
  m_packet_structure.parameter_length = packet[kParameterLengthIndex];
  assert(m_packet_structure.parameter_length <= communication::raw::kMaxPacketDataLength);
  auto parameter_begin = std::begin(packet) + kParameterStartIndex;
  auto parameter_end = parameter_begin + m_packet_structure.parameter_length;
  std::copy(parameter_begin, parameter_end, std::begin(m_packet_structure.parameters));
  m_packet_structure.crc = *(parameter_end);
}

enum MessageType CarelinkPacket::GetCommand() const {
    return static_cast<MessageType>(m_packet_structure.command_code);
}

communication::raw::packet_t CarelinkPacket::GetPacket() const {
  communication::raw::packet_t packet;
  packet[kDeviceIdIndex] = m_packet_structure.device_type;
  for (size_t packet_index = kPumpIdStartIndex, pump_id_index = 0;
    packet_index <= kPumpIdEndIndex; packet_index++, pump_id_index++) {
      packet[packet_index] = m_packet_structure.pump_id[pump_id_index];
  }
  packet[kCommandCodeIndex] = m_packet_structure.command_code;
  packet[kParameterLengthIndex] = m_packet_structure.parameter_length;
  std::copy(
    std::begin(m_packet_structure.parameters),
    std::end(m_packet_structure.parameters),
    std::begin(packet) + kParameterStartIndex);
  packet[kParameterStartIndex + m_packet_structure.parameter_length] = m_packet_structure.crc;
  return packet;
}

bool CarelinkPacket::IsValid() const {
  auto packet = GetPacket();
  auto crc = communication::raw::validation::CRC8WCDMA(
    packet.data(), packet.size() - communication::raw::kPacketCrcSize);
  return m_packet_structure.crc == crc;
}

uint32_t CarelinkPacket::GetPumpId() const {
  uint32_t pump_id = 0;
  pump_id = m_packet_structure.pump_id[0] << 16;
  pump_id += m_packet_structure.pump_id[1] << 8;
  pump_id += m_packet_structure.pump_id[2];
  return pump_id;
}

}  // namespace protocol
}  // namespace communication
