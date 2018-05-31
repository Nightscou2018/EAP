// Copyright 2018 EAP

#include "communication/raw/radio.h"

namespace communication {
namespace raw {

Radio::Radio(struct PumpConfiguration configuration)
: m_time_out(0),
  m_attempts(0) {}

Radio::~Radio() {}

int Radio::Request(const RequestPacket& request_packet, ResponsePacket* response) {
    while (m_attempts < request_packet.MaxRetries()) {
        int failure = 0;  // do request e.g. GetData(response)
        if (failure) {
            m_attempts++;
        }
    }
    response->Validate();
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
