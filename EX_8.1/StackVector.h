// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 8.1

#ifndef EX_8_1_STACKVECTOR_H
#define EX_8_1_STACKVECTOR_H
#include "Vector.h"

template<typename T>
class StackVector: public Vector<T> {
public:
    // constructor requires a starting size
    explicit StackVector(unsigned int capacity);
    StackVector(const StackVector& s);


    // Stack operations
    virtual void clear();
    virtual bool isEmpty() const;
    T pop();
    void push(T value);
    T top() const;

protected:
    // data fields
    Vector<T> data;
};

template<typename T>
StackVector<T>::StackVector(unsigned int capacity):data(capacity) {

}

template<typename T>
StackVector<T>::StackVector(const StackVector &s) : data(s.data) {

}

template<typename T>
void StackVector<T>::clear() {
    data.clear();
}

template<typename T>
bool StackVector<T>::isEmpty() const {
    return (data.getSize() == 0);
}

template<typename T>
T StackVector<T>::pop() {
    if(isEmpty()) {
        throw "Stack is empty";
    }
    return data.delLast();
}

template<typename T>
void StackVector<T>::push(T value) {
    data.insert(value);
}

template<typename T>
T StackVector<T>::top() const {
    if(isEmpty()) {
        throw "Stack is empty";
    }
    return data[data.getSize() - 1];
}


#endif //EX_8_1_STACKVECTOR_H
