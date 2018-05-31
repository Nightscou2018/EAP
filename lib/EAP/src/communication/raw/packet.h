// Copyright 2018 EAP
#ifndef COMMUNICATION_RAW_PACKET_H_
#define COMMUNICATION_RAW_PACKET_H_

#include <array>

namespace communication {
namespace raw {

const size_t kMaxPacketLength = 64;
typedef std::array<uint8_t, kMaxPacketLength> packet_data_t;

}
}


#endif  // COMMUNICATION_RAW_PACKET_H_
