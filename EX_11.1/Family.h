// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 11

#ifndef EX_11_FAMILY_H
#define EX_11_FAMILY_H


#include <ostream>

class Family {
private:
    int familyNumber;
    char familyName[21];   // if the name is 20 char we need 1 char for '\0'
    int numberOfFamilyMembers;
    int telNumber;
    short classes;
public:
    Family(int familyNumber, char * familyName, int numberOfFamilyMembers, int telNumber, short classes);

    Family(int familyNumber,const char * familyName, int numberOfFamilyMembers, int telNumber, short classes);

    Family();

    Family(const Family & other);

//    setter and getter

    int getFamilyNumber() const;

    void setFamilyNumber(int familyNumber);

    const char *getFamilyName() const;

    int getNumberOfFamilyMembers() const;

    void setNumberOfFamilyMembers(int numberOfFamilyMembers);

    int getTelNumber() const;

    void setTelNumber(int telNumber);

    short getClasses() const;

    void setClasses(short classes);

    void setName(const char * name);

    std::string getName();

//    operator overloading

    void operator=(Family & other);

};


#endif //EX_11_FAMILY_H
