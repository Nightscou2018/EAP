// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_PROTOCOL_CARELINK_TRANSLATION_H_
#define LIB_COMMUNICATION_PROTOCOL_CARELINK_TRANSLATION_H_

#include <array>
#include <memory>
#include "carelink_configuration.h"
#include "communication/raw/IRadio.h"

namespace communication {
namespace protocol {

template <size_t length>

class CarelinkTranslation {
 public:
  explicit CarelinkTranslation(CarelinkConfiguration configuration);
  int GetFirmwareVersion();
  int GetPumpModel();
  int SetTempBasal(int basal_rate);
  int GetScheduledBasalRate();
  int GetTempBasalRate();
  int GetISF();
  std::array<int, length> GetHistory(int page);  // TODO(virus): change type to GlucoseLevel
 private:
  std::unique_ptr<IRadio> radio;
};

}  // namespace protocol
}  // namespace communication

#endif  // LIB_COMMUNICATION_PROTOCOL_CARELINK_TRANSLATION_H_
