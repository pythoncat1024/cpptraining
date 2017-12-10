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

int main() {
    using namespace std;
    pAdd = add;
    int zz = (*pAdd)(3, 4);

    cout << "zz=" << zz << endl;
    cout << "# # # # # # # # # # # # " << endl;

    pFunAdd funAdd = add;

    int q = funAdd(5, 6);

    cout << "q =" << q << endl;
    return 0;
}

int add(int x, int y) {
    return x + y;
}
