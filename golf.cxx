//
// Created by cat on 2017/12/17.
//

#include "golf.h"
#include <iostream>
#include <cstring>

void setgolf(golf &g, const char *name, int hc) {
    strncpy(g.fullname, name, Len);
    g.handicap = hc;
}

int setgolf(golf &g) {
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
    if (temp == NULL || temp[0] == '\0' || !cin) {
        cout << "pos=" << pos << "temp=" << temp << endl;
        goto stop;
    }
    cout << msg2;
    cin >> hc;
    setgolf(g, temp, hc);
    ret = 1;
    stop:;
    // reset cin start {
    cin.clear();
    while (cin.get() != '\n')continue;
    // reset cin  end  }

    cout << "finish pos " << pos << endl;
    return ret;
}

void handicap(golf &g, int hc) {
    g.handicap = hc;
}

void showgolf(golf &g) {
    std::cout << "{" << g.fullname << " , "
              << g.handicap << "}" << std::endl;
}