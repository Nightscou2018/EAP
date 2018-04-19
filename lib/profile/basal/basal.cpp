// Copyright 2018 Elviro Junior and Rick van Schijndel
#include "profile/basal/basal.h"

namespace profile {
namespace basal {

int32_t BasalLookup(const std::vector<Schedule*> &schedules, const time_t now) {
  Helper helper;
  float basalRate;
  int32_t minutes;

  if (schedules.size() <= 0) {
    return -1;
  }

  if (now == 0) {
    return -1;
  }

  // TODO(virus): Get sorted schedule if necessary
  auto basalProfileData = schedules;
  minutes = helper.Minutes(now);
  basalRate = basalProfileData.at(0)->getRate();

  if (basalRate == 0.0) {
    return -1;
  }

  for (unsigned int i = 0; i < basalProfileData.size() - 1; ++i) {
    auto profile = basalProfileData.at(i);
    auto nextProfile = basalProfileData.at(i+1);

    if ((minutes >= profile->getStart())
        && (minutes <= nextProfile->getStart())) {
      basalRate = profile->getRate();
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
