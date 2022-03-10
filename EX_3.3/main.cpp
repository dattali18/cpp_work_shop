#include <iostream>
#include "MyString.h"

using namespace std;

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 3.3

int main() {
    // getting the input from the user
//     I didn't use the built-in >> operator because of problem with getting two consecutive string
    char * str1 = new char[30];
    char * str2 = new char[30];
    cin >> str1;
    cin >> str2;
//    creating the object
    MyString s1(str1), s2(str2), cpyStr;
    int index;
    cin >> index;
//    checking the string
    if (s1 == s2) {
        cout << "a=b" << endl;
    } else if (s1 > s2) {
        cout << "a>b" << endl;
    } else {
        cout << "a<b" << endl;
    }
    char * str = s1.getStr();
//    applying  insert methods
    cpyStr = s2.insert(index, str);
    cout << cpyStr << endl;
    char ch;
    cin >> ch;
    cin >> index;
//    inserting a char using the [] operator
    cpyStr[index] = ch;
    cout << cpyStr << endl;
}


// TESTING
/*
World
Hello
5
a>b
move ctor
move assign
WorldHello

!

5
World!ello
*/