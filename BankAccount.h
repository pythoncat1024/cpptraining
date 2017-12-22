//
// Created by cat on 2017/12/22.
//

#ifndef CPP02_BANKACCOUNT_H
#define CPP02_BANKACCOUNT_H


class BankAccount {

public:
    BankAccount();

    void showAccountInfo();

    double save(double come);

    double draw(double go);

    virtual ~BankAccount();
};


#endif //CPP02_BANKACCOUNT_H
