#ifndef EX_4_1_ACCOUNT_H
#define EX_4_1_ACCOUNT_H

#include "iostream"
#include "string"

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 4

using namespace std;

// declaring the account class

class Account {
private:
    int accountNumber = 0;
    int code = 0;
    int balance = 0;
    std::string email;

// static field

    static int withdrawSum;
    static int depositSum;

public:
//    CTOR
    Account();

    Account(int account_, int code_, std::string email_);

//    GETTER

    int getAccountNumber() const;

    int getCode() const;

    float getBalance() const;

    const std::string &getEmail() const;

//    OPERATOR OVERLOADING

    friend istream& operator>>(istream& is, Account& ac);

//    METHODS

    void withdraw(int nis);

    void deposit(int nis);

//    STATIC METHODS

    static int getSumWithdraw();

    static int getSumDeposit();
};



#endif //EX_4_1_ACCOUNT_H
