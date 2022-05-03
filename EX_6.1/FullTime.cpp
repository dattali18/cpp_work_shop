// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.1

#include "FullTime.h"

// ctor

FullTime:: FullTime(const string &name, int id, int seniority, float salary_per_year) : Employee(name, id, seniority) {
    salaryPerYear = salary_per_year;
    this->salary();
}

FullTime::FullTime() {
    this->setName(" ");
    this->setId(0);
    this->setSeniority(0);
    this->setPay(0);
    salaryPerYear = 0;
}

FullTime::FullTime(const FullTime &emp)  : Employee(emp) {
    salaryPerYear = emp.salaryPerYear;
}

// setter and getter

float FullTime::getSalaryPerYear() const {
    return salaryPerYear;
}

void FullTime::setSalaryPerYear(float salaryPerYear_) {
    FullTime::salaryPerYear = salaryPerYear_;
}

// calculating the salary

void FullTime::salary() {
    this->setPay(salaryPerYear / 12);
}

// operator overloading

istream &operator>>(istream &is, FullTime &emp) {
    string name;
    int id, seniority, salaryPerYears;

    std::cout << "Enter employee details:" << std::endl;

    is >> name;
    is >> id;
    is >> seniority;
    is >> salaryPerYears;

    if(seniority < 0 || salaryPerYears < 0) {
        throw "ERROR";
    }

    emp.setName(name);
    emp.setId(id);
    emp.setSeniority(seniority);
    emp.salaryPerYear = salaryPerYears;
    emp.salary();

    return is;
}

ostream &operator<<(ostream &os, const FullTime &emp) {

    os << "Employee: " << emp.getName() << std::endl;
    os << "Employee ID: " << emp.getId() << std::endl;
    os << "Years Seniority: " << emp.getSeniority()<< std::endl;
    os << "Salary per Month: " << emp.getPay() << std::endl;

    return os;
}

