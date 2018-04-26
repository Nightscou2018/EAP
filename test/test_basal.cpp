// Copyright 2018 EAP

#include "gtest/gtest.h"
#include "profile/basal/basal.h"
#include "profile/basal/helper.h"

TEST(TestBasalLookUp, NullSchedule) {
  profile::basal::Helper helper;
  time_t givenTime = time(0);
  int32_t result;
  result = profile::basal::BasalLookup(helper.GetSchedule(), givenTime);

  EXPECT_EQ(result, -1);
}

TEST(TestBasalLookUp, NullTime) {
  profile::basal::Helper helper;

  const char * start = "00:00:00";
  const char * start1 = "11:59:00";

  time_t givenTime = 0;

  int32_t result;

  helper.AddToSchedule(helper.StringToTime(start), 5);
  helper.AddToSchedule(helper.StringToTime(start1), 2);

  result = profile::basal::BasalLookup(helper.GetSchedule(), givenTime);

  EXPECT_EQ(result, -1);
}

TEST(TestBasalLookUp, BadSchedule) {
  profile::basal::Helper helper;

  const char * start = "10:20:00";
  const char * nowStr = "10:45:00";

  time_t givenTime = helper.StringToTime(nowStr);

  int32_t result;

  helper.AddToSchedule(helper.StringToTime(start), 0.0);

  result = profile::basal::BasalLookup(helper.GetSchedule(), givenTime);

  EXPECT_EQ(result, -1);
}

TEST(TestBasalLookUp, BasalGivenTime) {
  profile::basal::Helper helper;

  const char * start  = "10:00:00";
  const char * start1 = "10:20:00";
  const char * start2 = "10:25:00";
  const char * start3 = "10:30:00";

  const char * nowStr = "10:29:00";

  time_t givenTime = helper.StringToTime(nowStr);

  helper.AddToSchedule(helper.StringToTime(start), 5);
  helper.AddToSchedule(helper.StringToTime(start1), 2);
  helper.AddToSchedule(helper.StringToTime(start2), 15);
  helper.AddToSchedule(helper.StringToTime(start3), 1);

  int32_t result = profile::basal::BasalLookup(helper.GetSchedule(), givenTime);

  EXPECT_EQ(result, 15);
}

TEST(TestBasalLookUp, MinutesBiggerThanLastLog) {
  profile::basal::Helper helper;

  const char * start = "10:00:00";
  const char * start1 = "10:20:00";
  const char * nowStr = "10:21:00";

  time_t now = helper.StringToTime(nowStr);

  helper.AddToSchedule(helper.StringToTime(start), 5);
  helper.AddToSchedule(helper.StringToTime(start1), 2);

  int32_t result = profile::basal::BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);
}

TEST(TestMaxDailyBasal, emptyInput) {
  profile::basal::Helper helper;
  int32_t result = profile::basal::MaxDailyBasal(helper.GetSchedule());

  EXPECT_EQ(result, -1);
}

TEST(TestMaxDailyBasal, CorrectInput) {
  profile::basal::Helper helper;

  const char * start = "10:00:00";
  const char * start1 = "10:20:00";
  const char * start2 = "10:25:00";
  const char * start3 = "10:30:00";

  helper.AddToSchedule(helper.StringToTime(start), 5);
  helper.AddToSchedule(helper.StringToTime(start1), 2);
  helper.AddToSchedule(helper.StringToTime(start2), 15);
  helper.AddToSchedule(helper.StringToTime(start3), 1);

  int32_t result = profile::basal::MaxDailyBasal(helper.GetSchedule());

  EXPECT_EQ(result, 15);
}
