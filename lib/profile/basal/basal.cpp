#include "basal.h"
#include <iostream>
int32_t LIB_PROFILE_BASAL_BASAL::BasalLookup(std::vector<Schedule*> schedules, time_t givenTime) {
    Helper helper;
    float basalRate;
    int32_t minutes;

    if (schedules.size() <= 0) {
        return -1;
    }

    if (givenTime == 0) {
        givenTime = time(0);
        std::cout << "given time is now : " << helper.Minutes(givenTime) << std::endl;
    }

    // TODO(virus): Get sorted schedule if necessary
    auto basalProfileData = schedules;

    minutes = helper.Minutes(givenTime);
    basalRate = basalProfileData.at(0)->getRate();

    if (basalRate == 0.0) {
      return -1;
    }


    for (unsigned int i = 0; i < basalProfileData.size() - 1; ++i) {
      auto profile = basalProfileData.at(i);
      auto nextProfile = basalProfileData.at(i+1);
      //auto entryHigh = CompareMins(minutes, profile->getMinutes(), 0);
      //auto entryLow  = CompareMins(minutes, nextProfile->getMinutes(), 1);

      if ((minutes >= profile->getMinutes()) && (minutes <= nextProfile->getMinutes())) {
        basalRate = profile->getRate();
        return round(basalRate * 1000) / 1000;
      }
    }

return -1;
}

// TODO(elviro): change input type
int32_t LIB_PROFILE_BASAL_BASAL::MaxDailyBasal(std::vector<Schedule*> inputs) {
  if (inputs.size() <= 0) {
    return -1;
  }

  auto maxRate = std::max_element(inputs.begin(), inputs.end(),
                      [](Schedule  * a, Schedule * b){
                        return a->getRate() < b->getRate();
                      });

  return ((*maxRate)->getRate() * 1000) / 1000;
}

// double LIB_PROFILE_BASAL_BASAL::MaxBasalLookup(){} // TODO: change input type
