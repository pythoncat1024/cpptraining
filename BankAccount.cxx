//
// Created by cat on 2017/12/22.
//

#include <iostream>
#include "BankAccount.h"


BankAccount::BankAccount(double account, const std::string &name)
        : account(account), name(name) {
    std::cout << "BankAccount Constructor method invoke...\n";
}

BankAccount::~BankAccount() {
    std::cout << "BankAccount Destructor method invoke...\n";
}

void BankAccount::showAccountInfo() {
    using std::cout;
    using std::endl;

    cout << "{name:" << this->name << " , "
         << "account:" << this->account << "}\n";
}

double BankAccount::save(double come) {
    if (come < 0) {
        return this->account;
    }
    this->account += come;
    return this->account;
}

double BankAccount::draw(double go) {
    if (go < 0) {
        return this->account;
    } else if (this->account < go) {
        return 0;
    } else {
        this->account -= go;
        return this->account;
    }
}

