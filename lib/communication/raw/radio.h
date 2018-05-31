// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_RADIO_H_
#define LIB_COMMUNICATION_RAW_RADIO_H_

namespace communication {
namespace raw {
class Radio {
  int timeOut;
  int retries;
  explicit Radio(struct PumpConfiguration configuration);
};
}
}

#endif  // LIB_COMMUNICATION_RAW_RADIO_H_
