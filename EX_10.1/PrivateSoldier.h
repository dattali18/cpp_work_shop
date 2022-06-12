// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#ifndef EX_10_1_PRIVATESOLDIER_H
#define EX_10_1_PRIVATESOLDIER_H

#include "Soldier.h"
#include "iostream"

class PrivateSoldier: public Soldier {
private:
    int * grades;
public:
    int *getGrades() const;

public:
    PrivateSoldier(int id, const std::string &fName, const std::string &lName, int numOfOperation);

    PrivateSoldier(int id, const std::string &fName, const std::string &lName, int numOfOperation, int *grades);

    virtual ~PrivateSoldier();

    virtual bool medal();

    virtual void print();

    virtual std::string soldierType();
};


#endif //EX_10_1_PRIVATESOLDIER_H
