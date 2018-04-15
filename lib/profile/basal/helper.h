#ifndef __HELPER_H_
#define __HELPER_H_

#include <inttypes.h>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>


#include "schedule.h"

class Helper
{
    public:
      Helper();
      ~Helper();
      std::vector<Schedule*> schedule;
      int32_t Minutes(time_t &givenTime);
      time_t StringToTime(const char * now);
      void AddToSchedule(const char * start, float rate, int32_t minutes);
      std::vector<Schedule*> SortSchedule(std::vector<Schedule> &schedule);
      std::vector<Schedule*> GetSchedule();
};

#endif
