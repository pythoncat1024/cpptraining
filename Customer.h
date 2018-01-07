//
// Created by cat on 2018/1/6.
//

#ifndef CPP02_CUSTOMER_H
#define CPP02_CUSTOMER_H


#include <ostream>

class Customer {

private:
    long arriveTime;
    int processTime;

public:
    Customer();

    Customer(long when);

    Customer(const Customer &co);

    virtual ~Customer();

    Customer &operator=(const Customer &co);

    void set(long when);

    long when() const { return arriveTime; }

    int pTime() const { return processTime; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &co);
};


#endif //CPP02_CUSTOMER_H
