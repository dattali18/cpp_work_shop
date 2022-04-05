#include <iostream>
#include "List.h"

using namespace std;

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 5.1

enum CHOICES { EXIT, INSERT, REMOVE, ASSIGN, PRINT };

int main(){
    List lst;
    List lst2;
    int choice, val;

    cout << "enter the list values\n";
    cin >> lst;
    cout << "choose 0-4\n";
    cin >> choice;

    while (choice != EXIT){
        switch (choice) {
            case INSERT:
                cout << "enter a value to insert\n";
                cin >> val;
                lst.insert(val);
                break;
            case REMOVE:
                cout << "enter a value to remove\n";
                cin >> val;
                try {
                    lst.remove(val);
                } catch (const char * exp) {
                    cout << exp << endl;
                }
                break;
            case ASSIGN:
                lst2 = lst;
                cout << "list 2: " << lst2 << endl;
                cout << "list 1: ";
            case PRINT:
                cout << lst << endl;
                break;
            default:cout << "ERROR\n";
        }
        cout << "choose 0-4\n";
        cin >> choice;
    }
    return 0;
}


/*
enter the list values
9 8 7 6 5 4 3 2 1 1
choose 0-4
1
enter a value to insert
10
choose 0-4
4
1 2 3 4 5 6 7 8 9 10
choose 0-4
1
enter a value to insert
4
choose 0-4
4
1 2 3 4 4 5 6 7 8 9 10
choose 0-4
2
enter a value to remove
5
choose 0-4
4
1 2 3 4 4 6 7 8 9 10
choose 0-4
3
list 2: 1 2 3 4 4 6 7 8 9 10
list 1: 1 2 3 4 4 6 7 8 9 10
choose 0-4
0
 */
