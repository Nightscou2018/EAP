// Copyright 2018 EAP

#include "communication/raw/radio.h"

namespace communication {
namespace raw {

Radio::Radio(struct PumpConfiguration configuration) {}

Radio::~Radio() {}

int Radio::Request(const packet_t& request_packet, packet_t* response, uint8_t max_attempts) {
    uint8_t attempts = 0;
    while (attempts <= max_attempts) {
        int failure = 0;  // do request e.g. GetData(response)
        if (failure) {
            attempts++;
        }
    }
    return 1;
}

int Radio::Init() {
    return 1;
}

int Radio::WakeUp() {
    return 1;
}

int Radio::Sleep() {
    return 1;
}

}  // namespace raw
}  // namespace communication
