// Copyright 2018 EAP
#ifndef COMMUNICATION_RAW_PACKET_H_
#define COMMUNICATION_RAW_PACKET_H_

#include <array>

namespace communication {
namespace raw {

// what is the actual length?
// the decoding-carelink uses the usb stick, thus might not be the one to follow
// 64, http://bewest.github.io/decoding-carelink/api/commands.html#decocare.commands.PumpCommand.bytesPerRecord
// 70, https://github.com/ecc1/medtronic/blob/67e857035da4a6cfcb9bb3a53830cf79dcf4d09a/command.go#L12
// 71, https://github.com/ecc1/medtronic/blob/67e857035da4a6cfcb9bb3a53830cf79dcf4d09a/command.go#L98
// probably the last one
constexpr size_t kMaxPacketDataLength = 64;
constexpr size_t kPacketHeaderSize = 6;
constexpr size_t kPacketCrcSize = 1;
constexpr size_t kMaxPacketSize = kPacketHeaderSize + kMaxPacketDataLength + kPacketCrcSize;
typedef std::array<uint8_t, kMaxPacketSize> packet_t;

}  // namespace raw
}  // namespace communication


#endif  // COMMUNICATION_RAW_PACKET_H_
