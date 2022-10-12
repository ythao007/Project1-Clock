#include "pch.h"
#include "../Project 1/Clock.h"
#include "../Project 1/Clock.cpp"


TEST(TestBasicClock, TestBasicClock) {

	Clock clock;
	EXPECT_EQ(clock.get12HourFormat(), "12:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "00:00:00");

	clock.addHour();
	EXPECT_EQ(clock.get12HourFormat(), "1:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:00:00");

	clock.addMinute();
	EXPECT_EQ(clock.get12HourFormat(), "1:01:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:01:00");

	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "1:01:01 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:01:01");
}


TEST(TestAdvancedClock, TestAdvancedClock) {
	Clock clock(1, 58, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "1:59:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:59:00");

	clock = Clock(1, 59, 59);
	clock.addMinute();
	EXPECT_EQ(clock.get12HourFormat(), "2:00:59 AM");
	EXPECT_EQ(clock.get24HourFormat(), "02:00:59");

	clock = Clock(1, 59, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "2:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "02:00:00");

	clock = Clock(12, 0, 0);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "12:00:01 PM");
	EXPECT_EQ(clock.get24HourFormat(), "12:00:01");

	clock.addMinute();
	EXPECT_EQ(clock.get12HourFormat(), "12:01:01 PM");
	EXPECT_EQ(clock.get24HourFormat(), "12:01:01");

	clock.addHour();
	EXPECT_EQ(clock.get12HourFormat(), "1:01:01 PM");
	EXPECT_EQ(clock.get24HourFormat(), "13:01:01");

	clock = Clock(11, 59, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "12:00:00 PM");
	EXPECT_EQ(clock.get24HourFormat(), "12:00:00");

	clock = Clock(23, 59, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "12:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "00:00:00");
}

