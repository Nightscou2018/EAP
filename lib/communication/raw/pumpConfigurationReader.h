// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_RAW_PUMPCONFIGURATIONREADER_H_
#define LIB_COMMUNICATION_RAW_PUMPCONFIGURATIONREADER_H_

#include "communication/raw/pumpConfiguration.h"

namespace communication {
namespace raw {

class PumpConfigurationReader {
  readConfiguration(struct PumpConfiguration * configuration);
};

}  // namespace raw
}  // namespace communication

#endif  // LIB_COMMUNICATION_RAW_PUMPCONFIGURATIONREADER_H_
