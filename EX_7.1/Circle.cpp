// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#include "Circle.h"


Circle::Circle(float radius) :Shape(1) {
    this->radius = radius;
}

Circle::Circle(const Circle &c) : Shape(c){
    this->radius = c.radius;
}

bool Circle::isSpecial() const {
    Point * arr = this->getPoints();
    Point center(0,0);
    if(arr[0] == center) {
        return true;
    }
    return false;
}

void Circle::printSpecial() const {
    if(Circle::isSpecial()) {
        std::cout << " A canonical circle with a radius " << radius << std::endl;
    }
}

float Circle::area() const {
    const float PI_ = 3.14;
    return PI_ * radius * radius;
}
