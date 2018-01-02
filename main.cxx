#include <iostream>
#include "StringBad.h"

using namespace std;

void callStr(StringBad &sb);

void callStr2(StringBad sb);

int main() {

    const char *s1 = "比亚迪车主";
    const char *s2 = "东郭灰猫";
    const char *s3 = "南郭竽";
    StringBad sb(s1);   // create##
    StringBad sb2 = sb; // create^^
    StringBad sb3 = s2; // create##


    StringBad ss = s3; // create##
    cout << sb;
    cout << sb2;
    cout << sb3;
    callStr(sb);
    callStr2(sb3); // create^^ , 因为是按值传递的，所以是数据的拷贝

    ss = sb3; // operator=

    StringBad strBad; // create..
    std::cout << "done." << endl;
    return 0;
}


void callStr(StringBad &sb) {

    cout << "callStr:" << sb;
}

void callStr2(StringBad sb) {
    cout << "callStr2:" << sb;
}