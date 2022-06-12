#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include "exception"
#include "Family.h"

// NAME: DANIEL ATTALI
// ID: 328780879
// COURSE: C++ WORKSHOP
// EX 11

//  creating exception
struct invalidIdException : std::exception {
    const char * what() const throw() {
        return "ERROR: Invalid family number";
    }
};

struct noMatchException : std::exception {
    const char * what() const throw() {
        return "ERROR: Family is not in the file";
    }
};

struct invalidResponseException : std::exception {
    const char * what() const throw() {
        return "ERROR: Invalid response";
    }
};

struct rewriteException :std::exception {
    const char * what() const throw() {
        return "ERROR: Family is already in the file";
    }
};

enum OPTIONS { EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT };

enum ACTIVITY {
    NONE = 0,
    SWIMMING = 1,
    GYMNATSTICS = 2,
    DANCE = 4,
    ART = 8,
    SELF_DEFENSE = 16,
    MUSIC = 32,
    DRAMA = 64,
    BASKETBALL = 128
};


void setFile(std::fstream &file);
int count(std::fstream & file, short option);
void add(std::fstream & file);
void del(std::fstream & file, int id);
void update(std::fstream & file, int id, std::queue<Family>& queue);
void waiting(std::queue<Family>& queue);
void print(std::fstream & file, int id);

void handleCount(std::fstream & file) {
    int snum;
    std::cout << "enter activity number to count:\n";
    std::cout << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
    std::cin >> snum;
    std::cout << "there are ";
    switch (snum) {
        case 1:
            std::cout << count(file, SWIMMING);
            break;
        case 2:
            std::cout << count(file, GYMNATSTICS);
            break;
        case 3:
            std::cout << count(file, DANCE);
            break;
        case 4:
            std::cout << count(file, ART);
            break;
        case 5:
            std::cout << count(file, SELF_DEFENSE);
            break;
        case 6:
            std::cout << count(file, MUSIC);
            break;
        case 7:
            std::cout << count(file, DRAMA);
            break;
        case 8:
            std::cout << count(file, BASKETBALL);
            break;
    }
    std::cout << " families registered\n";
}


int main()
{
    std::queue<Family> q;
    std::queue<Family> jv;

    std::fstream file;
    file.open("families.txt", std::ios::binary | std::ios::in | std::ios::out);
    if (!file)
    {
        std::cout << "ERROR: couldn't open file\n";
        return 0;
    }
    setFile(file);
    file.clear();

    int choice;
    int snum;
    int cnum;
    std::cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
    std::cout << "enter 0-6:\n";
    std::cin >> choice;
    while (choice)
    {
        try {
            switch (choice)
            {
                case ADD://add to the file
                    add(file);
                    break;
                case DEL://delete from file
                    std::cout << "enter number of family to delete:\n";
                    std::cin >> snum;
                    del(file, snum);
                    break;
                case COUNT:
                    handleCount(file);
                    break;
                case UPDATE://update the list of classes of a family
                    std::cout << "enter number of family to update:\n";
                    std::cin >> snum;
                    update(file, snum, jv);
                    break;
                case WAITING://update the list of classes of a waiting family
                    waiting(jv);
                    break;

                case PRINT://print the details of a specific family
                    std::cout << "enter number of family to print:\n";
                    std::cin >> snum;
                    print(file, snum);
                    break;
                default:
                    std::cout << "ERROR: invalid choice\n";

            }
        }// try
        catch (std::exception& e) {
            std::cout << e.what();
        }
//        catch (const char * msg) {
//            std::cout << msg << std::endl;
//        }
        std::cout << "\nenter 0-6:\n";
        std::cin >> choice;

    }
    file.close();
    return 0;
}



void setFile(std::fstream &file) {
    Family fam; // the obj is init with the default values
    int size = sizeof(fam);
//    writing 100 instance of the init obj
    for (int i = 0; i < 100; ++i) {
        file.write((char *) &fam, size);
    }

}

int count(std::fstream & file, short option) {
    Family fam;
    int count = 0;
    int size = sizeof (fam);
//    looping through every obj in the file
    file.clear();
    for (int i = 0; i < 100; ++i) {
        file.seekg(size * i);
        file.read((char *) &fam, size);
        short classes = fam.getClasses();

        // bite arithmetic
        // masking all the bite except the bite of option if the result is 0
        // the family is not in the class else the family is in the class
        if ((classes & option) != 0) {
            count++;
        }
    }
    return count;
}

void add(std::fstream & file) {
    // getting the input for family obj
    std::cout << "enter the family's:  id, name, amount of people and a phone number:\n";
    int id, amount, tel;
    std::string name;
    std::cin >> id >> name >> amount >> tel;
    Family fam1(id, name.c_str(), amount, tel,  NONE);
    Family fam2;
//    checking the id
    if(id < 1 || id > 100) {
        throw invalidIdException();
    }
    file.clear();
//    moving the reader to the correct position
//    checking if the family is already in the file
    file.seekg(sizeof(fam2) * (id));
    file.read((char *)& fam2, sizeof(fam2));
//    if the family is in the file we throw an exception
    if(fam2.getFamilyNumber() != 0) {
        throw rewriteException();
    }
//    if there is no problem we will out the fam1 obj
    file.clear();
    file.seekp(sizeof(fam1) * id);
    file.write((char *)& fam1, sizeof(fam1));

    file.clear();
}

void del(std::fstream & file, int id) {
    if(id < 1 || id > 100) {
        throw invalidIdException();
    }
    file.clear();
    Family fam1;
    file.seekg(sizeof(fam1) * (id));
    file.read((char *)& fam1, sizeof(fam1));
    if(fam1.getFamilyNumber() == 0) {
        throw noMatchException();
    }
//    if the family is in the file we will delete it by putting a blank obj of type Family
    Family fam2;
    file.clear();
    file.seekp(sizeof(fam2) * (id));
    file.write((char *)&fam2, sizeof(fam2));

    file.clear();
}

void update(std::fstream & file, int id, std::queue<Family>& queue) {
    if(id < 1 || id > 100) {
        throw invalidIdException();
    }
    file.clear();
    Family fam1;
    file.seekg(sizeof(fam1) * (id));
    file.read((char *)& fam1, sizeof(fam1));
    if(fam1.getFamilyNumber() == 0) {
        throw noMatchException();
    }

    std::vector<std::string> msg;
    msg.push_back("Do you want to register for swimming?\n");
    msg.push_back("Do you want to register for gymnastics?\n");
    msg.push_back("Do you want to register for dance?\n");
    msg.push_back("Do you want to register for art?\n");
    msg.push_back("Do you want to register for self defense?\n");
    msg.push_back("Do you want to register for music?\n");
    msg.push_back("Do you want to register for drama?\n");
    msg.push_back("Do you want to register basketball?\n");

    std::vector<short> op;
    op.push_back(SWIMMING);
    op.push_back(GYMNATSTICS);
    op.push_back(DANCE);
    op.push_back(ART);
    op.push_back(SELF_DEFENSE);
    op.push_back(MUSIC);
    op.push_back(DRAMA);
    op.push_back(BASKETBALL);

    short classes = 0;
    short notAv = 0;
    char choice;
//    looping through every class in the ACTIVITIES
    for (int i = 0; i < 8; ++i) {
        std::cout << msg[i];
        std::cin >> choice;
        if(choice == 'y' || choice == 'Y') {
            if(count(file, op[i]) < 10) {
                classes |= op[i];
            } else {
                notAv |= op[i];
            }
        } else if(choice == 'n' || choice == 'N') {
//  do nothing
        } else {
            throw invalidResponseException();
        }
    }
    classes |= fam1.getClasses();
    fam1.setClasses(classes);
    file.clear();
    file.seekp(sizeof(fam1) * id);
    file.write((char *) & fam1, sizeof(fam1));
    file.clear();

    // pushing the classes that wasn't available to the family
    if(notAv != 0) {
        fam1.setClasses(notAv);
        queue.push(fam1);
    }
}


void waiting(std::queue<Family>& queue) {
    std::queue<Family> temp;
    Family fam;
    while(!queue.empty()) {
        fam = queue.front();
        temp.push(fam);
        queue.pop();

//      printing
        short classes = fam.getClasses();
        std::cout << "family name: " << fam.getFamilyName() << std::endl;
        std::cout << "number of persons: " << fam.getNumberOfFamilyMembers() << std::endl;
        std::cout << "phone number: " << fam.getTelNumber() << std::endl;

        std::cout << (((classes & SWIMMING) != 0) ? "SWIMMING\n" : "");
        std::cout << (((classes & GYMNATSTICS) != 0) ? "GYMNATSTICS\n" : "");
        std::cout << (((classes & DANCE) != 0) ? "DANCE\n" : "");
        std::cout << (((classes & ART) != 0) ? "ART\n" : "");
        std::cout << (((classes & SELF_DEFENSE) != 0) ? "SELF_DEFENSE\n" : "");
        std::cout << (((classes & MUSIC) != 0) ? "MUSIC \n" : "");
        std::cout << (((classes & DRAMA) != 0) ? "DRAMA \n" : "");
        std::cout << (((classes & BASKETBALL) != 0) ? "BASKETBALL \n" : "");
    }
    while(!temp.empty()) {
        queue.push(temp.front());
        temp.pop();
    }
}

void print(std::fstream & file, int id) {
    if(id < 1 || id > 100) {
        throw invalidIdException();
    }
    file.clear();
    Family fam;
    file.seekg(sizeof(fam) * id);
    file.read((char *)& fam, sizeof(fam));
    if(fam.getFamilyNumber() == 0) {
        throw noMatchException();
    }
//  if there is no error fam is the obj
    short classes = fam.getClasses();
    std::cout << "family name: " << fam.getName() << std::endl;
    std::cout << "number of persons: " << fam.getNumberOfFamilyMembers() << std::endl;
    std::cout << "phone number: " << fam.getTelNumber() << std::endl;
    std::cout << (((classes & SWIMMING) != 0) ? "SWIMMING\n" : "");
    std::cout << (((classes & GYMNATSTICS) != 0) ? "GYMNATSTICS\n" : "");
    std::cout << (((classes & DANCE) != 0) ? "DANCE\n" : "");
    std::cout << (((classes & ART) != 0) ? "ART\n" : "");
    std::cout << (((classes & SELF_DEFENSE) != 0) ? "SELF_DEFENSE\n" : "");
    std::cout << (((classes & MUSIC) != 0) ? "MUSIC \n" : "");
    std::cout << (((classes & DRAMA) != 0) ? "DRAMA \n" : "");
    std::cout << (((classes & BASKETBALL) != 0) ? "BASKETBALL \n" : "");
}