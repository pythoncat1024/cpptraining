#include <iostream>
#include <random>
#include <cmath>
#include "Vector.h"

//typedef VECTOR::Vector Vector;

int main() {

    using namespace std;
    using VECTOR::Vector;

    Vector v1 = Vector(20, 30, Vector::RECT);
    Vector v2 = Vector(40, 50, Vector::RECT);
    cout << v1 << v2 << endl;

    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = 1.4 * v1;
    Vector v6 = -v1;

    cout << v3 << endl;
    cout << v4 << endl;
    cout << v5 << endl;
    cout << v6 << endl;
    return 0;
}