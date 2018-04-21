#include "schedule.h"

Schedule::Schedule(int32_t index, time_t start, float rate, int32_t minutes)
:index(index), rate(rate), minutes(minutes), start(start) {}


Schedule::Schedule(int32_t index, float rate, int32_t minutes)
:index(index), rate(rate), minutes(minutes) {
  start = NowMinutes();
}

Schedule::Schedule() {}

Schedule::~Schedule() {}

int32_t Schedule::NowMinutes() {
  time_t now = time(0);
  struct tm * timee;

  timee = gmtime(&now);

  return ((timee->tm_hour * 60) + timee->tm_min);
}

int32_t Schedule::getMinutes() {
  return minutes;
}

int32_t Schedule::getRate() {
  return rate;
}

int32_t Schedule::getIndex() {
  return index;
}

time_t Schedule::getStart() {
  return start;
}
