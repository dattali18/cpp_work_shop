// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#ifndef EX_10_1_OFFICER_H
#define EX_10_1_OFFICER_H

#include "Soldier.h"
#include "iostream"

class Officer: public Soldier{
private:
    int sociometricGrad;
public:
    int getSociometricGrad() const;

public:
    Officer(int id, const std::string &fName, const std::string &lName, int numOfOperation, int sociometricGrad);

    virtual std::string soldierType();

    virtual void print();

    virtual bool medal();
};


#endif //EX_10_1_OFFICER_H
