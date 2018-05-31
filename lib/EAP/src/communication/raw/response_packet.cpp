// Copyright 2018 EAP

#include <cassert>
#include "communication/raw/response_packet.h"
#include "validation/crc.h"
#include "communication/raw/packet.h"

namespace communication {
namespace raw {

ResponsePacket::ResponsePacket()
: m_data({}), m_size(0) {}

ResponsePacket::ResponsePacket(packet_data_t data, size_t data_size)
: m_data(data), m_size(data_size) {
    assert(data_size <= kMaxPacketLength);
}

packet_data_t ResponsePacket::GetData() const {
      return m_data;
}

int ResponsePacket::Validate() const {
    auto crc = m_data[m_size - 1];
    auto data_size_without_crc = m_size - 1;
    validation::CRC8WCDMA(m_data.data(), data_size_without_crc);
}

}  // namespace raw
}  // namespace communication
