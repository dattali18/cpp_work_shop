#include <iostream>
#include "Clock.h"
#include "Account.h"

using namespace std;

// Name: Daniel Attali
// Id: 328780879
// Course: c++
// Ex 4

/* this is a program to manage the banking account using two classes, Clock for the time, Account form managing the account */

// there no comment on the obvious part of the code

enum ACTION {
    STOP,
    BALANCE,
    DEPOSIT,
    WITHDRAW,
    SUM_DEPOSIT,
    SUM_WITHDRAW
};

ACTION menu() {
    cout << "enter 1 to get account balance" << endl;
    cout << "enter 2 to deposit money" << endl;
    cout << "enter 3 to withdraw money" << endl;
    cout << "enter 4 to see the sum of all deposits" << endl;
    cout << "enter 5 to see the sum of all withdrawals" << endl;
    cout << "enter 0 to stop" << endl;
    int x;
    cin >> x;
    return (ACTION)x;
}

int findAccount(Account* bank, int size) {
    int number, code;
    cout << "please enter account number:\n";
    cin >> number;
    int i = 0;
    while (i < size && bank[i].getAccountNumber() != number)
        i++;
    if (i >= size)
        throw "ERROR: no such account number\n";
    cout << "please enter the code:\n";
    cin >> code;
    if (bank[i].getCode() == code)
        return i;
    throw "ERROR: wrong code!\n";
}

void printTransaction(Account a, ACTION ac, Clock& c) {
    cout << c << "\t";
    switch (ac) {
        case BALANCE: cout << "account #: " << a.getAccountNumber() << "\t";
            cout << "balance: " << a.getBalance() << endl;
            break;
        case DEPOSIT:
        case WITHDRAW: cout << "account #: " << a.getAccountNumber() << "\t";
            cout << "new balance: " << a.getBalance() << endl;
            break;
        case SUM_DEPOSIT:
            cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
            break;
        case SUM_WITHDRAW:
            cout << "sum of all withdrawals: " << Account::getSumWithdraw() << endl;
            break;
    }
}

void getBalance(Account* bank, int size, Clock& c) {
    int i = findAccount(bank, size);
    c += 20;
    printTransaction(bank[i], BALANCE, c);
}

void cashDeposit(Account* bank, int size, Clock& c) {
    int i = findAccount(bank, size);
    float amount;
    cout << "enter the amount of the deposit:\n ";
    cin >> amount;
//    try and catch block, we will catch the exception from both classes (Account , Clock)
    try {
        bank[i].deposit(amount);
        c += 30;
        printTransaction(bank[i], DEPOSIT, c);
    }
    catch (const char* msg) {
        cout << c << '\t' << msg;
    }
}

void cashWithdraw(Account* bank, int size, Clock& c) {
    int i = findAccount(bank, size);
    float amount;
    cout << "enter the amount of money to withdraw:\n ";
    cin >> amount;
//    try and catch block, we will catch the exception from both classes (Account , Clock)
    try {
        bank[i].withdraw(amount);
        c += 50;
        printTransaction(bank[i], WITHDRAW, c);
    }
    catch (const char* msg) {
        cout << c << '\t' << msg;
    }

}

void checkAccount(Account bank[], int i) {
    for (int j = 0; j < i; j++)
        if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
            throw "ERROR: account number must be unique!\n";
}

int main() {
    const int SIZE = 10;
    Clock c(8, 0, 0);
    Account bank[SIZE];
    cout << "enter account number, code and email for " << SIZE << " accounts:\n";
    for (int i = 0; i < SIZE; i++) {
        try {
            cin >> bank[i];
            checkAccount(bank, i);
        }
        catch (const char* msg) {
            cout << c << '\t' << msg;
            i--;
        }
    }
    ACTION ac = menu();
    while (ac) {
        switch (ac) {
            case BALANCE:
                getBalance(bank, SIZE, c);
                break;
            case WITHDRAW:
                cashWithdraw(bank, SIZE, c);
                break;
            case DEPOSIT:
                cashDeposit(bank, SIZE, c);
                break;
            case SUM_DEPOSIT:
                c += 60;
                printTransaction(bank[0], SUM_DEPOSIT, c);
                break;
            case SUM_WITHDRAW:
                c += 60;
                printTransaction(bank[0], SUM_WITHDRAW, c);
        }
        ac = menu();
    }

    return 0;
}

/*
enter account number, code and email for 10 accounts:
 1 1111 aaa@gmail.com
2 2222 aaa@gmail.com
3 3333 bbb@gmail.com
4 4444 ccc@gmail.com
5 5555 ddd@gmail.com
6 6666 eee@gmail.com
7 7777 fff@gmail.com
8 8888 ggg@gmail.com
9 9999 hhh@gmail.com
10 1010 iii@gmail.com
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
3
please enter account number:
4
please enter the code:
4444
enter the amount of money to withdraw:
 2000
08:00:50
	account #: 4	new balance: -2000
enter 1 to get account balance
enter 2 to deposit money
enter 3 to withdraw money
enter 4 to see the sum of all deposits
enter 5 to see the sum of all withdrawals
enter 0 to stop
0*/