// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.1

#ifndef EX_9_1_QUEUEVECTOR_H
#define EX_9_1_QUEUEVECTOR_H
#include "Vector.h"
#include "Queue.h"

//-------------------------------------------------------
//  class QueueVector
//  Queue implemented using vector operations
//-------------------------------------------------------
template<typename T>
class QueueVector : public Queue<T>
{
public:
    // constructor requires a starting size
    explicit QueueVector(int max);
    QueueVector(const QueueVector&);

    // implement Queue protocol
    void clear() override;
    T dequeue() override;
    void enqueue(T value) override;
    T front() const override;
    bool isEmpty() const override;

private:
    Vector<T> data;
    int tail; //current next empty place/slot (tail)
    int head; //current first place in the Q (head)
};

template<typename T>
QueueVector<T>::QueueVector(int max) :data(max + 1){
    clear();
}

template<typename T>
QueueVector<T>::QueueVector(const QueueVector & v):data(v.data), tail(v.tail), head(v.head) {

}

template<typename T>
void QueueVector<T>::clear() {
    tail = 0;
    head = 0;
}

template<typename T>
T QueueVector<T>::dequeue() {
    if(isEmpty()) throw "Queue is empty";
    int dataLoc = head;

    ++head;
    head = head % data.getCapacity();

    //++head %= data.getCapacity();

    return data[dataLoc];
}

template<typename T>
void QueueVector<T>::enqueue(T value) {
    // make sure Queue has not overflowed
    if((tail + 1) % data.getCapacity() == head)
        throw "the Queue is full";

    data[tail] = value;

    ++tail;
    tail = tail % data.getCapacity();
  //++tail%=data.getCapacity();

}

template<typename T>
T QueueVector<T>::front() const {
    if(isEmpty()) throw "Queue is empty";
    return data[head];

}

template<typename T>
bool QueueVector<T>::isEmpty() const {
    // pointing to same location as first use
    return tail == head;

}


#endif //EX_9_1_QUEUEVECTOR_H
