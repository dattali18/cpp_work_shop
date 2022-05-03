// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 6.2

#include "RoundList.h"
#include "iostream"
// ctor

RoundList::RoundList() : List() {
}

RoundList::~RoundList() {
    clear();
}

// methods

void RoundList::addToEnd(int value) {
    if(head == nullptr) {
        addToEmpty(value);
        return;
    }
    Link * newNode = new Link(value, head->next);
    head->next = newNode;
    head = newNode;
}

void RoundList::add(int value) {
    if(head == nullptr) {
        addToEmpty(value);
        return;
    }
    Link * newNode = new Link(value, head->next);
    head->next = newNode;
}

void RoundList::addToEmpty(int value) {
    if(head != nullptr) {
        return;
    }
    Link * newNode = new Link(value, nullptr);
    head = newNode;
    head->next = head;
}



void RoundList::clear()
{   // empty all elements from the List
    if(head == nullptr) {
        return;
//        if the list as only one element
    } else if(head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Link * ptr = head;
    Link * next;
    do {
        next = ptr->next;
        ptr->next = nullptr;
        ptr = next;
    } while(ptr != head->next);
    // mark that the List contains no elements
    head = nullptr;
}

int RoundList::search(int n) {
    if(head == nullptr) {
        return -1;
    }
    Link * ptr = head->next;
    for (int i = 0; i < n; ++i) {
        ptr = ptr->next;
    }
    return ptr->value;
}

void RoundList::removeFirst() {
//    if the list is empty
    if(head == nullptr) {
        return;
//        if the list as only one element
    } else if(head == head->next) {
        delete head;
        head = nullptr;
        return;
    }

    Link * ptr = head;
    Link * next;
    do {
        ptr = ptr->next;
    } while(ptr != head);

    next = ptr->next;
    ptr->next = ptr->next->next;
    delete next;
}
// operator overloading

ostream &operator<<(ostream &os, const RoundList &l) {
//    if the list is empty
    if(l.head == nullptr) {
        return os;
    }
    RoundList::Link * ptr = l.head->next;
    if(l.head != nullptr) {
        do {
            os << ptr->value << " ";
            ptr = ptr->next;
        } while(ptr != l.head->next);
    }
    return os;
}

