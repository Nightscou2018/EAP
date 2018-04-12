#ifndef __BASAL_H_
#define __BASAL_H_

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <math.h>
#include <inttypes.h>
#include "schedule.h"
#include "helper.h"


namespace Basal
{
    int BasalLookup(std::vector<Schedule*> schedules, time_t &now);
    int MaxDailyBasal(std::vector<Schedule*> inputs);
    int MaxBasalLookup(std::vector<Schedule*> inputs);

} // namespace Basal

#endif
