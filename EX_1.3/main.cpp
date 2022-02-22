#include <iostream>
#include "Point.h"
#include "Circle.h"

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.2

using namespace std;

int main() {
    // creating an array of 3 circle for the three circle
    Circle circle[3];
    // for the '(' char etc.
    char junk;
    int x, y, r;
    cout << "enter the center point and radius of 3 circles:" << endl;
    for (int i = 0; i < 3; ++i) {
        cin >> junk >> x >> junk >> y >> junk  >> r;

        // checking the validity of the data
        // if the r <= 0 we print error and ask for the data again
        if (r <= 0) {
            cout << "ERROR" << endl;
            i--;
            continue;
        }
        // setting the data
        circle[i].setCenter(x, y);
        circle[i].setRadius(r);
    }
    // outing the data
    cout << "perimeter:\tA: " << circle[0].perimeter() << "\tB: " << circle[1].perimeter() << "\tC: " << circle[2].perimeter() << endl;
    cout << "area:\tA: " << circle[0].area() << "\tB: " << circle[1].area() << "\tC: " << circle[2].area() << endl;

    cout << "enter points until (0,0):" << endl;

    // using the int array as a counter
    int c[3] = {0, 0, 0};

    Point p{};
    // reciving the data from the user
    do {
        cin >> junk >> x >> junk >> y >> junk;
        p.setX(x);
        p.setY(y);
        // setting the current point after a data validity check
        if (p.getX() == 0 && p.getY() == 0) {
            break;
        }
        // checking for each point if it is in or on one of the three circle
        for (int i = 0; i < 3; ++i) {
            r = circle[i].onInOut(p);
            // if r <= 0 the point is either on or in the circle, so we add 1 to the counter
            if (r <= 0) {
                c[i]++;
            }
        }
        // while the user didn't enter (0,0) we continue to recive point from the user
    } while (x != 0 || y != 0);
    // outputting the data
    cout << "num of points in circle:\tA:" << c[0] <<"\tB:" << c[1] << "\tC:" << c[2] << endl;
    return 0;
}

// testing:
/*
enter the center point and radius of 3 circles:
(0,0) 1
(0,0) 2
(0,1) 3
perimeter:	A: 6.28	B: 12.56	C: 18.84
area:	A: 3.14	B: 12.56	C: 28.26
enter points until (0,0):
(1,2)
(2,4)
(4,5)
(-1,3)
(0,0)
num of points in circle:	A:0	B:0	C:2
 */