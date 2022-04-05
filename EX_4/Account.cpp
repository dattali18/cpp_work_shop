#include "Account.h"

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 4

//  ctor

Account::Account() {
    accountNumber = 0;
    code = 0;
    balance = 0;
    email = "";
}

Account::Account(int account_, int code_, std::string email_) {
//    checking for exception
    if(code_ > 10000 || code_ < 1000) {
        throw "ERROR: code must be of 4 digits! ";
    } else if(email_.find('@') == std::string::npos) {
        throw "ERROR: email must contain @! ";
    } else if(email_.find(".com") == std::string::npos && email_.find(".co.il") == std::string::npos) {
        throw "ERROR: email must end at .com or .co.il! ";
    }

//    if no exception was thrown, we assign the value to the field

    this->accountNumber = account_;
    this->code = code_;
    this->balance = 0.0;
    this->email = email_;
}

// getter

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getCode() const {
    return code;
}

float Account::getBalance() const {
    return balance;
}

const std::string &Account::getEmail() const {
    return email;
}

// operator overloading

istream& operator>>(istream& is, Account& ac) {

    int accountNumber_;
    int code_;
    string email_;

//    getting the input from is

    is >> accountNumber_;
    is >> code_;
    is >> email_;

//    checking the input for exception

    if(code_ >= 10000 || code_ < 1000) {
        throw "ERROR: code must be of 4 digits! ";
    } else if(email_.find('@') == std::string::npos) {
        throw "ERROR: email must contain @! ";
    } else if(email_.find(".com") == std::string::npos && email_.find(".co.il") == std::string::npos) {
        throw "ERROR: email must end at .com or .co.il! ";
    }

//    if no exception was thrown, we assign the value to the field

    ac.accountNumber = accountNumber_;
    ac.code = code_;
    ac.balance = 0.0;
    ac.email = email_;

    return is;
}

// methods

void Account::withdraw(int nis) {

//    checking the parameter for exception

    if(this->balance - nis < -6000) {
        throw "ERROR: cannot have less than - 6000 NIS! ";
    }else if(nis > 2500) {
        throw "ERROR: cannot withdraw more than 2500 NIS! ";
    }
    // if no exception was thrown, we take the amount from the account
    this->balance -= nis;
//    we update the static field withdrawSum
    Account::withdrawSum += nis;
}

void Account::deposit(int nis) {
    //    checking the parameter for exception

    if(nis > 10000) {
        throw "ERROR: cannot deposit more than 10000 NIS! ";
    }
    // if no exception was thrown, we add the amount from the account
    this->balance += nis;
    // we update the static field withdrawSum
    Account::depositSum += nis;
}

// static methods
// assigning the value to be 0, at the first time an object form the account class is created

int Account::withdrawSum = 0;
int Account::depositSum = 0;

// getter for the static values

int Account::getSumWithdraw() {
    return withdrawSum;
}

int Account::getSumDeposit() {
    return depositSum;
}





