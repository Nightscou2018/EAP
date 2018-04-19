// Copyright 2018 Elviro Junior and Rick van Schijndel

#ifndef LIB_PROFILE_BASAL_BASAL_H_
#define LIB_PROFILE_BASAL_BASAL_H_

#include <math.h>
#include <inttypes.h>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include "utilities/schedule.h"
#include "profile/basal/helper.h"

namespace profile {
namespace basal {

int32_t BasalLookup(const std::vector<Schedule*> &schedules, const time_t now);
int32_t MaxDailyBasal(const std::vector<Schedule*> &inputs);
int32_t MaxBasalLookup(const std::vector<Schedule*> &inputs);

}  // namespace basal
}  // namespace profile

#endif  // LIB_PROFILE_BASAL_BASAL_H_
