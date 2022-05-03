// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.2

#ifndef EX_6_2_ROUNDLIST_H
#define EX_6_2_ROUNDLIST_H

#include "List.h"

class RoundList: public List {
public:
//    ctor
    RoundList();

    ~RoundList();
//    methods
    void add(int value);

    void addToEmpty(int value);

    void addToEnd(int value);

    void clear();

    int search(int n);

    void removeFirst();

//    operator overloading

    friend ostream& operator<<(ostream& os, const RoundList& l);
};


#endif //EX_6_2_ROUNDLIST_H
