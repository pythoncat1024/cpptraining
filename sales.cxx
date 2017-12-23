//
// Created by cat on 2017/12/23.
//

#include <iostream>
#include "sales.h"

void SALES::Sales::setSales(const double *ar, int n) {

    if (n < 1)
        return;
    int size = n < SALES::QUARTERS ? n : SALES::QUARTERS;
    double total = 0;
    for (int i = 0; i < size; ++i) {
        this->sales[i] = ar[i];
        total += ar[i];
    }
    double max = ar[0], min = ar[0];
    for (int j = 1; j < size; ++j) {

        if (ar[j] > max) {
            max = ar[j];
        }
        if (ar[j] < min) {
            min = ar[j];
        }
    }

    this->average = total / size;
    this->max = max;
    this->min = min;

}

void SALES::Sales::setSales() {
    using std::cout;
    using std::cin;

    int index = 0;
    double total = 0;
    cout << "enter some double numbers split with space or enter (counts must equals or bigger than 4):\n";
    while (cin && index < SALES::QUARTERS && cin >> this->sales[index]) {
        total += this->sales[index];
        index++;
//        if (index < SALES::QUARTERS - 1) {
//            cout << "enter some double numbers:";
//        }
    }
    cout << "xxxx\n";
//    cin.clear();
//    while (cin.get() != '\n')continue;
    double max = this->sales[0], min = this->sales[0];
    for (int j = 1; j < index; ++j) {

        if (this->sales[j] > max) {
            max = this->sales[j];
        }
        if (this->sales[j] < min) {
            min = this->sales[j];
        }
    }
    this->average = total / index;
    this->max = max;
    this->min = min;

}

void SALES::Sales::showSales() const {
    using std::cout;
    using std::endl;

    cout << "###### sales:{";
    for (int i = 0; i < SALES::QUARTERS - 1; ++i) {
        cout << this->sales[i] << " , ";
    }
    cout << this->sales[SALES::QUARTERS - 1] << "} , ";

    cout << "average:" << this->average << " , "
         << "max:" << this->max << " , "
         << "min:" << this->min << " #\n";

}
