// Created by Daniel Attali on 3/31/22.

#include "List.h"

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 5.1

List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}

List::Link::Link(const Link& source) : value(source.value), next(source.next) {}

List::List() : head(nullptr) {}

List::List(const List& l) {
    Link * src, * trg;
    if (l.head == nullptr)
        head = nullptr;
    else {
        head = new Link((l.head)->value, nullptr);
        src = l.head;
        trg = head;
        while (src->next != nullptr) {
            trg->next = new Link((src->next)->value, nullptr);
            src = src->next;
            trg = trg->next;
        }
    }
}

List::~List() {
    clear();
}

void List::clear()
{   // empty all elements from the List
    Link* next;
    for (Link * p = head; p != nullptr; p = next) {
        next = p->next;
        p->next = nullptr;
        delete p;
    }
    // mark that the List contains no elements
    head = nullptr;
}


bool List::isEmpty() const {
    return head == nullptr;
}

void List::add(int val)
{//Add a new value to the front of a Linked List
    head = new Link(val, head);
    if (head == nullptr)
        throw "failed in memory allocation";
}

int List::firstElement() const
{
    if (isEmpty())
        throw "the List is empty, no first Element";
    return head->value;
}


bool  List::search(const  int& val) const {
    // loop to test each element
    for (Link* p = head; p != nullptr; p = p->next)
        if (val == p->value)
            return true;
    // not found
    return false;
}



void List::removeFirst()
{
    // make sure there is a first element
    if (isEmpty())
        throw "the List is empty, no Elements to remove";
    // save pointer to the removed node
    Link* p = head;
    // reassign the first node
    head = p->next;
    p->next = nullptr;
    // recover memory used by the first element
    delete p;
}

// OPERATOR OVERLOADING

List &List::operator=(const List &l) {
//    using the same structure of code as the copy ctor
    Link * src, * trg;
    if(l.head == nullptr)
        head = nullptr;
    else {
       head = new Link((l.head)->value, nullptr);
        src = l.head;
        trg = head;
        while (src->next != nullptr) {
            trg->next = new Link((src->next)->value, nullptr);
            src = src->next;
            trg = trg->next;
        }
    }
    return *this;
}



ostream &operator<<(ostream &os, const List &l) {
//    printing or outputting the list in a recursive way so the list is in the right order
//    outputting from the beginning to end
    List::recPrint(os, l.head);
    return os;
}

istream &operator>>(istream &is, List &l) {
//    getting the input in descending order
    int last, current;
    is >> current;
//    l.add(current);
    do {
        last  = current;
        l.add(last);
        is >> current;
    } while (current < last);
    return is;
}

void List::insert(int key) {
    List::Link * node = new Link(key, nullptr);
//    if we need to insert at the beginning of the list
    if(head->value >= key) {
        node->next = head;
        head = node;
        return;
    }
    List::Link * current, * last;
    last = head;
    current = last->next;
//    searching the correct location for the new node
    while(current->next != nullptr && current->value < key) {
        last = current;
        current = current->next;
    }
    last->next = node;
    node->next = current;
}

void List::remove(int key) {
//    if we need to remove the first element
    if(head->value == key) {
        head = head->next;
        return;
    }
    List::Link * current, * last;
    last = head;
    current = head->next;
    // searching for the element to remove
    while(current->next != nullptr && current->value != key) {
        last = current;
        current = current->next;
    }
    // if we arrive at the end of the list, and we didn't find the element it means the element is not in the list
    if(current->next == nullptr) {
        throw "value not found";
    }
    last->next = current->next;
}

void List::recPrint(ostream& os, const List::Link *ptr) {
//    printing or outputting the list in the right order
//    from beginning to the end
    if(ptr == nullptr)
        return;
    recPrint(os, ptr->next);
    os << ptr->value << " ";
}

