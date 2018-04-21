#ifndef LIB_PROFILE_BASAL_BASAL_H_
#define LIB_PROFILE_BASAL_BASAL_H_

#include <inttypes.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <ctime>

#include "schedule.h"
#include "helper.h"


namespace LIB_PROFILE_BASAL_BASAL {
    int32_t BasalLookup(std::vector<Schedule*> schedules, time_t now);
    int32_t MaxDailyBasal(std::vector<Schedule*> inputs);
    int32_t MaxBasalLookup(std::vector<Schedule*> inputs);

}  // namespace LIB_PROFILE_BASAL_BASAL

#endif  // LIB_PROFILE_BASAL_BASAL_H_
