#include <iostream>
#include "Person.h"

int main() {

    using std::cout;
    using std::endl;
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.show();
    cout << endl;
    one.FormalShow();

    Person arr[3] = {one, two, three};

    for (int i = 0; i < 3; ++i) {
        arr[i].show();
        cout << endl;
        arr[i].FormalShow();
    }
    return 0;
}