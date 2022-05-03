// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.1

#ifndef EX_6_1_EMPLOYEE_H
#define EX_6_1_EMPLOYEE_H

#include "iostream"
#include "string"

using std::string;
using std::istream;
using std::ostream;

// declaring the father class Employee

class Employee {
private:
    string name;
    int id;
    int seniority;
    float pay;

public:
//    ctor
    Employee(const string &name, int id, int seniority);

    Employee();

    Employee(const Employee & emp);

//    setter and getter
    const string &getName() const;

    void setName(const string &name_);

    int getId() const;

    void setId(int id_);

    int getSeniority() const;

    void setSeniority(int seniority_);

    float getPay() const;

    void setPay(float pay_);

//  methods

    int salaryAfterBonus();

//    operator overloading

    friend ostream& operator<<(ostream& os, const Employee& emp);

    friend istream& operator>>(istream& is, Employee& emp);
};


#endif //EX_6_1_EMPLOYEE_H
