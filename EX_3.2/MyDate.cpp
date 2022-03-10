#include "MyDate.h"
#include "iostream"

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 3.2

// USING ONLY THE FUNCTION NEEDED FROM THE std NAMESPACE
// (THE REASON IS TO NOT FORCE ON THE PERSON USING THE HEADER FILE THE CHOICE OF USING NAMESPACE std)
using std::cout;
using std::endl;

// CTOR
MyDate::MyDate(int day, int month, int year) {
    if(day < 1 || day > 30) { //  1 ≤ day ≤ 30
        cout << "ERROR day" << endl;
        this->day = 1;
    } else {
        this->day = day;
    }
    if(month < 1 || month > 12) { // 1 ≤ month ≤ 12
        cout << "ERROR month" << endl;
        this->month = 1;
    } else {
        this->month = month;
    }
    if(year < 1920) { // 1920 ≤ year
        cout << "ERROR year" << endl;
        this->year = 1920;
    } else {
        this->year = year;
    }
}

// COPY CTOR
MyDate::MyDate(const MyDate &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}
// SETTER
void MyDate::setDate(int day_, int month_, int year_) {
//    CHECKING THE VALIDITY OF THE DATE
    if(day_ < 1 || day_ > 30 || month_ < 1 || month_ > 12 || year_ < 1920) {
//        IF ONE PARAMETER OR MORE ISN'T CORRECT WE DON'T CHANGE THE DATE AT ALL
        return;
    }
    this->day = day_;
    this->month = month_;
    this->year = year_;
}
// PRINT : HELP METHODS
void MyDate::print() const {
    cout << this->day << "/" << this->month << "/" << this->year;
}
// OPERATOR OVERLOADING
// PREFIX ++ OPERATOR
MyDate & MyDate::operator++() {
    if(this->day == 30 && this->month == 12) { // IF DATE IS: 30/12/YYYY
        this->day = 1;
        this->month = 1;
        (this->year)++;
        return (*this);
    } else if(this->day == 30) { // IF DATE IS 30/MM/YYY
        this->day = 1;
        (this->month)++;
        return (*this);
    } else {
        (this->day)++;
        return (*this);
    }
}

// POSTFIX ++ OPERATOR
const MyDate MyDate::operator++(int){
    MyDate temp = (*this);
    ++(*this);
    return temp;
}

MyDate& MyDate::operator=(const MyDate &date) = default;
// GREATER THAN > OPERATOR
bool MyDate::operator>(const MyDate &date) const{
//    A DATE IS GRT IS THE YEARS IS GREATER
//    THAN THE MONTH THAN THE YEAR
    if (this->year > date.year) {
        return true;
    } else if(this->year == date.year && this->month > date.month) {
        return true;
    } else if(this->year == date.year && this->month == date.month && this ->day > date.day) {
        return true;
    }
    return false;
}
//  SMALLER THAN > OPERATOR
bool MyDate::operator<(const MyDate &date) const {
//    CHANGING THE ORDER OF OPERATION
// IN ORDER TO SAVE CODE
    return date > *this;
}
// EQUALITY == OPERATOR
bool MyDate::operator==(const MyDate &date) const {
    return (this->day == date.day && this->month == date.month && this->year == date.year);
}




