#include "schedule.h"

int Schedule::index = 0;

Schedule::Schedule(time_t start, int rate, int minutes)
:start(start),rate(rate),minutes(minutes)
{
  index++;
}

Schedule::Schedule(int rate, int minutes)
:rate(rate),minutes(minutes)
{
  index++;
  start = Schedule::NowMinutes();
}

Schedule::~Schedule(){}

int Schedule::NowMinutes(){

  time_t now = time(0);
  struct tm * timee;

  timee = gmtime(&now);

  return (timee -> tm_min);
}

int Schedule::getMinutes()
{
  return minutes;
}

int Schedule::getRate()
{
  return rate;
}

int Schedule::getIndex()
{
  return index;
}

time_t Schedule::getStart()
{
  return start;
}
