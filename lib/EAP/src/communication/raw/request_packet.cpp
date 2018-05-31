// Copyright 2018 EAP

#include <cassert>
#include "communication/raw/request_packet.h"
#include "validation/crc.h"
#include "communication/raw/packet.h"

namespace communication {
namespace raw {

RequestPacket::RequestPacket(packet_data_t data,
      size_t data_size,
      int max_retries)
: m_data(data), m_max_retries(max_retries) {
      assert(data_size < kMaxPacketLength);
    auto crc = validation::CRC8WCDMA(data.data(), data_size);
    auto crc_position = &m_data[data_size];
    *crc_position = crc;
}

RequestPacket::~RequestPacket() {}

int RequestPacket::MaxRetries() const {
      return m_max_retries;
}

packet_data_t RequestPacket::GetData() const {
      return m_data;
}

}  // namespace raw
}  // namespace communication
