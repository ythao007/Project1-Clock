#include "Clock.h"
#include <iostream>

Clock::Clock() {
    this->hours = 0;
    this->minutes = 0;
    this->seconds = 0;
}

Clock::Clock(int hours, int minutes, int seconds) {
    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void Clock::addHour() {
    if (hours == 23) { // This condition does not exceed 23 hours
        hours = 0; // Hours will return to 0 after 23 hours
    }
    else {
        hours++; // Increments the hour by 1
    }
}

void Clock::addMinute() {
    if (minutes == 59) { // This condition does not exceed 59 minutes
        minutes = 0; // Minutes will return to 0 after 59
        addHour(); // Calls the addHour method for incrementing the hour
    }
    else {
        minutes++; // Increments the minutes by 1
    }
}

void Clock::addSecond() {
    if (seconds == 59) { // This condition does not exceed 59 seconds
        seconds = 0; // Seconds will return to 0 after 59
        addMinute(); // Calls the addMinute method for incrementing the minute
    }
    else {
        seconds++; // Increment seconds by 1
    }
}

string Clock::get24HourFormat() {
    string time = " "; // Variable concatenated format to a string

    time = pad(hours) + ":" + pad(minutes) + ":" + pad(seconds); // What clock display will look like
    
    return time; // Return clock format
}

string Clock::get12HourFormat() {
    int tempHours = hours; // Variable for temp hours so it doesn't override hours variable
    string amPm = " "; // Get AM or PM depending on time put in
    string time = " "; // Variable for concatenated format to a string

    if (tempHours == 0) { // If hour is 0, clock reads 12 AM
        tempHours = 12;
        amPm = " AM";
    }
    else if (tempHours == 12) { // If hour is 12, clock reads 12 PM
        tempHours = 12;
        amPm = " PM";
    }

    if (tempHours < 12) {
        amPm = " AM";       // If hour is less than 12, it is AM
    }
    else if (tempHours != 12) { // If hour does not eaqual 12
        tempHours = tempHours - 12; // Subtract 12 to get time
        amPm = " PM";       // If more than 12, it is PM
    }

    time = pad(tempHours) + ":" + pad(minutes) + ":" + pad(seconds) + amPm; // What clock display will look like

    return time; // Return clock format
}

string Clock::pad(int value) {
  
    if (value < 10) { // If the value is less than 10
        return "0" + to_string(value); // Add "0" in front of value and return this value
    }
    else {
        return to_string(value); // Otherwise, just return the value
    }
    return  to_string(value); // Return value as a string
}
