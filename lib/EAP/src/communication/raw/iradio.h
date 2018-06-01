// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_IRADIO_H_
#define COMMUNICATION_RAW_IRADIO_H_

#include "communication/raw/packet.h"

namespace communication {
namespace raw {

class IRadio {
 public:
  virtual int Request(const packet_t& request_packet, packet_t* response, uint8_t max_attempts) = 0;
  virtual ~IRadio() {}
  virtual int Init() = 0;
  virtual int WakeUp() = 0;
  virtual int Sleep() = 0;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_IRADIO_H_
