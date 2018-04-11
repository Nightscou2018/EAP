#ifndef __VALIDATION_CRC_H_
#define __VALIDATION_CRC_H_

#include <inttypes.h>
namespace Validation
{

  /*! \brief performs a crc on data
   *   the CRC is 8 bits wide, according to the WCDMA standard
   */
uint8_t CRC8WCDMA(const uint8_t data[], unsigned int count);


} // namespace validation

#endif
