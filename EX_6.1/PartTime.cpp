// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.1

#include "PartTime.h"

// ctor

PartTime::PartTime(const string &name, int id, int seniority, int hoursOfWork, float payPerHour) :
Employee(name, id, seniority),
hoursOfWork(hoursOfWork),
payPerHour(payPerHour) {
    this->salary();
}


PartTime::PartTime(): Employee() {
    hoursOfWork = 0;
    payPerHour = 0;
}

PartTime::PartTime(const PartTime &emp) : Employee(emp) {
    hoursOfWork = emp.hoursOfWork;
    payPerHour = emp.payPerHour;
}

// setter and getter

int PartTime::getHoursOfWork() const {
    return hoursOfWork;
}

void PartTime::setHoursOfWork(int hoursOfWork) {
    PartTime::hoursOfWork = hoursOfWork;
}

float PartTime::getPayPerHour() const {
    return payPerHour;
}

void PartTime::setPayPerHour(float payPerHour) {
    PartTime::payPerHour = payPerHour;
}

// operator overloading

ostream &operator<<(ostream &os, const PartTime &emp) {
    os << "Employee: " << emp.getName() << std::endl;
    os << "Employee ID: " << emp.getId() << std::endl;
    os << "Years Seniority: " << emp.getSeniority()<< std::endl;
    os << "Hours: " << emp.getHoursOfWork() << std::endl;
    os << "Salary per Month: " << (emp.getPayPerHour() * emp.getHoursOfWork()) << std::endl;
    return os;
}

istream &operator>>(istream &is, PartTime &emp) {
    string name;
    int id, seniority, hourOfWork, payPerHour;

    std::cout << "Enter employee details: " << std::endl;

    is >> name;
    is >> id;
    is >> seniority;
    is >> hourOfWork;
    is >> payPerHour;

    if(seniority < 0 || hourOfWork < 0) {
        throw "ERROR";
    }

    emp.hoursOfWork = hourOfWork;
    emp.payPerHour = payPerHour;
    emp.setName(name);
    emp.setId(id);
    emp.setSeniority(seniority);
    emp.salary();

    return is;
}

// methods

void PartTime::salary() {
    this->setPay(payPerHour * hoursOfWork);
}
