// Copyright 2018 EAP
#ifndef COMMUNICATION_RAW_VALIDATION_CRC_H_
#define COMMUNICATION_RAW_VALIDATION_CRC_H_

#include <cstddef>
#include <cinttypes>

namespace communication {
namespace raw {
namespace validation {

uint8_t CRC8WCDMA(const uint8_t data[], size_t count);

}  // namespace validation
}  // namespace raw
}  // namespace communication
#endif  // COMMUNICATION_RAW_VALIDATION_CRC_H_
