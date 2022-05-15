//
// Created by Daniel Attali on 5/15/22.
//

#ifndef EX_8_2_QUEUE_H
#define EX_8_2_QUEUE_H


class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front ()  = 0;
    virtual bool isEmpty() const = 0;
};



#endif //EX_8_2_QUEUE_H
