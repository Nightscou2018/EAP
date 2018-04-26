// Copyright 2018 EAP

#include "utilities/schedule.h"
#include "profile/basal/helper.h"

namespace profile {

Schedule::Schedule(int32_t index, time_t start, float rate)
:index(index), rate(rate), start(start) {}

Schedule::Schedule() {}

Schedule::~Schedule() {}

int32_t Schedule::getIndex() const {
  return index;
}

time_t Schedule::getStart() const {
  return start;
}

int32_t Schedule::getRate() const {
  return rate;
}

int32_t Schedule::getMinutes() const {
  basal::Helper helper;
  return helper.Minutes(start);
}

}  // namespace profile
