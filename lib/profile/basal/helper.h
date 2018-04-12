#ifndef __HELPER_H_
#define __HELPER_H_

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

#include "schedule.h"

class Helper
{
    public:
      Helper();
      ~Helper();
      std::vector<Schedule*> schedule;
      int Minutes(time_t &givenTime);
      time_t StringToTime(const char * now);
      void AddToSchedule(const char * start, double rate, int minutes);
      std::vector<Schedule*> SortSchedule(std::vector<Schedule> &schedule);
      std::vector<Schedule*> GetSchedule();
};

#endif
