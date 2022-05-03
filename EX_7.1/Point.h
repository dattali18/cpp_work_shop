#ifndef EX_2_1_POINT_H
#define EX_2_1_POINT_H

#include <iostream>

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

// declaring the Point class
class Point {
private:
    int x;
    int y;
public:
    // declaring the empty constructor
    Point();
    // declaring the constructor
    Point(int x1, int y1);
    // declaring the copy constructor
    Point(const Point & p1);
    // class method
    void setX(int x1);
    int getX() const;
    void setY(int y1);
    int getY() const;
    double getDistance(const Point & p1) const;

//    operator overloading
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    friend std::istream& operator>>(std::istream& is, Point& p);

    bool operator==(const Point &rhs) const;

    bool operator!=(const Point &rhs) const;
};


#endif //EX_2_1_POINT_H
