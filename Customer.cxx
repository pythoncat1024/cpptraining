//
// Created by cat on 2018/1/7.
//

#include <cstdlib>
#include "Customer.h"

Customer::Customer() {
    arriveTime = processTime = 0;
}

Customer::Customer(long when) {
    set(when);
}

Customer::Customer(const Customer &co) {
    arriveTime = co.arriveTime;
    processTime = co.processTime;
}

Customer::~Customer() {

}

Customer &Customer::operator=(const Customer &co) {
    arriveTime = co.arriveTime;
    processTime = co.processTime;
    return *this;
}

void Customer::set(long when) {

    processTime = std::rand() % 3 + 1;
    arriveTime = when;
}

std::ostream &operator<<(std::ostream &os, const Customer &co) {
    return os << "Customer:(" << co.arriveTime << "," << co.processTime << ")\n";
}
