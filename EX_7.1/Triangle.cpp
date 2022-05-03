// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#include "Triangle.h"
#include "cmath"

// CTOR
Triangle::Triangle() :Shape(3) {}


// METHODS
bool Triangle::isSpecial() const {
    Point * arr = this->getPoints();
    if (arr[0].getDistance(arr[1]) == arr[0].getDistance(arr[2]) && arr[1].getDistance(arr[2]) == arr[0].getDistance(arr[2])) {
        return true;
    }
    return false;
}

void Triangle::printSpecial() const {
    Point * arr = this->getPoints();
    if(this->isSpecial()) {
        std::cout << "An equilateral triangle with a side length " << arr[0].getDistance(arr[1]) << std::endl;
    }
}

float Triangle::area() const {
    Point * arr = this->getPoints();

    float side1 = arr[0].getDistance(arr[1]);
    float side2 = arr[0].getDistance(arr[2]);
    float side3 = arr[1].getDistance(arr[2]);
    float s = (side1 + side2 + side3) / 2;
    float area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    return area;
}
