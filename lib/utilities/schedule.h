#ifndef __Schedule_H_
#define __Schedule_H_

#include <ctime>
//#include <windows.h>
#include <inttypes.h>


class Schedule
{
  private:
    static int index;
    time_t start;
    int rate;
    int minutes;

  public:
    Schedule(time_t start, int rate, int minutes);
    Schedule(int rate, int minutes);
    Schedule();
    ~Schedule();
    int getMinutes();
    int getRate();
    int getIndex();
    time_t getStart();
    int NowMinutes();

};

#endif
