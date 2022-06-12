// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 9.1

#ifndef EX_8_2_QUEUE_H
#define EX_8_2_QUEUE_H

template<typename T>
class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(T value) = 0;
    virtual T dequeue() = 0;
    virtual T front () const  = 0;
    virtual bool isEmpty() const = 0;
};



#endif //EX_8_2_QUEUE_H
