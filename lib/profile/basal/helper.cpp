#include "helper.h"
#include <iostream>

Helper::Helper() {}

Helper::~Helper() {
    for (unsigned int i = 0; i < schedule.size(); i++) {
        delete schedule[i];
    }
}

/* TODO(virus): test this function since is now returning the total
                amount of minutes with the hour
*/
int32_t Helper::Minutes(time_t givenTime) {
  if (givenTime == 0) {
    std::cout << "given time is now : " << "0" << std::endl;
    return -1;
  }

  struct tm * timee;
  timee = gmtime(&givenTime);

  return ((timee->tm_hour * 60) + timee->tm_min);
}

time_t Helper::StringToTime(const char * givenTime) {
  struct tm tm;
  strptime(givenTime, "%H:%M:%S", &tm);
  time_t nowConverted = mktime(&tm);

  return nowConverted;
}

void Helper::AddToSchedule(const char * start, float rate, int32_t minutes) {
  time_t begining =  StringToTime(start);
  Schedule* scheduleItem = new Schedule(begining, rate, minutes);
  schedule.push_back(scheduleItem);
}

std::vector<Schedule*> Helper::SortSchedule(std::vector<Schedule*> scheduleToSort) {
  return schedule;
}

std::vector<Schedule*> Helper::GetSchedule() {
  return schedule;
}
