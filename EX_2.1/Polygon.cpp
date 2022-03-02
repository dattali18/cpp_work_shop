#include "Polygon.h"
#include "iostream"

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 2.1

// EMPTY CONSTRUCTOR
Polygon::Polygon() {
    this->pointArr = nullptr;
    this->size = 0;
    std::cout << "in empty constructor\n";
}
// CONSTRUCTOR
Polygon::Polygon(const Polygon &poly) {
    this-> size = poly.getSize();
    this->pointArr = new Point[this->size];
    for (int i = 0; i < this->size; ++i) {
        this->pointArr[i] = poly.pointArr[i];
    }
    std::cout << "in copy constructor\n";
}
// COPY CONSTRUCTOR
Polygon::Polygon(int size1) {
    this->size = size1;
    this->pointArr = new Point[size1];
    std::cout << "in one parameter constructor\n";
}
// DESTRUCTOR
Polygon::~Polygon() {
    delete []pointArr;
    std::cout << "in destructor\n";
}

int Polygon::getSize() const {
    return this->size;
}
// returning a new array
Point *Polygon::getArr() {
    Point * newArr = new Point[this->size];
    for (int i = 0; i < this->size; ++i) {
        newArr[i] = this->pointArr[i];
    }
    return newArr;
}
// in this function I'm assuming that the amount of sides in the polygon
// do not change each time we call the method
void Polygon::addPoint(const Point& p, int index) {
    this->pointArr[index] = p;
}
// calculating the total perimeter
float Polygon::getPerimeter() {
    float totalPerimeter = 0;
    for (int i = 0; i < this->size - 1; ++i) {
//        std::cout << i << " " << i+1 << '\n';
        totalPerimeter += this->pointArr[i].getDistance(this->pointArr[i+1]);
    }
    // adding the distance between the first and last point
    totalPerimeter += this->pointArr[0].getDistance(this->pointArr[this->size - 1]);
    return totalPerimeter;
}
// checking if two polygons are equal
bool Polygon::isEqual(const Polygon& poly) {
    // if the size is not equal the polygon aren't equal
    if(this->size != poly.getSize()) {
        return false;
    }
    int count = 0;
    // checking for each Point if the x and y field are equal
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < poly.size; ++j) {
            if(this->pointArr[i].getX() == poly.pointArr[j].getX() && this->pointArr[i].getY() == poly.pointArr[j].getY()) {
                count ++;
                continue;
            }
        }
    }
    // if the total point that are shared between the two polygon
    if (count == this->size) {
        return true;
    }
    return false;
}






