// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 7.1

#include "Shape.h"
#include "iostream"

Shape::Shape() : numOfPoint(0), Points(nullptr) {}

Shape::Shape(int numOfPoint) {
    this->numOfPoint = numOfPoint;
    Points = new Point[numOfPoint];

    std::cout << "Enter values of " << numOfPoint << " points: " << std::endl;
    for (int i = 0; i < numOfPoint; ++i) {
        std::cin >> Points[i];
    }
}

Shape::Shape(const Shape &s) {
    this->numOfPoint = s.numOfPoint;
    this->Points = new Point[this->numOfPoint];

    for (int i = 0; i < this->numOfPoint ; ++i) {
        this->Points[i] = s.Points[i];
    }
}

Shape::Shape(Shape &&s) noexcept {
    this->numOfPoint = s.numOfPoint;
    this->Points = s.Points;

    s.Points = nullptr;
    s.numOfPoint = 0;
}

// DECTOR

Shape::~Shape() {
    delete Points ;
    Points = nullptr;
    numOfPoint = 0;
}
// OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Shape& s) {
    os << "points: ";
    for (int i = 0; i < s.numOfPoint; ++i) {
        os << s.Points[i];
    }
    return os;
}

int Shape::getNumOfPoint() const {
    return numOfPoint;
}

void Shape::setNumOfPoint(int numOfPoint) {
    Shape::numOfPoint = numOfPoint;
}

Point *Shape::getPoints() const {
    return Points;
}

void Shape::setPoints(Point *points) {
    Points = points;
}
