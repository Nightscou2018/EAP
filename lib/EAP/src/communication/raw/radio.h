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
  int Request(const RequestPacket& request_packet, ResponsePacket* response);
  int Init();
  int WakeUp();
  int Sleep();

 private:
  int m_time_out;
  int m_attempts;
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_RADIO_H_
