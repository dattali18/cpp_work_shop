// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.1

#ifndef EX_6_1_PARTTIME_H
#define EX_6_1_PARTTIME_H

#include "Employee.h"


// declaring the PartTime class

class PartTime : public Employee   {
private:
    int hoursOfWork;
    float payPerHour;

public:

//    ctor

    PartTime(const string &name, int id, int seniority, int hoursOfWork, float payPerHour);

    PartTime();

    PartTime(const PartTime & emp);

// operator overloading

    friend ostream& operator<<(ostream& os, const PartTime& emp);

    friend istream& operator>>(istream& is, PartTime& emp);

//    setter and getter
    int getHoursOfWork() const;

    void setHoursOfWork(int hoursOfWork);

    float getPayPerHour() const;

    void setPayPerHour(float payPerHour);

//    methods

    void salary();

};


#endif //EX_6_1_PARTTIME_H
