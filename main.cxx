#include <iostream>
#include "Student.h"

int main() {

    Student s("比亚迪车主");
    s.show();
    s = Student("哈哈哈", 0, 0);
    s.show();
    std::cout << s.getName() << " , " << s.getNameP() << std::endl;
    s.registerIn("tom", 23, 19);

    std::cout << " stu name==" << s.getName() << std::endl;
    s.testing(87);
    s.show();

    s.resetInfo();
    s.show();
//    s.play();
    return 0;
}