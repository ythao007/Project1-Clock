#pragma once
#include <string>
using namespace std;

class Clock
{
	public:
		Clock();
		Clock(int, int, int);
		void addHour();
		void addSecond();
		void addMinute();
		string get12HourFormat();
		string get24HourFormat();

	private:
		int hours;
		int minutes;
		int seconds;
		string pad(int);
};

