#ifndef LIB_PROFILE_BASAL_HELPER_H_
#define LIB_PROFILE_BASAL_HELPER_H_

#include <inttypes.h>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>


#include "schedule.h"

class Helper{
 public:
      Helper();
      ~Helper();
      std::vector<Schedule*> schedule;
      int32_t Minutes(time_t givenTime);
      time_t StringToTime(const char * now);
      int32_t CompareMins(int32_t&, int32_t&, int32_t&);
      void AddToSchedule(const char * start, float rate, int32_t minutes);
      std::vector<Schedule*> SortSchedule(std::vector<Schedule*> schedule);
      std::vector<Schedule*> GetSchedule();
};

#endif  // LIB_PROFILE_BASAL_HELPER_H_
