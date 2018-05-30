// Copyright 2018 EAP

#ifndef LIB_COMMUNICATION_PROTOCOL_CARELINKTRANSLATION_H_
#define LIB_COMMUNICATION_PROTOCOL_CARELINKTRANSLATION_H_

#include <array>
#include "carelinkConfiguration.h"
#include "lib/communication/raw/iRadio.h"

namespace communication {
namespace carelinkTranslation {

class CarelinkTranslation {
  std::unique_ptr<Iradio> radio;
  CarelinkTranslation(carelinkConfiguration configuration);
  int getFirmwareVersion();
  int getPumpModel();
  int setTempBasal(int basal_rate);
  int getScheduledBasalRate();
  int getTempBasalRate();
  int getISF();
  array<int, int lenght> getHistory(int page);  // TODO(virus): change type to GlucoseLevel
};

}  // namespace carelinkTranslation
}  // namespace communication

#endif  // LIB_COMMUNICATION_PROTOCOL_CARELINKTRANSLATION_H_
