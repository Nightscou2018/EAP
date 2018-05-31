// Copyright 2018 EAP

#include <array>
#include "gtest/gtest.h"
#include "communication/raw/request_packet.h"

using communication::raw::RequestPacket;

// crc calculations were done here: http://crccalc.com
TEST(TestRequestPacket, CRCAddition) {
  std::array<uint8_t, 64> data = {0, 0, 0, 0};
  auto test_packet = RequestPacket(data, 4, 1);
  uint32_t crc = 0x00;
  data[4] = crc;
  ASSERT_EQ(data, test_packet.GetData());

  data = {'a', 'a', 'a', 'a'};
  test_packet = RequestPacket(data, 4, 1);
  crc = 0x42;
  data[4] = crc;
  ASSERT_EQ(data, test_packet.GetData());
}

TEST(TestRequestPacket, EmptyPacket) {
  std::array<uint8_t, 64> data = {};
  auto test_packet = RequestPacket(data, 0, 1);
  ASSERT_EQ(data, test_packet.GetData());
}
