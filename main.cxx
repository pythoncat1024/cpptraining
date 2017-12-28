#include <iostream>
#include "Time.h"

int main() {
    using namespace std;
    Time working = Time();
    Time play(2, 40);
    Time total;

    working.show();
    play.show();
    total.show();

    working.addHour(6);
    working.addMin(35);
    working.show();
    cout << "-------------------------\n";
    Time diff;
    diff = working - play;
    diff.show();

    Time multiPlay = play * 2;

    multiPlay.show();
    cout << "-------------------------\n";
//    total = working.sum(play);

    total = play + working;
    total.show();

    working.reset();
    play.reset();
    total.reset();

    total.show();

    cout << "#########################\n";
    const Time t = Time(3, 45);
    Time temp = 3 * t;
    temp.show();

    cout << "temp.toString():" << temp << endl << temp;
    return 0;
}