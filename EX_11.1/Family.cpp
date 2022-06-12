// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 11

#define NONE 0
#include "Family.h"

Family::Family(int familyNumber, char * familyName, int numberOfFamilyMembers, int telNumber, short classes)
        : familyNumber(familyNumber), numberOfFamilyMembers(numberOfFamilyMembers),
          telNumber(telNumber), classes(classes) {
    int i;
    for (i = 0; familyName[i] != 0 && i < 20; ++i) {
        this->familyName[i] = familyName[i];
    }
    for (int j = i; j < 21; ++j) {
        this->familyName[j] = 0;
    }
}

Family::Family(int familyNumber,const char * familyName, int numberOfFamilyMembers, int telNumber, short classes)
        : familyNumber(familyNumber), numberOfFamilyMembers(numberOfFamilyMembers),
          telNumber(telNumber), classes(classes) {
    int i;
    for (i = 0; familyName[i] != 0 && i < 20; ++i) {
        this->familyName[i] = familyName[i];
    }
    for (int j = i; j < 21; ++j) {
        this->familyName[i] = 0;
    }
}

Family::Family() {
    familyNumber = 0;
    for (int i = 0; i < 21; ++i) {
        familyName[0] = 0;
    }
    numberOfFamilyMembers = 0;
    telNumber = 0;
    classes = NONE;
}

int Family::getFamilyNumber() const {
    return familyNumber;
}

void Family::setFamilyNumber(int familyNumber) {
    Family::familyNumber = familyNumber;
}

const char *Family::getFamilyName() const {
    return familyName;
}

int Family::getNumberOfFamilyMembers() const {
    return numberOfFamilyMembers;
}

void Family::setNumberOfFamilyMembers(int numberOfFamilyMembers) {
    Family::numberOfFamilyMembers = numberOfFamilyMembers;
}

int Family::getTelNumber() const {
    return telNumber;
}

void Family::setTelNumber(int telNumber) {
    Family::telNumber = telNumber;
}

short Family::getClasses() const {
    return classes;
}

void Family::setClasses(short classes) {
    Family::classes = classes;
}

void Family::setName(const char * name) {
    int i;
    for (i = 0; name[i] != 0 && i < 20; ++i) {
        this->familyName[i] = name[i];
    }
    for (int j = i; j < 21; ++j) {
        this->familyName[j] = 0;
    }
}

Family::Family(const Family &other) {
    this->setName(other.familyName);
    this->setClasses(other.classes);
    this->setTelNumber(other.telNumber);
    this->setNumberOfFamilyMembers(other.numberOfFamilyMembers);
    this->setFamilyNumber(other.familyNumber);
}

void Family::operator=(Family &other) {
    this->setName(other.familyName);
    this->setClasses(other.classes);
    this->setTelNumber(other.telNumber);
    this->setNumberOfFamilyMembers(other.numberOfFamilyMembers);
    this->setFamilyNumber(other.familyNumber);
}

std::string Family::getName() {
    std::string name = this->familyName;
    return name;
}






