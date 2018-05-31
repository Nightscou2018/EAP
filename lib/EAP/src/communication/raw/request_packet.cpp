// Copyright 2018 EAP

#include <cassert>
#include "communication/raw/request_packet.h"
#include "communication/raw/validation/crc.h"

namespace communication {
namespace raw {

RequestPacket::RequestPacket(std::array<uint8_t, packet_length> data,
      size_t data_size,
      int max_retries)
: m_data(data), m_max_retries(max_retries) {
      assert(data_size < packet_length);
    auto crc = validation::CRC8WCDMA(data.data(), data_size);
    auto crc_position = &m_data[data_size];
    *crc_position = crc;
}

RequestPacket::~RequestPacket() {}

int RequestPacket::MaxRetries() const {
      return m_max_retries;
}

std::array<uint8_t, packet_length> RequestPacket::GetData() const {
      return m_data;
}

}  // namespace raw
}  // namespace communication
