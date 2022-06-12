// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#include "Officer.h"

Officer::Officer(int id, const std::string &fName, const std::string &lName, int numOfOperation, int sociometricGrad)
        : Soldier(id, fName, lName, numOfOperation), sociometricGrad(sociometricGrad) {}

std::string Officer::soldierType() {
    return {"officer"};
}

void Officer::print() {
    std::cout << this->soldierType() << '\n';
    std::cout << "ID: " << this->getId() << '\n';
    std::cout << "first name: " << this->getFName() << '\n';
    std::cout << "last name: " << this->getLName() << '\n';
    std::cout << "num operations: " << this->getNumOfOperation() << '\n';
    std::cout << "sociometric score: " << sociometricGrad << '\n';
}


bool Officer::medal() {
    if(this->getNumOfOperation() > 2 && sociometricGrad >= 92) {
        return true;
    }
    return false;
}

int Officer::getSociometricGrad() const {
    return sociometricGrad;
}