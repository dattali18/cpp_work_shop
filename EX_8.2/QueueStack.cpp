// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 8.2

#include "QueueStack.h"
//  ctor
QueueStack::QueueStack() {
    data = new StackVector<int>(10);
}
//  methods
void QueueStack::clear() {
    data->clear();
}
// getting to the end of the stack by putting it into a temp stack and taking the last and putting it back
int QueueStack::dequeue() {
    StackVector<int> temp(data->getCapacity());
    while (!data->isEmpty()) {
        temp.push(data->pop());
    }
    int num = temp.pop();
    while (!temp.isEmpty()) {
        data->push(temp.pop());
    }
    return num;
}

void QueueStack::enqueue(int value) {
    data->push(value);
}

int QueueStack::front() {
    StackVector<int> temp(data->getCapacity());
    while (!data->isEmpty()) {
        temp.push(data->pop());
    }
    int num = temp.top();
    while (!temp.isEmpty()) {
        data->push(temp.pop());
    }
    return num;
}

bool QueueStack::isEmpty() const {
    return data->isEmpty();
}
