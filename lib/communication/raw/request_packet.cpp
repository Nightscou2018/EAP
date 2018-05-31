// Copyright 2018 EAP

#include "communication/raw/request_packet.h"
#include "communication/raw/validation/crc.h"

namespace communication {
namespace raw {

RequestPacket::RequestPacket(std::array<uint8_t, packet_length> data, int max_retries)
: m_data(data), m_max_retries(max_retries) {
    auto crc = validation::CRC::CRC8WCDMA(data.data(), packet_length);
    auto crc_position = data.end();
    // TODO(Mindavi): not sure where to put the crc
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
