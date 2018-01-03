#include <iostream>
#include "StringBetter.h"

using namespace std;
const unsigned int ArSize = 10;
const unsigned int MaxLen = 81;

int main() {

    StringBetter name;
    cout << "Hi ,what's your name?\n>> ";
    cin >> name;
    cout << name << " , please enter up to " << ArSize
         << " short sayings < empty line to quit>:\n";

    StringBetter saying[ArSize];
    char temp[MaxLen];
    int i;
    for (i = 0; i < ArSize; ++i) {
        cout << i + 1 << "：";
        cin.get(temp, MaxLen);

//        while (cin && cin.get() != '\n')continue;
//        if (cin) {
//            cout << "cin ok....";
//        }
        if (!cin || cin.get() == '\0') { // \0 --> empty line
            break;
        } else {
            saying[i] = temp;  // operator=()
        }
    }
    int total = i;

    if (total > 0) {
        cout << "Here are your sayings:\n";
        for (i = 0; i < total; ++i) {
            cout << saying[i][0] << ": " << saying[i] << endl;
        }
        int shortest = 0, first = 0;
        for (i = 0; i < total; ++i) {
            if (saying[i].length() < saying[shortest].length()) {
                shortest = i;
            }
            if (saying[i] > saying[first]) {
                first = i;
            }
        }
        cout << "Shortest saying:\n" << saying[shortest] << endl;
        cout << "First alphabetically saying:\n" << saying[shortest] << endl;

        cout << "This program used" << StringBetter::HowMany() << " StringBetter objects. Bye.\n";
    } else {

        cout << "No input! Bye.\n";
    }
    return 0;
}