#include<stdio.h>
#include <iostream>


using namespace std;
const int Max = 10;

int input(double *arr); // 输入函数
void show(const double *arr, int len); // 一行显示成绩
double average(const double *arr, int len); // 报告平均成绩
void dropInput(); // 丢弃多余输入
/**
 编写一个程序，要求用户输入最多10个高尔夫成绩，并将其存储在一个数组中。程序允许用户提早结束
 输入，并在一行显示所有的成绩，然后报告平均成绩。请使用3个数组处理的函数来分别进行输入、显示
 和计算平均成绩。
 */
int main(void) {

    double arr[Max];
    int size = input(arr);
    show(arr, size);
    double avg = average(arr, size);
    cout << "avg==" << avg << endl;

    return 0;
}

double average(const double *arr, int size) {
    double total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total / size;
}

void show(const double *arr, int size) {
    cout << "arr(" << size << "):[";
    for (int i = 0; i < size - 1; ++i) {
        cout << arr[i] << ",";
    }
    cout << arr[size - 1] << "]" << endl;
}

int input(double *arr) {
    int size = 0;
    double element;
    while (size < Max && (cin >> element) && element > 0) {
        dropInput();
        cout << "ele==" << element << endl;
        *arr++ = element;
        size++;
    }
    dropInput();
    return size;
}

void dropInput() {
    while (cin && cin.get() != '\n')continue;
    cin.clear();
}

