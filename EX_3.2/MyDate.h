#ifndef EX_3_2_MYDATE_H
#define EX_3_2_MYDATE_H

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 3.2

// DECLARING THE MyDate CLASS
class MyDate {
private:
//    THE FIELD OF THE CLASS
    int day;
    int month;
    int year;
public:
//    CTOR
    MyDate(int day = 1, int month = 1, int year = 1920);
//  COPY CTOR
    MyDate(const MyDate& date);
//    SETTER
    void setDate(int day_, int month_, int year_);
//    OPERATION OVERLOADING
    MyDate& operator=(const MyDate& date);
    MyDate& operator++();
    const MyDate operator++(int);
    bool operator>(const MyDate& date) const;
    bool operator<(const MyDate& date) const;
    bool operator==(const MyDate& date) const;
//    HELPING METHODS
    void print() const;

};


#endif //EX_3_2_MYDATE_H
