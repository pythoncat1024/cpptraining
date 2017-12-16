#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
void swap2(T &a, T &b);

int main() {


    int a = 12;
    int b = 9;

    cout << "before: a=" << a << " , b=" << b << endl;
    swap2(a, b);
    cout << "after : a=" << a << " , b=" << b << endl;
    return 0;
}

template<typename T>
void swap2(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

