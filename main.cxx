
#include <iostream>
#include "golf.h"

int main() {

    const int ArrSize = 5;
    golf arrG[ArrSize]{};

    // set data
    for (int i = 0; i < ArrSize; ++i) {
        int set = setgolf(arrG[i]);

        std::cout << "set= " << set << std::endl;
        if (!set)break;
    }

    std::cout<< "show data:\n";
// show data
    for (int k = 0; k < ArrSize; ++k) {
        showgolf(arrG[k]);
    }
    // reset data
    for (int j = 0; j < ArrSize; ++j) {
        handicap(arrG[j], j + 1);
    }
    // reshow data
    std::cout<< "reshow data:\n";
    for (int k = 0; k < ArrSize; ++k) {
        showgolf(arrG[k]);
    }
    return 0;
}
