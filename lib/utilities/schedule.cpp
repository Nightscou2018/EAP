#include "schedule.h"

int32_t Schedule::index = 0;

Schedule::Schedule(time_t start, float rate, int32_t minutes)
:rate(rate),minutes(minutes),start(start)
{
  index++;
}

Schedule::Schedule(float rate, int32_t minutes)
:rate(rate),minutes(minutes)
{
  start = NowMinutes();
  index++;
}

Schedule::Schedule(){}

Schedule::~Schedule(){}

int32_t Schedule::NowMinutes(){

  time_t now = time(0);
  struct tm * timee;

  timee = gmtime(&now);

  return (timee -> tm_min);
}

int32_t Schedule::getMinutes()
{
  return minutes;
}

int32_t Schedule::getRate()
{
  return rate;
}

int32_t Schedule::getIndex()
{
  return index;
}

time_t Schedule::getStart()
{
  return start;
}
