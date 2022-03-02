#include <iostream>
#include "Polygon.h"
#include "Point.h"
#include "cmath"
using namespace std;

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 2.1

int main() {
    int sides, x, y;
    char junk;
    cout << "enter number of sides:" << endl;
    cin >> sides;
    // checking the validity of the data (there is no 0 or negative side)
    while (sides <= 0) {
        cout << "ERROR" << endl;
        cin >> sides;
    }
    Polygon poly1(sides);
    cout << "enter the point values:" << endl;
    Point p;
    // getting the Point input from the user
    for (int i = 0; i < sides; ++i) {
        cin >> junk >> x >> junk >> y >> junk;
        p.setX(x);
        p.setY(y);
        poly1.addPoint(p, i);
    }
    cout << "enter number of sides:" << endl;
    cin >> sides;
    // checking the validity of the data (there is no 0 or negative side)
    while (sides <= 0) {
        cout << "ERROR" << endl;
        cin >> sides;
    }
    Polygon poly2(sides);
    cout << "enter the point values:" << endl;
    // getting the Point input from the user
    for (int i = 0; i < sides; ++i) {
        cin >> junk >> x >> junk >> y >> junk;
        p.setX(x);
        p.setY(y);
        poly2.addPoint(p, i);
    }
    cout << " in copy constructor" << endl << "in destructor" << endl;
    // if both polygon are equal we print only on perimeter
    if (poly1.isEqual(poly2)) {
        cout << "equal" << endl;
        cout << "perimeter: " << round(poly1.getPerimeter()) << endl;
//    else we print the different perimeter
    } else {
        cout << "not equal" << endl;
        cout << "perimeter: " << round(poly1.getPerimeter()) << endl;
        cout << "perimeter: " << round(poly2.getPerimeter()) << endl;
    }
    return 0;
}
// TESTING
/*
enter number of sides:
3
in one parameter constructor
enter the point values:
(1,2)
(2,3)
(4,3)
enter number of sides:
3
in one parameter constructor
enter the point values:
(1,2)
(4,3)
(2,3)
equal
perimeter: 11
in destructor
in destructor
 */