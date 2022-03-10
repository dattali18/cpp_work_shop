#ifndef EX_3_3_MYSTRING_H
#define EX_3_3_MYSTRING_H

#include "iostream"
#include "string"

#pragma warning (disable:4996)

using std::ostream;
using std::istream;

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 3.3

class MyString {
private:
    int len = 0;
    char * str;
public:
    MyString() : str(nullptr), len(0) {}
    explicit MyString(const char* s); //constructor
    MyString(const MyString& ms); //copy constructor
    MyString& operator=(const MyString& ms); //assignment operator
    ~MyString(); //destructor
    MyString(MyString&& ms); // move constructor
    MyString& operator=(MyString&& ms); //move assignment operator
//    getter
    char * getStr();
//    operator overloading
    bool operator==(const MyString& ms) const;
    bool operator!=(const MyString& ms) const;
    bool operator>(const MyString& ms) const;
    bool operator<(const MyString& ms) const;
    bool operator>=(const MyString& ms) const;
    bool operator<=(const MyString& ms) const;
    MyString  operator+(const MyString& ms) const;
    MyString  operator* (const int) const;
    char & operator[](int index);
    friend ostream& operator<<(ostream& os, const MyString& ms);
    friend istream& operator>>(istream& is, MyString& ms);
//    helping methods
    MyString insert( int index, const char* str ) ;
};


#endif //EX_3_3_MYSTRING_H
