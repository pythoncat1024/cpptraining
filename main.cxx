#include <iostream>
#include <sstream>

#include "complex0.h"
#include <complex>
using namespace std;

int main() {

    using complex0::Complex;
    Complex a(3, 4);
    Complex c;

    stringstream ss;
    int x;
    ss >> x;

    cout << "x = " << x;
    cout << "Enter a complex number(q to quit):\n";

    while (cin >> c) {
        cout << "c is " << c << "\n";
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number(q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}