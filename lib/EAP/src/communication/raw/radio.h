// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_RADIO_H_
#define COMMUNICATION_RAW_RADIO_H_

#include "communication/raw/iradio.h"
#include "communication/raw/pump_configuration.h"

namespace communication {
namespace raw {

class Radio : public IRadio {
 public:
  explicit Radio(struct PumpConfiguration configuration);
  ~Radio();
  int Request(const packet_t& request_packet, packet_t* response, uint8_t max_attempts);
  int Init();
  int WakeUp();
  int Sleep();
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_RADIO_H_
