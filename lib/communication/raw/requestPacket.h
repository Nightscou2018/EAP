// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_REQUESTPACKET_H_
#define LIB_COMMUNICATION_RAW_REQUESTPACKET_H_

#include <stdint.h>
#include <array>
#include <string>

namespace communication {
namespace raw {

template <size_t length>

class RequestPacket {
 private:
  std::array<uint32_t, length> m_data;
  int m_max_retries;

 public:
  RequestPacket<length>(std::array<uint32_t, length> data, int max_retries);
  int const maxRetries();
  std::array<uint32_t, length> const getData();
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_REQUESTPACKET_H_
