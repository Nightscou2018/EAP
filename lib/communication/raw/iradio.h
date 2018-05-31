// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_IRADIO_H_
#define LIB_COMMUNICATION_RAW_IRADIO_H_

#include "communication/raw/request_packet.h"
#include "communication/raw/response_packet.h"

namespace communication {
namespace raw {

class IRadio {
 public:
  virtual int Request(const RequestPacket& request_packet, ResponsePacket* response) = 0;
  virtual ~IRadio() {}
  virtual int Init() = 0;
  virtual int WakeUp() = 0;
  virtual int Sleep() = 0;
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_IRADIO_H_
