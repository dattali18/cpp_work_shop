#include "Point.h"

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.2

// there is no validity checking for any of the data because every number is acceptable
void Point::setX(int myX) {
    this->x = myX;
}

void Point::setY(int myY) {
    this->y = myY;
}

int Point::getX() const {
    return this->x;
}

int Point::getY() const {
    return this->y;
}
