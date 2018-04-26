// Copyright 2018 Elvior Junior and Rick van Schijndel

#include "profile/basal/helper.h"

namespace profile {
namespace basal {

Helper::Helper() {}

Helper::~Helper() {
    for (unsigned int i = 0; i < schedule.size(); i++) {
        delete schedule[i];
    }
}

int32_t Helper::Minutes(const time_t givenTime) {
  if (givenTime == 0) {
    return -1;
  }

  struct tm * timee;
  timee = gmtime(&givenTime);

  return ((timee->tm_hour * 60) + timee->tm_min);
}

time_t Helper::StringToTime(const char * givenTime) {
  struct tm tm;
  strptime(givenTime, "%H:%M:%S", &tm);
  time_t givenTimeConverted = mktime(&tm);

  return givenTimeConverted;
}

int32_t Helper::CompareMins(int32_t mins, int32_t profileMins, int32_t option) {
  if (option == 0) {
    return (mins >= profileMins) ? 0 : -1;
  } else if (option == 1) {
    return (mins <= profileMins) ? 0 : -1;
  } else {
    return -1;
  }
}

void Helper::AddToSchedule(const time_t start, float rate) {
  int new_index = schedule.size();
  profile::Schedule* scheduleItem =
    new profile::Schedule(new_index, start, rate);
  schedule.push_back(scheduleItem);
}

std::vector<profile::Schedule*> Helper::SortSchedule(
    std::vector<profile::Schedule*> *scheduleTosort) {
  return schedule;
}

std::vector<profile::Schedule*> Helper::GetSchedule() {
  return schedule;
}

}  // namespace basal
}  // namespace profile
