#include <iostream>
#include "Student.h"

int main() {
    {

//    Student s2();  // bad type ,调用无参构造时，不要带括号，容易理解成一个方法，而不是初始化对象！
        Student s3; // good type , 无参构造就这样使用，不要带括号！
        Student s("比亚迪车主");
        s.show();
        s = Student("哈哈哈", 10, 10);
        s.show();
        s = Student();
        std::cout << s.getName() << " , " << s.getNameP() << std::endl;
        s.registerIn("tom", 23, 19);

        std::cout << " stu name==" << s.getName() << std::endl;
        s.testing(87);
        s.show();

        s.resetInfo();
        s.show();
//    s.play();

//        std::cout << "@@@@@@@@@@@@@@@@@@@\n";
//
//        const Student byd("byd");
//        byd.show();
    }
    return 0;
}