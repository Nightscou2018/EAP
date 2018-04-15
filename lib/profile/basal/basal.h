#ifndef __BASAL_H_
#define __BASAL_H_

#include <inttypes.h>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#include <ctime>


#include "schedule.h"
#include "helper.h"


namespace Basal
{
    int32_t BasalLookup(std::vector<Schedule*> schedules, time_t &now);
    int32_t MaxDailyBasal(std::vector<Schedule*> inputs);
    int32_t MaxBasalLookup(std::vector<Schedule*> inputs);

} // namespace Basal

#endif
