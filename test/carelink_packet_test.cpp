// Copyright 2018 EAP

#include <array>
#include "gtest/gtest.h"
#include "communication/protocol/carelink_packet.h"
#include "communication/raw/validation/crc.h"

using communication::protocol::CarelinkPacket;
using communication::raw::packet_t;
using communication::raw::kPacketHeaderSize;
using communication::raw::kPacketCrcSize;
using communication::protocol::MessageType;
namespace validation = communication::raw::validation;

// can't test too many parameters or totally empty data,
// as it would trip the asserts that ask for at least 7 bytes

static void add_crc(packet_t* data, uint8_t n_parameters) {
  auto packet_length_without_crc = kPacketHeaderSize + n_parameters;
  auto crc = validation::CRC8WCDMA(data->data(), packet_length_without_crc);
  data->at(packet_length_without_crc) = crc;
}

static CarelinkPacket create_packet(const packet_t& data, uint8_t n_parameters) {
  auto packet_length = kPacketHeaderSize + n_parameters + kPacketCrcSize;
  return CarelinkPacket(data, packet_length);
}

// crc calculations were done here: http://crccalc.com
TEST(TestRequestPacket, PacketNoParams) {
  uint8_t n_parameters = 0;
  packet_t data = {
      0xA7,  // device_type
      0x00, 0x00, 0x00,  // pump_id
      0x00,  // command_code
      n_parameters,
  };
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_EQ(data, packet.GetPacket());
}

TEST(TestRequestPacket, PacketNoCrc) {
  uint8_t n_parameters = 0;
  packet_t data = {
      0xA7,  // device_type
      0x00, 0x00, 0x00,  // pump_id
      0x00,  // command_code
      n_parameters,
  };
  packet_t copy_without_crc(data);
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_NE(copy_without_crc, packet.GetPacket());
}

TEST(TestRequestPacket, GetPumpId) {
  uint8_t n_parameters = 0;
  uint32_t pump_id = 0xABCDEF;
  uint8_t pump_id_0 = (pump_id >> 16) & 0xFF;
  uint8_t pump_id_1 = (pump_id >> 8) & 0xFF;
  uint8_t pump_id_2 = pump_id & 0xFF;
  packet_t data = {
    0xA7,
    pump_id_0, pump_id_1, pump_id_2,
    0x00,
    n_parameters,
  };
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_EQ(pump_id, packet.GetPumpId());
}

TEST(TestRequestPacket, CommandNoParams) {
  uint8_t n_parameters = 0;
  auto command = MessageType::kFirmwareVersion;
  packet_t data = {
    0xA7,
    0x00, 0x00, 0x00,
    static_cast<uint8_t>(command),
    n_parameters,
  };
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_EQ(command, packet.GetCommand());
}

TEST(TestRequestPacket, PacketOneParameter) {
  uint8_t n_parameters = 1;
  packet_t data = {
    0xA7,
    0x00, 0x00, 0x00,
    0x00,
    n_parameters,
    0xFF,
  };
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_EQ(data, packet.GetPacket());
}

TEST(TestRequestPacket, PacketMultipleParameters) {
  uint8_t n_parameters = 5;
  packet_t data = {
    0xA7,
    0x00, 0x00, 0x00,
    0x00,
    n_parameters,
    0xFF, 0xAB, 0xCD, 0xEF, 0x12,
  };
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_EQ(data, packet.GetPacket());
}

TEST(TestRequestPacket, PacketMaxParameters) {
  uint8_t n_parameters = 64;
  packet_t data = {
    0xA7,
    0x00, 0x00, 0x00,
    0x00,
    n_parameters,
    0xFF, 0xAB, 0xAA, 0x00, 0xAA, 0x00, 0xBA, 0xDD, 0x16, 0x81, 0x11, 0xCD, 0xEF, 0x12, 0xAA, 0x81,
    0xFF, 0xAB, 0xAA, 0xFE, 0x99, 0x00, 0xBA, 0x76, 0x16, 0x81, 0x11, 0xCD, 0xEF, 0x12, 0xAA, 0x81,
    0x11, 0xAB, 0xAA, 0x00, 0x19, 0x00, 0xBA, 0xDD, 0x65, 0x61, 0x91, 0xCD, 0xAD, 0x12, 0xAA, 0x81,
    0x10, 0xAB, 0xFF, 0x00, 0xAA, 0xFF, 0xBA, 0xDD, 0x16, 0x81, 0x11, 0xCC, 0xEF, 0x12, 0xAA, 0x90,
  };
  add_crc(&data, n_parameters);
  auto packet = create_packet(data, n_parameters);
  ASSERT_EQ(data, packet.GetPacket());
}
