// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_RADIO_H_
#define COMMUNICATION_RAW_RADIO_H_

#include "iradio.h"

namespace communication {
namespace raw {
class Radio : public IRadio {
 public:
  explicit Radio(struct PumpConfiguration configuration);
  ~Radio();

 private:
  int timeOut;
  int retries;
};
}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_RADIO_H_
