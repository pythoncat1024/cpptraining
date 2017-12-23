#include <iostream>
#include "sales.h"

int main() {
    using namespace std;
    using SALES::Sales;
    Sales s1, s2;
    s1.setSales();

    cout << " show sales #1:\n";
    s1.showSales();

    double arr[4] = {1.23, 3.32, 4.31, 7.6};
    s2.setSales( arr, 3);
    cout << " show sales #2:\n";
    s2.showSales();

//    int num;
//    cin >> num;
//
//    cout << " num=" << num << " done \n";
    return 0;
}