// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#include "Commander.h"

Commander::Commander(int id, const std::string &fName, const std::string &lName, int numOfOperation, bool isCombat)
        : PrivateSoldier(id, fName, lName, numOfOperation), isCombat(isCombat) {}

Commander::Commander(int id, const std::string &fName, const std::string &lName, int numOfOperation, int *grades,
                     bool isCombat) : PrivateSoldier(id, fName, lName, numOfOperation, grades), isCombat(isCombat) {}

std::string Commander::soldierType() {
    return {"commander"};
}

void Commander::print() {
    PrivateSoldier::print();
    std::cout << "combat: ";
    if(isCombat) {
        std::cout << "yes" << '\n';
    } else {
        std::cout << "no" << '\n';
    }
}

bool Commander::medal() {
    if(this->getNumOfOperation() >= 7) {
        int sum = 0;
        std::for_each(this->getGrades(), this->getGrades() + this->getNumOfOperation(), [&](int num){sum += num;});
        float avg = sum / this->getNumOfOperation();
        if(avg >= 90) {
            return true;
        }
    }
    return false;
}

bool Commander::isCombat1() const {
    return isCombat;
}

Commander::~Commander() {
    PrivateSoldier::~PrivateSoldier();
}



