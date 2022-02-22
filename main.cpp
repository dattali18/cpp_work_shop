#include "Rational.h"
#include <iostream>
using namespace std;

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.1

int main()
{
    int num1, num2, num3;
    char junk;

    cout << "part 1.  set/get" << endl;
    cout << "enter a rational number:" << endl;
    // the junk is used to get rid of the '/' char
    cin >> num1 >> junk >> num2;
    Rational rat1;
    rat1.setNumerator(num1);
    rat1.setDenominator(num2);
    cout << "numerator: " << rat1.getNumerator()<<endl;
    cout << "denominator: " << rat1.getDenominator()<<endl;

    cout << "enter a rational number:" << endl;
    // the junk is used to get rid of the '/' char
    cin >> num1 >> junk >> num2;
    Rational rat2;
    rat2.setNumerator(num1);
    rat2.setDenominator(num2);
    rat2.print();
    cout << endl << endl;

    cout << "part 2.  equals" << endl;
    if (rat1.equal(rat2)) // checking if both number are equal
        cout << "The two numbers are equal" << endl;
    else
        cout << "The two numbers are different" << endl;
    cout << endl << endl;

    // adding the number
    cout << "part 3. add" << endl;
    Rational ans = rat1.add(rat2);
    rat1.print();
    cout << "+ ";
    rat2.print();
    cout << "= ";
    ans.print();
    cout << endl;

    return 0;
}

// testing
/*
part 1.  set/get
enter a rational number:
1/2
numerator: 1
denominator: 2
enter a rational number:
3/4
3/4


part 2.  equals
The two numbers are different


part 3. add
1/2
+ 3/4
= 5/4
 */