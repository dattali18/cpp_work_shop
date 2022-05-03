// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.1

#include "Employee.h"

#ifndef EX_6_1_FULLTIME_H
#define EX_6_1_FULLTIME_H

// declaring the FullTime class

class FullTime: public Employee {
private:
    float salaryPerYear;

//    ctor
public:

    FullTime(const string &name, int id, int seniority, float salary_per_year);

    FullTime();

    FullTime(const FullTime & emp);

//    setter and getter

    float getSalaryPerYear() const;

    void setSalaryPerYear(float salaryPerYear_);

//    methods

    void salary();

//    operator overloading
    friend ostream& operator<<(ostream& os, const FullTime& emp);

    friend istream& operator>>(istream& is, FullTime& emp);

};


#endif //EX_6_1_FULLTIME_H
