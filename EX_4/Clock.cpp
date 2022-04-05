#include "Clock.h"
#include "iostream"
#include "string"

using namespace std;

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 4

// getter and setter

int Clock::getHour() const {
    return hour;
}

void Clock::setHour(int hour) {
    if(hour < 0) {
        throw "Invalid time - negative number of hours.";
    } else if(hour > 24) {
        throw "Invalid time - more than 24 hours.";
    }
    this->hour = hour;
}

int Clock::getMinute() const {
    return minute;
}

void Clock::setMinute(int minute) {
    if(minute < 0) {
        throw "Invalid time - negative number of minutes.";
    } else if(minute > 60){
        throw "Invalid time - more than 60 minutes.";
    }
    this->minute = minute;
}

int Clock::getSecond() const {
    return second;
}

void Clock::setSecond(int second) {
    if(second < 0) {
        throw "Invalid time - negative number of seconds." ;
    } else if(second > 60) {
        throw "Invalid time - more than 60 seconds.";
    }
    this->second = second;
}

// ctor

Clock::Clock(int hour, int minute, int second){
//    checking for exception
    if(second < 0) {
        throw "Invalid time - negative number of seconds.";
    } else if(second > 59) {
        throw "Invalid time - more than 60 seconds.";
    } else if(minute < 0) {
        throw "Invalid time - negative number of minutes.";
    } else if(minute > 59){
        throw "Invalid time - more than 60 minutes.";
    } else if(hour < 0) {
        throw "Invalid time - negative number of hours.";
    } else if(hour > 23) {
        throw "Invalid time - more than 24 hours.";
    }
//    if no exception was thrown we assign the value to the corresponding field
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}


void Clock::operator+=(int sec) {
    // dividing the second into day, hour, minute, sec part
    int x = sec;
    int day_ = x / (60*60*24);
    x = (day_ > 0) ? x % (60*60*24) : x;
    int hour_ = x / (60*60);
    x = (hour_ > 0) ? x % (60*60) : x;
    int min_ = x / 60;
    x = (min_ > 0) ? x % 60 : x;
    int sec_ =  x;

    // adding the second to seconds etc
    int temp = this->second + sec_;

    this->second = (this->second + sec_) % 60; // the seconds are never greater than 60

    if(temp >= 60) this->minute += 1; // adding 1 min if there is an overflow in the second

    temp = this->minute + min_;

    this->minute = (this->minute + min_) % 60; // the min are never greater than 60

    if(temp >= 60) this->hour += 1; // adding 1 hour if there is an overflow in the minute

    this->hour = (this->hour + hour_) % 24;
    // we don't care about overflowing in the hour because we just change the day, and we don't have days
}

ostream &operator<<(ostream &os, const Clock &ck) {
    // using string to convert from an int to a string type
    string hh,mm,ss,time;
    hh = (ck.hour / 10 == 0) ?  "0" + to_string(ck.hour)  : to_string(ck.hour);
    mm = (ck.minute / 10 == 0) ? "0" + to_string(ck.minute) : to_string(ck.minute);
    ss = (ck.second / 10 == 0) ? "0" + to_string(ck.second) : to_string(ck.second);
    time = hh + ":" + mm + ":" + ss;
    // outputting the formatted time
    os << time << endl;
    return os;
}

istream &operator>>(istream &is, Clock &ck) {
    int hh,mm,ss;

//  getting the input from is

    is >> hh >> mm >> ss;

//    setting the value , the exception will be thrown from the setter directly
    ck.setSecond(ss);
    ck.setMinute(mm);
    ck.setHour(hh);

    return is;
}
