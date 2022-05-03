// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#ifndef EX_7_1_CIRCLE_H
#define EX_7_1_CIRCLE_H

#include "Shape.h"

class Circle : public Shape{
private:
    float radius;
public:
//    CTOR
    explicit Circle(float radius);
    Circle(const Circle &c);
//    METHODS
    virtual float area() const;
    virtual bool isSpecial() const;
    virtual void printSpecial() const;
};


#endif //EX_7_1_CIRCLE_H
