#include <iostream>
#include "SuperClass.h"

int main() {

//    SuperClass sp = SuperClass("比亚迪车主", 25);

    SubClass sb = SubClass("东郭灰猫", 33, "1024x07253");
    // --> 先super构造，然后 sub构造，最后super复制构造

    SuperClass &s = sb;

//    sp.show();
    std::cout << std::endl;
//    sb.show();
    std::cout << std::endl;
    s.show();
    std::cout << std::endl;
    return 0;
}