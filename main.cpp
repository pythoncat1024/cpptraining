#include <iostream>

/*
char (*pFun)(int);

char glFun(int a) { ; }

int main() {
    pFun = glFun;
    (*pFun)(2);
    return 0;
}*/


int (*pAdd)(int, int); // 定义函数指针 pAdd , pAdd不是一个函数，而是函数指针

typedef int (*pFunAdd)(int, int); // 定义一个新的类型
// pFunAdd 到底是什么类型呢？是一个函数指针类型，
// 其中被指向的函数是参数为2个int,返回类型为int.

int add(int x, int y);

int sum(int x, int y);

void useArr(pFunAdd arr[], int size);

/**
 * 定义一个新的类型，如同int,char一样，类型名：pFuncUseArr
 */
typedef void (*pFunUseArr)(pFunAdd *arr, int size); // define a type

int main() {
    using namespace std;
    pAdd = add;
    int zz = (*pAdd)(3, 4);

    cout << "zz=" << zz << endl;
    cout << "# # # # # # # # # # # # " << endl;

    pFunAdd funAdd = add;

    int q = funAdd(5, 6);

    cout << "q =" << q << endl;

    cout << "函数指针数组：" << endl;
    pFunAdd arr[3] = {add, add, sum};
    useArr(arr, 3);

    cout << "函数指针-- " << endl;

    pFunUseArr pfu = useArr;

    pfu(arr+1, 2);
    return 0;
}

void useArr(pFunAdd arr[], int size) {
    int a = 3;
    int b = 4;
    using namespace std;
    for (int i = 0; i < size; ++i) {
        pFunAdd pf = arr[i];
        cout << "i=" << i << " , pf=" << pf
             << ":\t" << pf(a, b) << endl;
    }

}

int add(int x, int y) {
    return x + y;
}

int sum(int x, int y) {

    return x * x + y * y;
}
