#include <iostream>
#include "move.h"

int main() {
    using namespace std;

    Move m = Move(0, 0);
    m.showMove();
    Move val = Move(12, 15);
    m = m.add(val);
    m.showMove();

    m.reset();
    m.showMove();

    m.add2(val);
    m.add2(m.add2(val));
    m.showMove();
    return 0;
}