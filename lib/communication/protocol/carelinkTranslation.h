// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_PROTOCOL_CARELINKTRANSLATION_H_
#define LIB_COMMUNICATION_PROTOCOL_CARELINKTRANSLATION_H_

#include <array>
#include <memory>
#include "carelinkConfiguration.h"
//#include "lib/communication/raw/iRadio.h"

namespace communication {
namespace carelinkTranslation {
template <size_t length>
class CarelinkTranslation {
  std::unique_ptr<int> radio;
  CarelinkTranslation(CarelinkConfiguration configuration);
  int getFirmwareVersion();
  int getPumpModel();
  int setTempBasal(int basal_rate);
  int getScheduledBasalRate();
  int getTempBasalRate();
  int getISF();
  std::array<int, length> getHistory(int page);  // TODO(virus): change type to GlucoseLevel
};

}  // namespace carelinkTranslation
}  // namespace communication

#endif  // LIB_COMMUNICATION_PROTOCOL_CARELINKTRANSLATION_H_
