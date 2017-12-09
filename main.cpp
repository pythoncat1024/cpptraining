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

void dropInput();

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

void display3(const student pa[], int n) {
    for (int i = 0; i < n; ++i) {
        student st = pa[i];
        cout << "3st:{"
             << st.fullName << ","
             << st.hobby << ","
             << st.oopLevel << "}" << endl;
    }
}

void display2(student *st) {
    cout << "2st:{"
         << st->fullName << ","
         << st->hobby << ","
         << st->oopLevel << "}" << endl;
}

void display1(student st) {
    cout << "1st:{"
         << st.fullName << ","
         << st.hobby << ","
         << st.oopLevel << "}" << endl;
}


int getinfo(student pa[], int n) {

    int i;
    bool exit = false;
    for (i = 0; i < n; ++i) {
        cout << "请输入第" << (i + 1) << "个学生的姓名：" << endl;
        cin.get(pa[i].fullName, SLEN);
        dropInput();
        cout << "请输入第" << (i + 1) << "个学生的爱好：" << endl;
        cin.get(pa[i].hobby, SLEN);
        dropInput();
        cout << "请输入第" << (i + 1) << "个学生的等级：" << endl;
        if (!(cin >> pa[i].oopLevel)) { // 只能这样子，不能做成变量然后判断！
            exit = true;
        }
        dropInput();
        if (exit) {
            cout << "illegal input #### " << endl;
            i++;
            break;
        }
    }
    return i;
}

void dropInput() {
    while (cin && cin.get() != '\n')
        continue;
    cin.clear();
}





















