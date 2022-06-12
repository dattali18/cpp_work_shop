// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#ifndef EX_10_1_COMMANDER_H
#define EX_10_1_COMMANDER_H

#include "PrivateSoldier.h"

class Commander: public PrivateSoldier{
private:
    bool isCombat;
public:
    bool isCombat1() const;

public:
    Commander(int id, const std::string &fName, const std::string &lName, int numOfOperation, bool isCombat);

    Commander(int id, const std::string &fName, const std::string &lName, int numOfOperation, int *grades,
              bool isCombat);

    virtual ~Commander();

    virtual std::string soldierType();

    virtual void print();

    virtual bool medal();
};


#endif //EX_10_1_COMMANDER_H
