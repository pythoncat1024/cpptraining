#include <iostream>
#include "stack.h"

int main() {
    using namespace std;
    using catStack::Stack;
    using catStack::customer;
    Stack s;
//    s.remove();
    customer c = {"张三", 29};
    customer c1 = {"李四", 30};

    s.add(c);
    s.add(c1);
    s.remove();

    s.add(c1);
    s.add(c);


    std::cout << "xxxxxxxxx\n";
    return 0;
}