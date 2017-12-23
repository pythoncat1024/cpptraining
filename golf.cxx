//
// Created by cat on 2017/12/17.
//

#include "golf.h"
#include <iostream>
#include <cstring>


golf &golf::setgolf() {
    using namespace std;

    static int pos = 0;
    int ret = 0;
//    cout << "a" << std::endl;
    const string msg1 = "输入用户的姓名：";
    const string msg2 = "输入用户的等级：";

//    golf golfArr[ArrSize]{};

    char temp[Len];
    int hc;
    cout << msg1;
    cin.get(temp, Len);
    pos += 1;
    if ( temp[0] == '\0' || !cin) {
        cout << "ERROR:pos=" << pos << "temp=" << temp << endl;
        goto stop;
    }
    cout << msg2;
    cin >> hc;
//    setgolf(g, temp, hc);
    *this = golf(temp, hc);
    stop:;
    // reset cin start {
    cin.clear();
    while (cin.get() != '\n')continue;
    // reset cin  end  }
    cout << "finish pos " << pos << endl;
    return *this;
}

void golf::handicap(int hc) {
    this->hand = hc;
}

void golf::showgolf() const {
    std::cout << "{" << this->fullname << " , "
              << this->hand << "}" << std::endl;
}

golf::golf(const char *fullname, int handicap) {

    strncpy(this->fullname, fullname, Len);
    this->hand = handicap;
}




