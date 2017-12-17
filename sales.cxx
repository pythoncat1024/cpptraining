//
// Created by cat on 2017/12/18.
//

#include <iostream>
#include "sales.h"

void SALES::showSales(const Sales &s) {
    using std::cout;
    using std::endl;

    cout << "###### sales:{";
    for (int i = 0; i < SALES::QUARTERS - 1; ++i) {
        cout << s.sales[i] << " , ";
    }
    cout << s.sales[SALES::QUARTERS - 1] << "} , ";

    cout << "average:" << s.average << " , "
         << "max:" << s.max << " , "
         << "min:" << s.min << " #\n";

}

void SALES::setSales(Sales &s, const double *ar, int n) {
    if (n < 1)
        return;
    int size = n < SALES::QUARTERS ? n : SALES::QUARTERS;
    double total = 0;
    for (int i = 0; i < size; ++i) {
        s.sales[i] = ar[i];
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

    s.average = total / size;
    s.max = max;
    s.min = min;
}

void SALES::setSales(Sales &s) {
    using std::cout;
    using std::cin;

    int index = 0;
    double total = 0;
    cout << "enter some double numbers split with space or enter (counts must equals or bigger than 4):\n";
    while (cin && index < SALES::QUARTERS && cin >> s.sales[index]) {
        total += s.sales[index];
        index++;
//        if (index < SALES::QUARTERS - 1) {
//            cout << "enter some double numbers:";
//        }
    }
    cout << "xxxx\n";
//    cin.clear();
//    while (cin.get() != '\n')continue;
    double max = s.sales[0], min = s.sales[0];
    for (int j = 1; j < index; ++j) {

        if (s.sales[j] > max) {
            max = s.sales[j];
        }
        if (s.sales[j] < min) {
            min = s.sales[j];
        }
    }
    s.average = total / index;
    s.max = max;
    s.min = min;


}