// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1

#include "PrivateSoldier.h"

PrivateSoldier::PrivateSoldier(int id, const std::string &fName, const std::string &lName, int numOfOperation)
        : Soldier(id, fName, lName, numOfOperation) {
    grades = new int[numOfOperation];
}

PrivateSoldier::PrivateSoldier(int id, const std::string &fName, const std::string &lName, int numOfOperation,
                               int *grades_) : Soldier(id, fName, lName, numOfOperation) {
    grades = new int[numOfOperation];
    for (int i = 0; i < numOfOperation; ++i) {
        grades[i] = grades_[i];
    }
}


PrivateSoldier::~PrivateSoldier() {
    delete grades;
    grades = nullptr;
//    Soldier::~Soldier();
}

std::string PrivateSoldier::soldierType() {
    return {"private"};
}

bool PrivateSoldier::medal() {
    if(this->getNumOfOperation() >= 10) {
            int sum = 0;
            std::for_each(grades, grades + this->getNumOfOperation(), [&](int num){sum += num;});
            float avg = sum / this->getNumOfOperation();
            if(avg >= 95) {
                return true;
            }
    }
    return false;
}

void PrivateSoldier::print() {
    std::cout << this->soldierType() << '\n';
    std::cout << "ID " << this->getId() << '\n';
    std::cout << "first name: " << this->getFName() << '\n';
    std::cout << "last name: " << this->getLName() << '\n';
    std::cout << "num operations: " << this->getNumOfOperation() << '\n';
    if(this->getNumOfOperation() > 0) {
        std::cout << "grades: ";
        std::for_each(grades, grades + this->getNumOfOperation(), [](int num){std::cout << num << " ";});
        std::cout << '\n';
    }
}

int *PrivateSoldier::getGrades() const {
    return grades;
}










