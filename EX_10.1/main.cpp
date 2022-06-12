// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 10.1


#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include "Soldier.h"
#include "Officer.h"
#include "PrivateSoldier.h"
#include "Commander.h"

enum option {
    EXIT,
    ADD_NEW_SOLDIER,
    DESERVES_MEDAL,
    HIGHEST_SOCIOMETRIC,
    PRIVATE_MEDAL_COUNT,
    NONCOMBAT_COMMANDER,
    SUPER_SOLDIER,
    REMOVE_OFFICER,
};
void add(std::vector<Soldier*> & soldiers);
void remove(std::vector<Soldier*> & soldiers);
void printMedalList(const std::vector<Soldier*> & soldiers);
Soldier* highestSociometricScore (const std::vector<Soldier*> & soldiers);

int main()
{
    Soldier* s;
    std::vector<Soldier*> soldiers;
    int op;
    std::cout << "enter 0-7\n";
    std::cin >> op;
    int sum = 0;
    while(op != EXIT)
    {
        switch (op)
        {
            case ADD_NEW_SOLDIER:
                add( soldiers);
                break;
            case DESERVES_MEDAL:
                printMedalList( soldiers);
                break;
            case HIGHEST_SOCIOMETRIC:
                s = highestSociometricScore(soldiers);
                std::cout <<"Officer with the highest sociometric score: ";
                std::cout << s->getFName() << ' ' << s->getLName() << std::endl;
                break;
            case PRIVATE_MEDAL_COUNT:
                std::cout << "number of privates that received medals: ";
                for_each(soldiers.begin(), soldiers.end(), [&](Soldier *element) {
                    if(element->medal() && element->soldierType() == std::string("private")) {
                        sum += 1;
                    }
                });
                std::cout << sum << std::endl;
                break;
            case NONCOMBAT_COMMANDER:
                std::cout << "list of noncombat commanders: ";
                for_each(soldiers.begin(), soldiers.end(), [](Soldier * element) {
                    if(element->soldierType() == std::string("commander")) {
                        if(!((Commander *)element)->isCombat1()) {
                            std::cout << element->getFName() << ' ' << element->getLName() << std::endl;
                        }
                    }
                });
                std::cout << std::endl;
                break;
            case SUPER_SOLDIER:
                if (any_of(soldiers.begin(), soldiers.end(), [](Soldier * element)->bool {
                    if(element->getNumOfOperation() > 15) { return true; }
                    return false;
                }))
                {
                    std::cout << "there is at least one soldier that did more than 15 operations\n";
                }
                else
                    std::cout << "no soldier did more than 15 operations\n";
                break;
            case REMOVE_OFFICER:
                remove(soldiers);
                for (auto element: soldiers) {
                    element->print();
                    std::cout << std::endl;
                }
                break;
            default:
                std::cout << " ";
                break;
        }
        std::cout << "enter 0-7\n";
        std::cin >> op;
    }
    return 0;
}

void add(std::vector<Soldier*> & soldiers) {
    Soldier *newSoldier;
    int choice;
    std::cout << "choose a soldier\n";
    std::cout << "enter 1 to add a private\n";
    std::cout << "enter 2 to add a commander\n";
    std::cout << "enter 3 to add an officer\n";
    std::cin >> choice;
    std::string fName, lName;
    int numOfOperations, id, isCombat;
    float sociometric;
    std::cout << "enter id, first name, last name and number of operations\n";
    std::cin >> id;
    std::cin >> fName >> lName;
    std::cin >> numOfOperations;
    int * grade = new int [numOfOperations];
    switch (choice) {
        case 1:
            if(numOfOperations)
                std::cout << "enter " << numOfOperations << " grades\n";
            for (int i = 0; i < numOfOperations; ++i) {
                std::cin >> grade[i];
            }
            newSoldier = new PrivateSoldier(id, fName, lName, numOfOperations, grade);
            break;
        case 2:
            if(numOfOperations)
                std::cout << "enter " << numOfOperations << " grades\n";
            for (int i = 0; i < numOfOperations; ++i) {
                std::cin >> grade[i];
            }
            std::cout << "enter 1 if the soldier is combat and 0 if not\n";
            std::cin >> isCombat;
            newSoldier = new Commander(id, fName, lName, numOfOperations, grade, (bool) isCombat);
            break;
        case 3:
            std::cout << "enter the sociometric score\n";
            std::cin >> sociometric;
            newSoldier = new Officer(id, fName, lName, numOfOperations, sociometric);
            break;
    }
    soldiers.push_back(newSoldier);
}

void remove(std::vector<Soldier*> & soldiers) {
    for (auto it : soldiers) {
        if(it->soldierType() == std::string("officer") && it->getNumOfOperation() == 0) {
            auto position = std::find(soldiers.begin(), soldiers.end(), it);
            if(position != soldiers.end()) {
                soldiers.erase(position);
            }
        }
    }
}

void printMedalList(const std::vector<Soldier*> & soldiers) {
    for (auto soldier : soldiers) {
        if(soldier->medal()) {
            soldier->print();
        }
    }
}
Soldier* highestSociometricScore (const std::vector<Soldier*> & soldiers) {
    Soldier* highest ;
    for (auto soldier : soldiers) {
        if(soldier->soldierType() == std::string("officer")) {
            if(((Officer *)soldier)->getSociometricGrad() > ((Officer *) highest)->getSociometricGrad()) {
               highest = soldier;
            }
        }
    }
    return highest;
}