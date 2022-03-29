#ifndef EX_4_1_CLOCK_H
#define EX_4_1_CLOCK_H

#include <iostream>

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 4

using namespace std;

// declaring the clock class

class Clock {
private:
    int hour = 0;
    int minute = 0;
    int second = 0;
public:
//    getter and setter

    int getHour() const;

    void setHour(int hour);

    int getMinute() const;

    void setMinute(int minute);

    int getSecond() const;

    void setSecond(int second);

//    ctor
    Clock(int hour, int minute, int second);

//    operator overloading
    void operator+=(int sec);

    friend ostream& operator<<(ostream& os, const Clock& ck);

    friend istream& operator>>(istream& is, Clock& ck);
};


#endif //EX_4_1_CLOCK_H
