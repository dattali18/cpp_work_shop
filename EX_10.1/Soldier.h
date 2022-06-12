// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#ifndef EX_10_1_SOLDIER_H
#define EX_10_1_SOLDIER_H

#include "string"

class Soldier {
private:
    int id;

    std::string fName;

    std::string lName;

    int numOfOperation;

public:
    Soldier(int id, const std::string &fName, const std::string &lName, int numOfOperation) : id(id), fName(fName),
                                                                                              lName(lName),
                                                                                              numOfOperation(
                                                                                                      numOfOperation) {};
//    virtual ~Soldier();

    virtual bool medal() = 0;

    virtual void print() = 0;

    virtual std::string soldierType() = 0;

    int getId() const {
        return id;
    }

    const std::string &getFName() const {
        return fName;
    }

    const std::string &getLName() const {
        return lName;
    }

    int getNumOfOperation() const {
        return numOfOperation;
    }
};



#endif //EX_10_1_SOLDIER_H
