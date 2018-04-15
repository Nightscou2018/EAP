#ifndef __Schedule_H_
#define __Schedule_H_

#include <ctime>
#include <inttypes.h>


class Schedule
{
  private:
    static int32_t index;
    int32_t rate;
    int32_t minutes;
    time_t start;

  public:
    Schedule(time_t start, float rate, int32_t minutes);
    Schedule(float rate, int32_t minutes);
    Schedule();
    ~Schedule();
    int32_t getMinutes();
    int32_t getRate();
    int32_t getIndex();
    time_t  getStart();
    int32_t NowMinutes();

};

#endif
