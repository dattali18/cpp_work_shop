#include "Worker.h"
#include "cstring"
#include "iostream"

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.2

void Worker::setId(int id) {
    if(id % 1000000000 == 0) { // if the id is not 9 digit
        this->Id = 111111111; // I have decided that the id of '111111111' if the default id
    } else {
        this->Id = id;
    }
}

int Worker::getId() const {
    return this->Id;
}


void Worker::setHour(int hour) {
    if(hour < 0) {
        this->totalHour = 0; // if the input is incorrect the default hour is 0
    } else {
        this->totalHour = hour;
    }
}

int Worker::getHour() const {
    return this->totalHour;
}

void Worker::setDonation(float donation) {
    if(donation < 0) { // if the input is incorrect the default is 0
        this->totalDonation = 0;
    } else {
        this->totalDonation = donation;
    }
}

float Worker::getDonation() const {
    return this->totalDonation;
}

float Worker::calcSalary() { // calculating the total salary
    float sal = (this->perHourSalary * (float) this->totalHour) + this->calcPercentage(); // calling the help method for the percentage
    return sal;
}

float Worker::calcPercentage() const {
    // using the instruction to calc the percentage of the donation
    float percentage = 0;
    if (this->totalDonation <= 1000) { // if the donation in the range [0,1000]
        percentage = 0.1 * this->totalDonation;
    } else if (this->totalDonation <= 2000 && this->totalDonation > 1000) { // if the donation in the range (1000,2000]
        percentage = 0.1 * 1000 + 0.15 *(this->totalDonation - 1000);
    } else if (this->totalDonation <= 4000 && this->totalDonation > 2000) { // if the donation in the range (2000,4000]
        percentage = 0.1 * 1000 + 0.15 * 1000 + 0.2 * (this->totalDonation - 2000);
    } else if (this->totalDonation <= 5000 && this->totalDonation > 4000) { // if the donation in the range (4000,5000]
        percentage = 0.1 * 1000 + 0.15 * 1000 + 0.2 * 2000 + 0.3 * (this->totalDonation - 4000);
    } else { // if the donation in the range (5000,inf)
        percentage = 0.1 * 1000 + 0.15 * 1000 + 0.2 * 2000 + 0.3 * 1000 + 0.4 * (this->totalDonation - 5000);
    }
    return percentage;
}

char *Worker::getName() {
    return this->name;
}

void Worker::setName(char *name) {
    strcpy(this->name, name);
}

// this function is used for debuting
void Worker::print() {
    std::cout << this->Id << std::endl;
    std::cout << this->name << std::endl;
    std::cout << this->perHourSalary << std::endl;
    std::cout << this->totalHour << std::endl;
    std::cout << this->totalDonation << std::endl;
    std::cout << this->calcSalary() << std::endl;

}

void Worker::setSalary(float sal) {
    if (sal < 0) { // if the input is not correct the default value is 0
        this->perHourSalary = 0;
    } else {
        this->perHourSalary = sal;
    }
}

float Worker::getSalary() const {
    return this->perHourSalary;
}


