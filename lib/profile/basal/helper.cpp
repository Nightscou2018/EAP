// Copyright 2018 Elvior Junior and Rick van Schijndel

#include "profile/basal/helper.h"

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

  return (timee -> tm_min);
}

time_t Helper::StringToTime(const char * now) {
  struct tm tm;
  strptime(now, "%H:%M:%S", &tm);
  time_t nowConverted = mktime(&tm);

  return nowConverted;
}

void Helper::AddToSchedule(const char * start, float rate, int32_t minutes) {
  time_t begining =  StringToTime(start);
  profile::Schedule* scheduleItem =
    new profile::Schedule(begining, rate, minutes);
  schedule.push_back(scheduleItem);
}

std::vector<profile::Schedule*> Helper::SortSchedule(
    std::vector<profile::Schedule*> *scheduleTosort) {
  return schedule;
}

std::vector<profile::Schedule*> Helper::GetSchedule() {
  return schedule;
}
