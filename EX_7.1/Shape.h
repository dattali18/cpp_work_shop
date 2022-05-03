// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#ifndef EX_7_1_SHAPE_H
#define EX_7_1_SHAPE_H

#include "Point.h"

class Shape {
private:
    int numOfPoint;
    Point * Points;

public:
//    CTOR
    Shape();
    explicit Shape(int numOfPoint);
    Shape(const Shape & s);
    Shape(Shape &&s) noexcept;
//    DECOTR

    virtual ~Shape();
//    OPERATOR OVERLOADING
    friend std::ostream& operator<<(std::ostream& os, const Shape& s);

    //    VIRTUAL METHODS

    virtual float area() const = 0;
    virtual bool isSpecial() const = 0;
    virtual void printSpecial() const = 0;

//    SETTER AND GETTER
    int getNumOfPoint() const;

    void setNumOfPoint(int numOfPoint);

    Point *getPoints() const;

    void setPoints(Point *points);
};


#endif //EX_7_1_SHAPE_H
