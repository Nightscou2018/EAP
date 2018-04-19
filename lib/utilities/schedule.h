// Copyright 2018 Elviro Junior and Rick van Schijndel

#ifndef LIB_UTILITIES_SCHEDULE_H_
#define LIB_UTILITIES_SCHEDULE_H_

#include <inttypes.h>
#include <ctime>

namespace profile {

class Schedule {
 private:
    uint16_t index;
    time_t start;
    int32_t rate;

 public:
    Schedule(uint16_t index, time_t start, int16_t rate);
    Schedule(float rate, int32_t minutes);
    Schedule();
    ~Schedule();
    int32_t getIndex() const;
    time_t getStart() const;
    int32_t getRate() const;
    static int32_t NowMinutes();
};

}  // namespace profile

#endif  // LIB_UTILITIES_SCHEDULE_H_
