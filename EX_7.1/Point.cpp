#include "Point.h"
#include <cmath>

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

void Point::setX(int x1) {
    this->x = x1;
}

int Point::getX() const {
    return this->x;
}

void Point::setY(int y1) {
    this->y = y1;
}

int Point::getY() const {
    return this->y;
}
// using the distance formula d = sqrt((x2-x1)^2+(y2-y1)^2))
double Point::getDistance(const Point & p1) const {
    double d = sqrt(pow(p1.getX() - this->getX(), 2.0) + pow(p1.getY() - this->getY(), 2.0));
    return d;
}
// EMPTY CONSTRUCTOR
Point::Point() {
    this->x = 0;
    this->y = 0;
}
// CONSTRUCTOR
Point::Point(int x1, int y1) {
    this->x = x1;
    this->y = y1;
}
// COPY CONSTRUCTOR
Point::Point(const Point &p1) {
    this->x = p1.getX();
    this->y = p1.getY();
}

// OPERATOR OVERLOADING

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.getX() << "," << p.getY() << ") ";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    int x, y;
    char junk;
    is >> junk >> x >> junk >> y >> junk;
    p.setX(x);
    p.setY(y);

    return is;
}

bool Point::operator==(const Point &rhs) const {
    return x == rhs.x &&
           y == rhs.y;
}

bool Point::operator!=(const Point &rhs) const {
    return !(rhs == *this);
}
