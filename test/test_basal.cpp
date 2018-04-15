//#include <int32_ttypes.h>

#include "gtest/gtest.h"
#include "basal.h"
#include "helper.h"

using namespace Basal;

TEST(TestBasalLookUp, NullSchedule)
{
  Helper helper;
  time_t now;
  int32_t result;
  result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);
}

/*Here we are testing if the empty valriable start2Min is initialized with the current time*/
TEST(TestBasalLookUp, NullTime)
{
  Helper helper;

  const char * start  = "00:00:00";
  const char * start1 = "11:59:00";

  time_t startMin  = helper.StringToTime(start);
  time_t start2Min = helper.StringToTime(start1);
  time_t getAtTime;

  int32_t result;

  helper.AddToSchedule(start1, 5, helper.Minutes(start2Min));
  helper.AddToSchedule(start, 2, helper.Minutes(startMin));

  result = BasalLookup(helper.GetSchedule(), getAtTime);

  EXPECT_EQ(result, -1);
}

TEST(TestBasalLookUp, BadSchedule)
{
  Helper helper;

  const char * start  = "10:20:00";
  const char * nowStr = "10:45:00";

  time_t now      = helper.StringToTime(nowStr);
  time_t startMin = helper.StringToTime(start);

  int32_t result;

  helper.AddToSchedule(start, 0.0, helper.Minutes(startMin));

  result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);
}

TEST(TestBasalLookUp, BasalNow)
{
  Helper helper;

  const char * start  = "10:00:00";
  const char * start1 = "10:20:00";
  const char * start2 = "10:25:00";
  const char * start3 = "10:30:00";
  const char * nowStr = "10:30:00";

  time_t startMin  = helper.StringToTime(start);
	time_t start1Min = helper.StringToTime(start1);
  time_t start2Min = helper.StringToTime(start2);
	time_t start3Min = helper.StringToTime(start3);
  time_t now       = helper.StringToTime(nowStr);

  helper.AddToSchedule(start , 5, helper.Minutes(startMin));
	helper.AddToSchedule(start1 , 2, helper.Minutes(start1Min));
	helper.AddToSchedule(start2 , 15, helper.Minutes(start2Min));
  helper.AddToSchedule(start3 , 1, helper.Minutes(start3Min));

  int32_t result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, 15);
}

TEST(TestBasalLookUp, minutesBiggerThanLastLog)
{
  Helper helper;

  const char * start  = "10:00:00";
  const char * start1 = "10:20:00";
  const char * nowStr = "10:21:00";

  time_t now       = helper.StringToTime(nowStr);
  time_t startMin  = helper.StringToTime(start);
  time_t start1Min = helper.StringToTime(start1);

  helper.AddToSchedule(start , 5, helper.Minutes(startMin));
	helper.AddToSchedule(start1 , 2, helper.Minutes(start1Min));

  int32_t result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);

}

TEST(TestMaxDailyBasal, emptyInput)
{
  Helper helper;
  int32_t result = MaxDailyBasal(helper.GetSchedule());

  EXPECT_EQ(result, -1);
}

TEST(TestMaxDailyBasal, correctInput)
{
  Helper helper;

  const char * start  = "10:00:00";
  const char * start1 = "10:20:00";
  const char * start2 = "10:25:00";
  const char * start3 = "10:30:00";

  time_t startMin  = helper.StringToTime(start);
	time_t start1Min = helper.StringToTime(start1);
  time_t start2Min = helper.StringToTime(start2);
	time_t start3Min = helper.StringToTime(start3);

  helper.AddToSchedule(start , 5, helper.Minutes(startMin));
	helper.AddToSchedule(start1 , 2, helper.Minutes(start1Min));
	helper.AddToSchedule(start2 , 15, helper.Minutes(start2Min));
  helper.AddToSchedule(start3 , 1, helper.Minutes(start3Min));

  int32_t result = MaxDailyBasal(helper.GetSchedule());

  EXPECT_EQ(result, 15);
}
