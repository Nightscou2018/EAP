// Copyright 2018 EAP

#include <Arduino.h>
#include "communication/raw/request_packet.h"
#include "communication/raw/response_packet.h"
#include "communication/raw/radio.h"
#include "communication/raw/packet.h"
#include "communication/raw/pump_configuration_reader.h"

void loop() {}

void setup() {
    namespace comm = communication::raw;
    auto data = comm::packet_data_t({0xDE, 0xEA, 0xDB, 0xEE, 0xF});
    auto request = comm::RequestPacket(data, 1, 10);
    auto config_reader = comm::PumpConfigurationReader();
    struct comm::PumpConfiguration config;
    if (config_reader.ReadConfiguration(&config)) {
        // problem
        return;
    }
    auto radio = comm::Radio(config);
    radio.Init();
    auto response = comm::ResponsePacket();
    radio.Request(request, &response);
    auto response_data = response.GetData();
}
