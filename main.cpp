#include <iostream>
#include <string>

using namespace std;

struct student {
    std::string name;
    int age;
};

int main() {

    string str;
    unsigned long size = str.size(); // ok
    cout << "str=" << str << " , size=" << size << " , " << sizeof(str) << endl;
    cout << "# # # # # # # # # " << endl;

    student kelly;
    cout << kelly.name << " , " << kelly.age << sizeof(kelly) << endl; // ok
    cout << "-- # # # # # # # # # " << endl;

    student *rose = new student;
    cout << (*rose).name << " , " << (*rose).age << sizeof(*rose) << endl;

    delete rose;
    return 0;
}