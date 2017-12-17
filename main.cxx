#include <iostream>
#include "sales.h"

int main() {
    using namespace std;
    using SALES::Sales;
    using SALES::setSales;
    using SALES::showSales;
    Sales s1, s2;
    setSales(s1);

    cout << " show sales #1:\n";
    showSales(s1);

    double arr[4] = {1.23, 3.32, 4.31, 7.6};
    setSales(s2, arr, 3);
    cout << " show sales #2:\n";
    showSales(s2);


//    int num;
//    cin >> num;
//
//    cout << " num=" << num << " done \n";
    return 0;
}