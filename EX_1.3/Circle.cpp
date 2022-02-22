#include "Circle.h"
#include "cmath"
// defining the var PI to bo 3.14 for further use
#define PI 3.14

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.2

void Circle::setCenter(int x, int y) {
    this->center.setX(x);
    this->center.setY(y);
}

void Circle::setRadius(int myRadius) {
    // checking the validity of the data
    if(myRadius <= 0) {
        // if the data is not valid the default radius is 1
        this->radius = 1;
    } else {
        this->radius = myRadius;
    }
}

Point Circle::getCenter() {
    return this->center;
}

int Circle::getRadius() const {
    return this->radius;
}

float Circle::area() const {
    return PI * (this->radius * this->radius);
}

float Circle::perimeter() const {
    return PI * 2 * this->radius;
}

int Circle::onInOut(Point p) {
    // using the distance formula between two point
    float distance = sqrt(pow(p.getX() - this->center.getX(),2) + pow(p.getY() - this->center.getY(),2));
    // if d = r the point is on the circle
    if (distance == this->radius) {
        return 0;
    // if the d > r the point is out of the circle
    } else if (distance > this->radius) {
        return 1;
    // if the d < r the point is in the circle
    } else {
        return -1;
    }
}
