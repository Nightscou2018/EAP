// Copyright 2018 EAP

#include "communication/raw/pump_configuration_reader.h"

namespace communication {
namespace raw {

int PumpConfigurationReader::ReadConfiguration(struct PumpConfiguration * configuration) {
    configuration->frequency = 16555;
    return 0;
}

}  // namespace raw
}  // namespace communication
