// Copyright 2018 Elviro Junior and Rick van Schijndel

#ifndef LIB_PROFILE_BASAL_HELPER_H_
#define LIB_PROFILE_BASAL_HELPER_H_

#include <inttypes.h>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>

#include "utilities/schedule.h"

namespace profile {
namespace basal {

class Helper {
 public:
  Helper();
  ~Helper();
  std::vector<profile::Schedule*> schedule;
  int32_t Minutes(const time_t givenTime);
  time_t StringToTime(const char * now);
  void AddToSchedule(const time_t start, float rate);
  int32_t CompareMins(int32_t mins, int32_t profileMins, int32_t option);
  std::vector<profile::Schedule*> SortSchedule(std::vector<profile::Schedule*> *schedule);
  std::vector<profile::Schedule*> GetSchedule();
};

}  // namespace basal
}  // namespace profile

#endif  // LIB_PROFILE_BASAL_HELPER_H_
