// Copyright 2018 Elviro Junior and Rick van Schijndel

#ifndef LIB_PROFILE_BASAL_HELPER_H_
#define LIB_PROFILE_BASAL_HELPER_H_

#include <inttypes.h>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

#include "utilities/schedule.h"

class Helper {
 public:
  Helper();
  ~Helper();
  std::vector<profile::Schedule*> schedule;
  int32_t Minutes(const time_t givenTime);
  time_t StringToTime(const char * now);
  void AddToSchedule(const char * start, float rate, int32_t minutes);
  std::vector<profile::Schedule*> SortSchedule(std::vector<profile::Schedule*> *schedule);
  std::vector<profile::Schedule*> GetSchedule();
};

#endif  // LIB_PROFILE_BASAL_HELPER_H_
