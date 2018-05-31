// Copyright 2018 EAP
#ifndef LIB_COMMUNICATION_RAW_VALIDATION_CRC_H_
#define LIB_COMMUNICATION_RAW_VALIDATION_CRC_H_

#include <inttypes.h>
namespace communication {
namespace raw {
namespace validation {
class CRC {
 public:
      static uint8_t CRC8WCDMA(const uint8_t data[], unsigned int count);
 private:
      static uint8_t Reflect(const uint8_t input);
      static uint8_t crcTable[];
      CRC() {}
};

}  // namespace validation
}  // namespace raw
}  // namespace communication
#endif  // LIB_COMMUNICATION_RAW_VALIDATION_CRC_H_
