#include <iostream>
#include "Worker.h"
using namespace std;

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.2


int main() {
    // those vars are used for storing the data for the best and worst workers
    // (because the instruction said no array)
    int worstId;
    int bestId;
    char bestName[21];
    char worstName[21];
    float bestSalary = 0; // I'm assuming that the best worker will make a greater salary than 0
    float worstDonation = 1000000; // I'm assuming that the worst worker will make less than 1000000 of donation

    int id;
    char name[21];
    float perHourSalary;
    int totalHour;
    float totalDonation;
    // getting the user input
    cout << "enter details, to end enter 0:" << endl;
    do {
        Worker r1{};
        cin >> id;
        // if the user type 0 we stop the loop
        if (id == 0) {
            break;
        }
        cin >> name;
        cin >> perHourSalary;
        cin >> totalHour;
        cin >> totalDonation;

        // checking the valid
        if ((id > 0 && id / 100000000 > 0) && (strlen(name) <= 21) && (perHourSalary > 0) && (totalDonation > 0) && (totalHour > 0)) {
            r1.setId(id);
            r1.setName(name);
            r1.setSalary(perHourSalary);
            r1.setHour(totalHour);
            r1.setDonation(totalDonation);
        } else {
            // if the data is incorrect we print error and restart the loop
            cout << "ERROR" << endl;
            continue;
        }

//        r1.print();

        // updating the data of the best and word worker
        if (r1.getDonation() < worstDonation) {
            worstId = r1.getId();
            worstDonation = r1.getDonation();
            strcpy(worstName, r1.getName());
        }
        if (r1.calcSalary() > bestSalary) {
            bestId = r1.getId();
            bestSalary = r1.calcSalary();
            strcpy(bestName, r1.getName());
        }
    } while (id != 0);

    // printing the result
    cout << "minimum collected: " << worstId << " " << worstName << " " << worstDonation << endl;
    cout << "highest salary:  " << bestId << " " << bestName << " " << bestSalary << endl;
    return 0;
}

// testing
/*
enter details, to end enter 0:
123456789 moshe 10 10 10
123456788 dan 30 40 50
0
minimum collected: 123456789 moshe 10
highest salary:  123456788 dan 1205
 */