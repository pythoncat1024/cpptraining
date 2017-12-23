
#include <iostream>
#include "golf.h"

int main() {

    const int ArrSize = 5;
    golf arrG[ArrSize]{};

    // set data
    for (int i = 0; i < ArrSize; ++i) {
        golf &set = arrG[i].setgolf();

//        std::cout << "set= " << set << std::endl;
        if (&set == NULL)break;
    }

    std::cout << "show data:\n";
// show data
    for (int k = 0; k < ArrSize; ++k) {
        arrG[k].showgolf();
    }
    // reset data
    for (int j = 0; j < ArrSize; ++j) {
        arrG[j].handicap( j + 1);
    }
    // reshow data
    std::cout << "reshow data:\n";
    for (int k = 0; k < ArrSize; ++k) {
        arrG[k].showgolf();
    }
    return 0;
}
