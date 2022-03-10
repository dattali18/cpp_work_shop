#include "MyString.h"
#include "iostream"
#include "cstring"

using namespace std;
#pragma warning (disable:4996)

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 3.3

// code from GitHub
// ctor
MyString::MyString(const char* s)
{
    if (s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    else
        str = nullptr;
}
// ctor
MyString::MyString(const MyString& ms) : MyString(ms.str) {}


MyString& MyString::operator=(const MyString& ms)
{
    len = ms.len;

    if (str)
        delete[] str;

    if (ms.str)
    {
        len = strlen(ms.str);
        str = new char[len + 1];
        strcpy(str, ms.str);
    }
    else
        str = nullptr;
    return *this;
}

MyString::~MyString()
{
    if (str) //very important!!!
        delete[] str;
    str = nullptr;
}

MyString MyString::operator+(const MyString& ms) const
{
    int sizeI = len;
    int sizeII = ms.len;
    char* temp = new char[sizeI + sizeII + 1];

    strcpy(temp, str);
    strcpy(temp + sizeI, ms.str);

    MyString x(temp);
    return x;
}

bool MyString::operator==(const MyString& ms) const
{
    return !strcmp(str, ms.str);
}
MyString MyString::operator*(const int num) const
{
    char* temp;
    temp = new char[len * num + 1];

    for (int i = 0; i < num; i++)
        strcpy(temp + i * len, str);

    MyString s(temp);
    return s;
}

ostream& operator<<(ostream& os, const MyString& ms)
{
    if (ms.str)
        os << ms.str << endl;
    return os;
}

istream& operator>>(istream& is, MyString& ms)
{
    is >> ms.len;

    ms.str = new char[ms.len + 1];
    is >> ms.str;

    return  is;
}

MyString::MyString(MyString&& ms)
{  // move constructor

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr; //very important!!!
    cout << "move ctor" << endl;
}



MyString& MyString::operator=(MyString&& ms)
{ // move assignment operator

    if (str)
        delete[] str;

    len = ms.len;
    str = ms.str; // steal (dont copy) rvalue's data
    ms.str = nullptr;
    cout << "move assign" << endl;;
    return *this;
}

// from here it's my code

bool MyString::operator!=(const MyString &ms) const {
//    inverting the boolean value
    return !(*this == ms);
}

bool MyString::operator>(const MyString &ms) const {
//    using strcmp from cstring
    int cmp = strcmp(str, ms.str);
    if (cmp > 0) {
        return true;
    } else {
        return false;
    }
}

bool MyString::operator<(const MyString &ms) const {
//    inverting the caller and parameter
    return (ms > *this);
}

bool MyString::operator>=(const MyString &ms) const {
//    using the already existing operator
    return (*this > ms || *this == ms);
}

bool MyString::operator<=(const MyString &ms) const {
//    using the already existing operator
    return  (*this < ms || *this == ms);;
}

char &MyString::operator[](int index) {
//    if the index is out of range
    if(index >= this->len) {
        cout << "ERROR" << endl;
        exit(0);
    }
    return this->str[index];
}

MyString MyString::insert(int index, const char *str) {
//    if the index is out of range
    if (index > this->len) {
        cout << "ERROR" << endl;
//        printing that, because the Way I built the function it doesn't need the move ctor
        cout << "move ctor" << endl;
        return MyString();
    }
    int strLen = strlen(str);
    MyString cpyStr;
    cpyStr.len = (this->len + strLen);
    cpyStr.str = new char[cpyStr.len];
//    copying first third
    for (int i = 0; i < index; ++i) {
        cpyStr.str[i] = this->str[i];
    }
//    copying second third, the str
    for (int i = index; i < index + strLen; ++i) {
        cpyStr.str[i] = str[i - index];
    }
//    copying the rest of the caller string
    for (int i = index + strLen; i < cpyStr.len; ++i) {
        cpyStr.str[i] = this->str[i - strLen];
    }
    return cpyStr;
}
// for my use
char *MyString::getStr() {
    char * str = new char[this->len];
    strcpy(str, this->str);
    return str;
}
