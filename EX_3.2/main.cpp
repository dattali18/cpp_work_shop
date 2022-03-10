#include <iostream>
#include "MyDate.h"

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 3.2

// USING ONLY THE FUNCTION NEEDED FROM std NAME SPACE
using std::cout;
using std::cin;
using std::endl;
// AN ENUM FOR THE READABILITY OF THE CODE
enum Option {EXIT, SET, PRE, POST, PLC, GRT, SMT, EQL};

int main() {
//    INITIALIZING choice TO BE 10 SO THERE IS NO ERROR IN THE CASE IT WAS ALREADY 0
    int day, month, year, choice = 10;
//    USED FOR THE '/' CHAR IN THE DATE FORMAT
    char junk;
    cout << "Enter a date" << endl;
//    GETTING THE DATA IN THE DD/MM/YYYY FORMAT
    cin >> day >> junk >> month >> junk >> year;
//    INITIALIZING THE FIRST DATE USING THE CTOR
    MyDate date1(day, month, year), date2;
    date1.print();
    cout << endl;
//    WHILE THE CHOICE ISN'T 0
    while(choice != EXIT) {
        cout << "Enter a code" << endl;
        cin >> choice;
        switch (choice) {
//                CASE 0: EXITING
            case EXIT:
                break;
//            CASE 1: CHECKING THE SETTER METHOD(S)
            case SET:
                cout << "Enter a date" << endl;
                cin >> day >> junk >> month >> junk >> year;
                date1.setDate(day, month, year);
                date1.print();
                cout << endl;
                break;
//                CASE 2: CHECKING THE PREFIX ++ OPERATOR
            case PRE:
                date2 = ++date1;
                date2.print();
                cout << endl;
                date1.print();
                cout << endl;
                break;
//                CASE 3: CHECKING THE POSTFIX ++ OPERATOR
            case POST:
                date2 = date1++;
                date2.print();
                cout << endl;
                date1.print();
                cout << endl;
                break;
            case PLC:
                cout << "Enter a date" << endl;
                cin >> day >> junk >> month >> junk >> year;
                date2.setDate(day, month, year);
                date1 = date2;
                date1.print();
                cout << endl;
                break;
//                CASE 5: CHECKING THE > (GREATER THEN = GRT) OPERATOR
            case GRT:
                cout << "Enter a date" << endl;
                cin >> day >> junk >> month >> junk >> year;
                date2.setDate(day, month, year);
                date1.print();
                cout << " > ";
                date2.print();
                cout << ": ";
                cout << ((date1 > date2) ? " true " : " false ") << endl;
                break;
//                CASE 6: CHECKING THE < (SMALLER THEN = SMT) OPERATOR
            case SMT:
                cout << "Enter a date" << endl;
                cin >> day >> junk >> month >> junk >> year;
                date2.setDate(day, month, year);
                date1.print();
                cout << " < ";
                date2.print();
                cout << ": ";
                cout << ((date1 < date2) ? "true " : "false ") << endl;
                break;
//                CASE 7: CHECKING THE == (EQUALITY = EQL) OPERATOR
            case EQL:
                cout << "Enter a date" << endl;
                cin >> day >> junk >> month >> junk >> year;
                date2.setDate(day, month, year);
                date1.print();
                cout << " == ";
                date2.print();
                cout << ": ";
                cout << ((date1 == date2) ? " true " : " false ") << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}

// TESTING:
/*
Enter a date
1/2/2002
1/2/2002
Enter a code:
1
Enter a date
6/7/2002
6/7/2002
Enter a code:
2
7/7/2002
Enter a code:
3
7/7/2002
Enter a code:
4
Enter a date
3/4/2002
>: true
Enter a code:
5
Enter a date
3/4/2001
<: false
Enter a code:
6
Enter a date
3/4/2030
==: false
Enter a code:
7
Enter a code:
0*/
