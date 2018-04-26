// Copyright 2018 EAP

#ifndef LIB_VALIDATION_CRC_H_
#define LIB_VALIDATION_CRC_H_

#include <inttypes.h>

namespace validation {

  /*! \brief performs a crc on data
   *   the CRC is 8 bits wide, according to the WCDMA standard
   */
uint8_t CRC8WCDMA(const uint8_t data[], unsigned int count);

}  // namespace validation
#endif  // LIB_VALIDATION_CRC_H_
