#ifndef LIB_UTILITIES_SCHEDULE_H_
#define LIB_UTILITIES_SCHEDULE_H_

#include <inttypes.h>
#include <ctime>

class Schedule{
 private:
    int32_t index;
    int32_t rate;
    int32_t minutes;
    time_t start;

 public:
    Schedule(int32_t index, time_t start, float rate, int32_t minutes);
    Schedule(int32_t index, float rate, int32_t minutes);
    Schedule();
    ~Schedule();
    int32_t getMinutes();
    int32_t getRate();
    int32_t getIndex();
    time_t  getStart();
    int32_t NowMinutes();
};

#endif  // LIB_UTILITIES_SCHEDULE_H_
