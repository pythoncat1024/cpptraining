#include<stdio.h>
#include <iostream>


using namespace std;

long recursion(int num);

void dropInput();
/*
 定义一个递归函数，接受一个整数参数，并返回该参数的阶乘。前面讲过，3的阶乘写作3!，等于3*2!，
 以此类推；而0!被定义为1。通用的计算公式是，如果n大于0，则n!=n*(n-1)!。在程序中对该函数
 进行测试，程序使用循环让用户输入不同的值，程序将报告这些值的阶乘。
 */
int main(void) {

    cout << " 请输入一个整数，用于计算其阶乘：";
    int num;
    while (cin && (cin >> num) && num >= 0) {
        dropInput();
        long ret = recursion(num);
        cout << "recursion(" << num << ")=" << ret << endl;
        cout << " 请输入一个整数，用于计算其阶乘：";
    }
    dropInput();
    cout << "输入无效，结束程序。" << endl;
    return 0;
}

long recursion(int num) {
    if (num == 0) {
        return 1;
    } else {
        return num * recursion(num - 1);
    }
}

void dropInput() {
    while (cin && cin.get() != '\n')continue;
}

