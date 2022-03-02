#include "Vector.h"
#include <cmath>
#include <iostream>

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 2.2

// THIS FUNCTION IS FOR CALCULATING THE CAPACITY OF THE VECTOR FOR A CERTAIN SIZE
int Vector::calcRequestedSize(int requested_size) {
    int res = pow(2, ceil(log(requested_size) / log(2)));
    return res;
}

// CONSTRUCTOR
Vector::Vector(int cap) {
    if (cap == 0) {
        this->size = 0;
        this->capacity = 2;
        this->data = new int[this->capacity];
        return;
    }
    this->size = 0;
    if (ceil(log2(cap)) == floor(log2(cap))) {
        this->capacity = cap;
    } else {
        this->capacity = this->calcRequestedSize(cap);
    }
    this->data = new int[this->capacity];
}

// DECONSTRUCTOR
Vector::~Vector() {
    if (this->data)
        delete [] data;
    this->data = nullptr;
}
// RETURN CAPACITY
int Vector::getCapacity() const {
    return this->capacity;
}
// RETURN SIZE

int Vector::getSize() const {
    return this->size;
}
// PRINT THE CURRENT STATE OF THE VECTOR

void Vector::print() {
    std::cout << "capacity: "<< this->capacity << " size: " << this->size << " values: ";
    for (int i = 0; i < this->size; ++i) {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}
// ASSIGN THE CALLING VECTOR THE VALUE IN THE PARAMETER VECTOR
void Vector::assign(const Vector& v) {
    this->size = v.getSize();
    this->capacity = v.getCapacity();
    this->data = new int[this->capacity];
    for (int i = 0; i < this->size; ++i) {
        this->data[i] = v.data[i];
    }
}
// EVALUATE IF TWO VECTOR ARE EQUAL (EQUALITY IS DEFINED TO BE THAT ALL THE FIELD OF BOTH OBJECT ARE EQUAL
bool Vector::isEqual(const Vector& v) {
    if (v.size != this->size) {
        return false;
    }
    for (int i = 0; i < this->size; ++i) {
        if(this->data[i] != v.data[i]) {
            return false;
        }
    }
    return true;
}
// IS USED LIKE THE [] OPERATOR (RETURN A REFERENCE TO THE VALUE AT THE CERTAIN INDEX

int & Vector::at(int index) {
    if(index >= this->size || index < 0) {
        std::cout << "ERROR" << std::endl;
        return this->data[0];
    }
    return this->data[index];
}
// RETURN THE VALUE OF THE SCALAR MULTIPLICATION BETWEEN TWO VECTOR
int Vector::scalmul(const Vector& v) {
    if (this->size != v.size) {
        std::cout << "ERROR" << std::endl;
        return -1;
    }
    int res = 0;
    for (int i = 0; i < this->size; ++i) {
        res += this->data[i] * v.data[i];
    }
    return res;
}
// CONCATENATE THE PARAMETER VECTOR TO THE CALLING VECTOR
Vector Vector::strnewcat(const Vector& v) {
    Vector newV;
    newV.size = this->size + v.size;
    newV.capacity = this->calcRequestedSize(this->capacity + v.capacity);
    newV.data = new int[newV.capacity];
    for (int i = 0; i < this->size; ++i) {
        newV.data[i] = this->data[i];
    }
    for (int i = this->size; i < this->size + v.size ; ++i) {
        newV.data[i] = this->data[i - this->size];
    }
    return newV;
}
// DELETE THE LAST VALUE IN THE VECTOR
void Vector::clear() {
    for (int i = 0; i < this->size; ++i) {
        this->data[i] = 0;
    }
    this->size = 0;
}
// DELETE THE LAST VALUE IN THE VECTOR
void Vector::delLast() {
    if(this->size == 0) {
        std::cout << "ERROR" << std::endl;
    }
    this->data[this->size - 1] = 0;
    this->size --;
}
// INSERT A VALUE IN THE VECTOR
void Vector::insert(int val) {

    if (this->capacity >= (this->size + 1)) {
        this->data[this->size] = val;
        this->size++;
    } else {
        this->capacity *= 2;
        int * help = new int[this->capacity];
        for (int i = 0; i < this->size; ++i) {
            help[i] = this->data[i];
        }
        help[(this->size)++] = val;
        delete []this->data;
        this->data = help;
    }
}
