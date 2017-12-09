#include<stdio.h>
#include <iostream>


using namespace std;

int Fill_array(double *arr, int length);

void Show_array(const double *arr, int size);

void Reverse_array(double *arr, int size);

/*
 编写一个程序，它使用下列函数：
 Fill_array()将一个double 数组的名称和长度作为参数。它提示用户输入double值，并将
 这些值存储到数组中。当数组被填满或用户输入了非数字时，输入将停止，并返回实际输入了多少个数字。
 Show_array()将一个double数组的名称和长度作为参数，并显示该数组的内容。
 Reverse_array()将一个double数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。
 程序将使用这些函数来填充数组，然后显示数组；反转数组，然后显示数组；反转数组中除了第一个和
 最后一个元素之外的所有元素，然后显示数组。
 */
int main(void) {
    const int MaxLength = 20;
    double arr[MaxLength];
    int size = Fill_array(arr, MaxLength);
    Show_array(arr, size);
    Reverse_array(arr, size);
    Show_array(arr, size);
    Reverse_array(arr + 1, size - 2);
    Show_array(arr, size);
    return 0;
}

void Reverse_array(double *arr, int size) {
    double temp;
    for (int i = 0; i < size; ++i) {
        int begin = i;
        int end = size - i - 1;
        if (begin < end) {
            temp = arr[begin];
            arr[begin] = arr[end];
            arr[end] = temp;
        }
    }
}

void Show_array(const double *arr, int size) {
    cout << "arr(" << size << "):[";
    for (int i = 0; i < size - 1; ++i) {
        cout << arr[i] << ",";
    }
    cout << arr[size - 1] << "]" << endl;
}

int Fill_array(double *arr, int length) {
    cout << "请输入数组元素，以空格作为间隔，提前结束输入，请按q，然后回车:";
    double num;
    int size = 0;
    for (int i = 0; i < length; ++i) {
        if (cin && (cin >> num)) {
            arr[i] = num;
            size++;
        }
    }
    return size;
}


