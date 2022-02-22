#ifndef EX_1_3_CIRCLE_H
#define EX_1_3_CIRCLE_H
#include "Point.h"

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.3

// defining the Circle class
class Circle {
private:
    Point center;
    int radius;
public:
    void setCenter(int x, int y);
    void setRadius(int myRadius);
    Point getCenter();
    int getRadius() const;
    float area() const;
    float perimeter() const;
    int onInOut(Point p);

};


#endif //EX_1_3_CIRCLE_H
