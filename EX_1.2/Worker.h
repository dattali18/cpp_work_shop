#ifndef EX_1_2_WORKER_H
#define EX_1_2_WORKER_H

// Name: Daniel Attali
// id: 328780879
// course: C++ Work Shop
// EX 1.2

// declaring the class Worker
class Worker {
private:
    int Id;
    char name[21];
    float perHourSalary;
    int totalHour;
    float totalDonation;
    // this function is private because it's only used by the class method
    float calcPercentage() const;
public:
    void setId(int id);
    int getId() const;
    void setName(char * name);
    char * getName();
    void setHour(int hour);
    int getHour() const;
    void setSalary(float sal);
    float getSalary() const;
    void setDonation(float donation);
    float getDonation() const;
    float calcSalary();
    // this function was used for debugging
    void print();
};


#endif //EX_1_2_WORKER_H
