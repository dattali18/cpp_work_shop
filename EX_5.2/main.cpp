#include <iostream>
#include "List.h"

using namespace std;

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 5.2

// this program test three function on the class List
// merge - two merge two LL
// makeSate - to remove all duplicate
// reverse - reverse the order of the list

List merge(List& lst1,List& lst2);
void makeSet(List& lst);
void reverse(List& lst);

int main() {
    List lst1, lst2, mergedList;

    cout << "enter sorted values for the first list:" << endl;
    cin >> lst1;
    cout << "enter sorted values for the second list:" << endl;
    cin >> lst2;


    try {
        mergedList = merge(lst1, lst2);
    } catch (const char * exp) {
        cout << exp << endl;
    }
    cout <<"the new merged list: " << mergedList <<endl;

    makeSet(mergedList);
    cout<<"the new merged set: " << mergedList << endl;

    reverse(mergedList);
    cout<<"the new merged reverse: " << mergedList << endl;


    return 0;
}

// merging two LL into one
List merge(List& lst1, List& lst2) {

    List merged;

    int num1 = lst1.firstElement();
    int num2 = lst2.firstElement();

//  using the simple merging algorithm

    while (!lst1.isEmpty() && !lst2.isEmpty()) {
        if(num1 <= num2) {
            merged.add(num1);
            lst1.removeFirst();
            if(!lst1.isEmpty())
                num1 = lst1.firstElement();
        } else {
            merged.add(num2);
            lst2.removeFirst();
            if(!lst2.isEmpty())
                num2 = lst2.firstElement();
        }
    }
// there is always one list that is empty before the other, so we continue to copy the rest
    while(!lst1.isEmpty() || num1 > merged.firstElement()) {
        merged.add(num1);
        lst1.removeFirst();
        if(!lst1.isEmpty()) {
            num1 = lst1.firstElement();
        }
    }

    while(!lst2.isEmpty() || num2 > merged.firstElement()) {
        merged.add(num2);
        lst2.removeFirst();
        if (!lst2.isEmpty()) {
            num2 = lst2.firstElement();
        }
    }

    // reversing the of the list
    reverse(merged);

    return merged;
}
// 5 3 1 9
//  4 2 9


// reversing the order of a LL
void reverse(List& lst) {
//    by emptying the list into another the list is reversed
    List temp;
    while(!lst.isEmpty()) {
        temp.add(lst.firstElement());
        lst.removeFirst();
    }
    lst = temp;
}

// the difference between a list and a set is that in the set there is no duplicate
void makeSet(List& lst) {
    List temp;

    int current, last;
    while(!lst.isEmpty()) {
        current = lst.firstElement();
        lst.removeFirst();
//  if the current element is the same as the last one we don't copy it to the temporary list
        if(current != last) {
            temp.add(current);
        }
        last = current;
    }
    lst = temp;
    reverse(lst);
}

/*
enter sorted values for the first list:
6 5 4 3 2 1 9
enter sorted values for the second list:
7 5 4 3 9
the new merged list: 7 6 5 5 4 4 3 3 2 1
the new merged set: 7 6 5 4 3 2 1
the new merged reverse: 1 2 3 4 5 6 7
 */