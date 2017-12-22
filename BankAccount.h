//
// Created by cat on 2017/12/22.
//

#ifndef CPP02_BANKACCOUNT_H
#define CPP02_BANKACCOUNT_H


#include <string>

class BankAccount {
private:
    double account;
    std::string name;
public:

    BankAccount(double account = 0, const std::string &name = "");

    void showAccountInfo();

    double save(double come);

    double draw(double go);

    virtual ~BankAccount();
};


#endif //CPP02_BANKACCOUNT_H
