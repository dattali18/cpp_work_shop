// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#include "Rectangle.h"

Rectangle::Rectangle() : Shape(4) {}


bool Rectangle::isSpecial() const {
    Point * arr = this->getPoints();
    if (arr[0].getDistance(arr[1]) == arr[1].getDistance(arr[2])
    && arr[1].getDistance(arr[2]) == arr[2].getDistance(arr[3])
    && arr[2].getDistance(arr[3]) == arr[3].getDistance(arr[0])){
        return true;
    }
    return false;
}

void Rectangle::printSpecial() const {
    Point * arr = this->getPoints();
    if (Rectangle::isSpecial()) {
        std::cout << "Square with side length " << arr[0].getDistance(arr[1]) << std::endl;
    }
}

float Rectangle::area() const {
    Point * arr = this->getPoints();
    return arr[0].getDistance(arr[1]) * arr[1].getDistance(arr[2]);
}
