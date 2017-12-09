#include <iostream>

using namespace std;
const int SLEN = 30;
struct student {
    char fullName[SLEN];
    char hobby[SLEN];
    int oopLevel;
};

int getinfo(student pa[], int n);

void display1(student st);

void display2(student *st);

void display3(const student pa[], int n);

/*
 * 补全程序
 */
int main() {
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student *ptr_stu = new student[class_size];

    int entered = getinfo(ptr_stu, class_size);

    for (int i = 0; i < entered; ++i) {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;

    cout << "Done\n";
    return 0;
}























