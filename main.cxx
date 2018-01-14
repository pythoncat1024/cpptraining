#include <iostream>
#include "CD.h"

void Bravo(const CD &disk);

using namespace std;

int main() {

//    std::string s("abc");
    CD c1((char *) "Beatles", (char *) "Capitol", 14, 35.5);

    Classic c2 = Classic((char *) "Piano Sonata in B flat, Fatansia in C",
                         (char *) "Alfred Brendel", (char *) "Philips", 2, 57.17);
    CD *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use CD method
    c2.Report(); // use Classic method
    cout << "Using type cd* pointer to objects:\n";

    pcd->Report(); // use CD method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object

    cout << "Calling a function with a CD reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";

    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const CD &disk) {
    disk.Report();
}