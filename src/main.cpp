// Copyright 2018 EAP

#include <Arduino.h>
#include "communication/raw/radio.h"
#include "communication/raw/packet.h"
#include "communication/raw/pump_configuration_reader.h"
#include "communication/protocol/carelink_packet.h"

void loop() {}

void setup() {
    namespace comm = communication::raw;
    auto data = comm::packet_t({0xDE, 0xEA, 0xDB, 0xEE, 0xF});
    auto request = communication::protocol::CarelinkPacket(data, 7);
    auto config_reader = comm::PumpConfigurationReader();
    struct comm::PumpConfiguration config;
    if (config_reader.ReadConfiguration(&config)) {
        // problem
        return;
    }
    auto radio = comm::Radio(config);
    radio.Init();
    communication::raw::packet_t response_data;
    auto max_attempts = 1;
    if (radio.Request(request.GetPacket(), &response_data, max_attempts)) {
        // problem
        return;
    }
}
