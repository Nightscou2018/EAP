#include "basal.h"

int Basal::BasalLookup(std::vector<Schedule*> schedules, time_t &now)
{

    Helper helper;
    double basalRate;
    int minutes;

    if(schedules.size() <= 0)
    {  return -1; }

    auto basalProfileData = schedules;   //TODO: Get sorted schedule if necessary
    minutes = helper.Minutes(now);
    basalRate = basalProfileData.at(0)->getRate();

    if(basalRate == 0.0)
    {
      return -1;
    }


    for(unsigned int i = 0; i < basalProfileData.size() - 1; ++i)
    {
      auto profile = basalProfileData.at(i);
      auto nextProfile = basalProfileData.at(i+1);

      if((minutes >= profile->getMinutes()) && (minutes <= nextProfile->getMinutes()))
      {
        basalRate = profile->getRate();
        return round(basalRate * 1000) / 1000;
      }

    }

   return -1;
}

int Basal::MaxDailyBasal(std::vector<Schedule*> inputs)   //TODO: change input type*
{
   auto maxRate = std::max_element(inputs.begin(), inputs.end(),
                      [](Schedule  * a, Schedule * b)
                      {
                        return a->getRate() < b->getRate();
                      });

  return ((*maxRate)->getRate() * 1000) / 1000;
}

//double MaxBasalLookup(){} //TODO: change input type
