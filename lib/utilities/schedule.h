// Copyright 2018 EAP

#ifndef LIB_UTILITIES_SCHEDULE_H_
#define LIB_UTILITIES_SCHEDULE_H_

#include <inttypes.h>
#include <ctime>

namespace profile {

class Schedule {
 private:
    int32_t index;
    int32_t rate;
    time_t start;

 public:
    Schedule(int32_t index, time_t start, float rate);
    Schedule();
    ~Schedule();
    int32_t getMinutes() const;
    int32_t getRate() const;
    int32_t getIndex() const;
    time_t  getStart() const;
};

}  // namespace profile

#endif  // LIB_UTILITIES_SCHEDULE_H_
