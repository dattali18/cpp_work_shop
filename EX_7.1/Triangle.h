// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#ifndef EX_7_1_TRIANGLE_H
#define EX_7_1_TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape{
public:
//    CTOR
    Triangle();
//  METHODS
    virtual float area() const;
    virtual bool isSpecial() const;
    virtual void printSpecial() const;
};


#endif //EX_7_1_TRIANGLE_H
