// Copyright 2018 Elviro Junior and Rick van Schijndel

#include "utilities/schedule.h"

namespace profile {

Schedule::Schedule(uint16_t index, time_t start, int16_t rate)
  : index(index), start(start), rate(rate) {}

Schedule::Schedule() {}

Schedule::~Schedule() {}

int32_t Schedule::NowMinutes() {
  time_t now = time(0);
  struct tm * timee;

  timee = gmtime(&now);

  return (timee -> tm_min);
}

int32_t Schedule::getIndex() const {
  return index;
}

time_t Schedule::getStart() const {
  return start;
}

int32_t Schedule::getRate() const {
  return rate;
}

}  // namespace profile
