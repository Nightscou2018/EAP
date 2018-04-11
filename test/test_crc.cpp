#include "gtest/gtest.h"
#include "crc.h"
#include <inttypes.h>

using namespace Validation;

TEST(TestCRC, OnlyZero)
{
  uint8_t input = 0x00;
  uint8_t result = CRC8WCDMA(&input, 1);

  EXPECT_EQ(result, 0x00);
}

TEST(TestCRC, SingleValue)
{
  uint8_t input = 0x5C;
  uint8_t result = CRC8WCDMA(&input, 1);

  EXPECT_EQ(result, 0x47);
}

TEST(TestCRC, MultiValueIdentical)
{
  uint8_t input[] = { 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55 };
  uint8_t result = CRC8WCDMA(input, sizeof(input) / sizeof(input[0]));

  EXPECT_EQ(result, 0x56);
}

TEST(TestCRC, MultiValueDifferentValues)
{
  uint8_t input[] = { 0x81, 0x72, 0x63, 0x54, 0x45, 0x36, 0x27, 0x18 };
  uint8_t result = CRC8WCDMA(input, sizeof(input) / sizeof(input[0]));

  EXPECT_EQ(result, 0x8B);
}

TEST(TestCRC, ConsecutiveExecution)
{
  uint8_t input[] = { 0x81, 0x72, 0x63, 0x54, 0x45, 0x36, 0x27, 0x18 };
  uint8_t size    =  sizeof(input) / sizeof(input[0]);


  EXPECT_EQ(CRC8WCDMA(input, size), 0x8B);
  EXPECT_EQ(CRC8WCDMA(input, size), 0x8B);
  EXPECT_EQ(CRC8WCDMA(input, size), 0x8B);
  EXPECT_EQ(CRC8WCDMA(input, size), 0x8B);
}
