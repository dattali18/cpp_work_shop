// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.1

#include "Employee.h"
#include "iostream"

using std::endl;
using std::cout;

// ctor

Employee::Employee(const string &name, int id, int seniority) : name(name), id(id), seniority(seniority) {
    pay = 0.0f;
}

Employee::Employee() {
    name = "";
    id = 0;
    seniority = 0;
    pay = 0.0f;
}

Employee::Employee(const Employee &emp) {
    name = emp.name;
    id = emp.id;
    seniority = emp.seniority;
    pay = emp.pay;
}

// setter and getter

const string &Employee::getName() const {
    return name;
}

void Employee::setName(const string &name_) {
    Employee::name = name_;
}

int Employee::getId() const {
    return id;
}

void Employee::setId(int id_) {
    Employee::id = id_;
}

int Employee::getSeniority() const {
    return seniority;
}

void Employee::setSeniority(int seniority_) {
    Employee::seniority = seniority_;
}

float Employee::getPay() const {
    return pay;
}

void Employee::setPay(float pay_) {
    Employee::pay = pay_;
}


// operator overloading

ostream &operator<<(ostream &os, const Employee &emp) {
    os << "Employee:\t" << emp.name << endl;
    os << "Employee ID:\t" << emp.id << endl;
    os << "Years Seniority:\t" << emp.seniority << endl;
    return os;
}

istream &operator>>(istream &is, Employee &emp) {
    cout << "Enter employee details:" << endl;

    string name;
    int id, seniority, pay;

    is >> name;
    is >> id;
    is >> seniority;
    is >> pay;

    if(seniority < 0 || pay < 0) {
        throw "ERROR";
    }

    emp.name = name;
    emp.id = id;
    emp.seniority = seniority;
    emp.pay = pay;

    return is;
}

// methods

int Employee::salaryAfterBonus() {
    if(seniority <= 5) {
        return (this->pay + 500);
    } else {
        return (this->pay * 1.25);
    }
}
