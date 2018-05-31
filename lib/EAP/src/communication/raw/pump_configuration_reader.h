// Copyright 2018 EAP

#ifndef COMMUNICATION_RAW_PUMP_CONFIGURATION_READER_H_
#define COMMUNICATION_RAW_PUMP_CONFIGURATION_READER_H_

#include "communication/raw/pump_configuration.h"

namespace communication {
namespace raw {

class PumpConfigurationReader {
 public:
  PumpConfigurationReader();
  ~PumpConfigurationReader();
  int ReadConfiguration(struct PumpConfiguration * configuration);
};

}  // namespace raw
}  // namespace communication

#endif  // COMMUNICATION_RAW_PUMP_CONFIGURATION_READER_H_
