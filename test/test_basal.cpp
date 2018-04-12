#include <inttypes.h>
#include "gtest/gtest.h"
#include "basal.h"
#include "helper.h"

using namespace Basal;

TEST(TestBasalLookUp, NullSchedule)
{
  Helper helper;

  time_t now;
  double result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);
}

/*Here we are testing if the empty valriable start2Min is initialized with the current time*/
TEST(TestBasalLookUp, NullTime)
{
  Helper helper;

  const char * start = "00:00:00";
  const char * start1 = "11:59:00";

  time_t startMin = helper.StringToTime(start);
  time_t start2Min;

  helper.AddToSchedule(start1, 5, helper.Minutes(start2Min));
  helper.AddToSchedule(start, 2, helper.Minutes(startMin));

  double result = BasalLookup(helper.GetSchedule(), start2Min);

  EXPECT_EQ(result, 5);
}

TEST(TestBasalLookUp, BadSchedule)
{
  Helper helper;

  const char * start = "10:20:00";
  time_t startMin = helper.StringToTime(start);

  const char * nowStr = "10:45:00";
  time_t now = helper.StringToTime(nowStr);

  helper.AddToSchedule(start, 0.0, helper.Minutes(startMin));

  double result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);
}

TEST(TestBasalLookUp, BasalNow)
{
  Helper helper;
  const char * start = "10:00:00";
  time_t startMin = helper.StringToTime(start);

  const char * start1 = "10:20:00";
	time_t start1Min = helper.StringToTime(start1);

	const char * start2 = "10:25:00";
	time_t start2Min = helper.StringToTime(start2);

	const char * start3 = "10:30:00";
	time_t start3Min = helper.StringToTime(start3);

  helper.AddToSchedule(start , 5, helper.Minutes(startMin));
	helper.AddToSchedule(start1 , 2, helper.Minutes(start1Min));
	helper.AddToSchedule(start2 , 15, helper.Minutes(start2Min));
  helper.AddToSchedule(start3 , 1, helper.Minutes(start3Min));


  const char * nowStr = "10:30:00";
  time_t now = helper.StringToTime(nowStr);

  double result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, 15);
}

TEST(TestBasalLookUp, minutesBiggerThanLastLog)
{
  Helper helper;
  const char * start = "10:00:00";
  time_t startMin = helper.StringToTime(start);

  const char * start1 = "10:20:00";
  time_t start1Min = helper.StringToTime(start1);

  helper.AddToSchedule(start , 5, helper.Minutes(startMin));
	helper.AddToSchedule(start1 , 2, helper.Minutes(start1Min));

  const char * nowStr = "10:21:00";
  time_t now = helper.StringToTime(nowStr);

  double result = BasalLookup(helper.GetSchedule(), now);

  EXPECT_EQ(result, -1);

}
