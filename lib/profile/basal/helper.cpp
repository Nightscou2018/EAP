#include <ctime>
#include "helper.h"

Helper::Helper(){}

Helper::~Helper()
{
    for( unsigned int i = 0; i < schedule.size(); i++)
    {
        delete schedule[i];
    }
}

int Helper::Minutes(time_t &givenTime)
{
  if(givenTime == 0)
  {
    givenTime = time(0);
  }

  struct tm * timee;
  timee = gmtime(&givenTime);

  return (timee -> tm_min);
}

time_t Helper::StringToTime(const char * now)
{
  struct tm tm;
  strptime(now, "%H:%M:%S", &tm);
  time_t nowConverted = mktime(&tm);

  return nowConverted;
}

void Helper::AddToSchedule(const char * start, double rate, int minutes)
{
  time_t begining =  StringToTime(start);
  Schedule * scheduleItem = new Schedule(begining, rate, minutes);
  schedule.push_back(scheduleItem);
}

std::vector<Schedule*> Helper::SortSchedule(std::vector<Schedule> & scheduleTosort)
{
  return schedule;
}

std::vector<Schedule*> Helper::GetSchedule()
{
  return schedule;
}
