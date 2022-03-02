#ifndef EX_2_1_POLYGON_H
#define EX_2_1_POLYGON_H
#include "Point.h"

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 2.1

// declaring the Polygon class
class Polygon {
private:
    Point * pointArr;
    int size;
public:
    // declaring the empty constructor
    Polygon();
    // declaring the constructor
    explicit Polygon(int size1);
    // declaring the copy constructor
    Polygon(Polygon const &poly) ;
    // declaring the destructor
    ~Polygon();
    // class method
    int getSize() const;
    Point * getArr();
    void addPoint(const Point& p, int index);
    float getPerimeter();
    bool isEqual(const Polygon& poly);
};


#endif //EX_2_1_POLYGON_H
