// Copyright 2018 EAP

#include <array>
#include "gtest/gtest.h"
#include "communication/raw/request_packet.h"

TEST(TestRequestPacket, TestCRCAddition) {
  using communication::raw::RequestPacket;
  std::array<uint8_t, 64> data = {0, 0, 0, 0};
  auto test_packet = RequestPacket(data, 1);
  uint32_t crc = 0x00;
  data[4] = crc;
  ASSERT_EQ(data, test_packet.GetData());

  data = {'a', 'a', 'a', 'a'};
  test_packet = RequestPacket(data, 1);
  crc = 0x42;
  data[4] = crc;
  ASSERT_EQ(data, test_packet.GetData());
}
