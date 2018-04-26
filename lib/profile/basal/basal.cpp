// Copyright 2018 EAP
#include "profile/basal/basal.h"
#include <iostream>

namespace profile {
namespace basal {

int32_t BasalLookup(const std::vector<Schedule*> &schedules, const time_t givenTime) {
  Helper helper;
  float basalRate;
  int32_t minutes;

  if (schedules.size() <= 0) {
    return -1;
  }

  if (givenTime == 0) {
    return -1;
  }

  // TODO(virus): Get sorted schedule if necessary
  auto basalProfileData = schedules;
  minutes = helper.Minutes(givenTime);
  basalRate = basalProfileData.at(0)->getRate();

  if (basalRate == 0.0) {
    return -1;
  }

  for (unsigned int i = 0; i < basalProfileData.size() - 1; ++i) {
    auto schedule = basalProfileData.at(i);
    auto nextSchedule = basalProfileData.at(i+1);

    if ((minutes >= schedule->getMinutes())
        && (minutes <= nextSchedule->getMinutes())) {
      basalRate = schedule->getRate();
      std::cout << basalRate << std::endl;
      return round(basalRate * 1000) / 1000;
    }
  }
  return -1;
}

int32_t MaxDailyBasal(const std::vector<Schedule*> &inputs) {
  if (inputs.size() <= 0) {
    return -1;
  }

  auto maxRate = std::max_element(inputs.begin(), inputs.end(),
    [](Schedule* a, Schedule* b) {
      return a->getRate() < b->getRate();
    });

  return ((*maxRate)->getRate() * 1000) / 1000;
}

// double MaxBasalLookup(){} //TODO: change input type

}  // namespace basal
}  // namespace profile
