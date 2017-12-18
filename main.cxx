#include <iostream>
#include "Student.h"

int main() {

    Student s;
    s.registerIn("tom", 23, 19);
    s.testing(87);
    s.show();

    s.resetInfo();
    s.show();
    return 0;
}