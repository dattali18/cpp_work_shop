// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 8.2


#include <iostream>
#include "QueueStack.h"
using namespace std;


int main() {
    Queue* Q;
    int num;
    Q = new QueueStack();
    cout << "enter 5 numbers: "<< endl;
    try {
        for (int i = 0; i < 5; i++) {
            cin >> num;
            Q->enqueue(num);
        }
    }
    catch (const char* msg)
    {
        cout << msg;
    }
    cout << "first in queue is: " << Q->front() << endl;
    cout << "removing first 2 elements:" << endl;
    cout << Q->dequeue() << ' ';
    cout << Q->dequeue() << endl;
    cout << "first in queue is: " << Q->front() << endl;
    Q->enqueue(8);
    Q->enqueue(9);
    cout << "emptying out the queue: " << endl;
    while (!Q->isEmpty())
        cout << Q->dequeue() << " ";
    cout << endl;
    return 0;
}
