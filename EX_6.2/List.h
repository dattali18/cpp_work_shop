// Created by Daniel Attali on 3/31/22.

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.2

#ifndef EX_5_1_LIST_H
#define EX_5_1_LIST_H

#include "iostream"

using namespace std;

// declaring the list class

class List {

//    declaring the nested link class
public:
    class Link
    {
    public:
        Link(const Link &); // constructor

        Link(int linkValue, Link* nextPtr);

        int value;  // data areas

        Link * next;

    };
    //end of class Link

public:
    List();  // constructors

    List(const List &);

    ~List();

//    methods

    int firstElement()  const;  // operations

    void add(int value);

    void clear();

    bool search(const int & value) const;

    bool isEmpty() const;

    void removeFirst();

//     OPERATOR OVERLOADING

    List & operator=(const List& l);

    friend ostream& operator<<(ostream& os, const List& l);

    friend istream& operator>>(istream& is, List& l);

//    METHODS

    void insert(int key);

    void remove(int key);

    static void recPrint(ostream& os,const List::Link * ptr);


protected:

    Link * head;      // data field
};


#endif //EX_5_1_LIST_H
