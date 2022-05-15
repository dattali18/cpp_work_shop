// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 8.2

#include "Queue.h"
#include "StackVector.h"

#ifndef EX_8_2_QUEUESTACK_H
#define EX_8_2_QUEUESTACK_H

class QueueStack : public Queue
{
protected:
    StackVector<int>* data;
public:
    QueueStack();
    void clear() override;
    int dequeue() override;
    void enqueue(int value) override;
    int front() override;
    bool isEmpty() const override;
};



#endif //EX_8_2_QUEUESTACK_H
