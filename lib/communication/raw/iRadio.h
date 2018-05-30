// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_IRADIO_H_
#define LIB_COMMUNICATION_RAW_IRADIO_H_

#include "communication/raw/requestPacket.h"
#include "communication/raw/responsePacket.h"

namespace communication {
namespace raw {

class Iradio {
virtual int request(const RequestPacket& request_packet, ResponsePacket* response) = 0;
virtual int init() = 0;
virtual int wakeUp() = 0;
virtual int sleep() = 0;
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_IRADIO_H_
