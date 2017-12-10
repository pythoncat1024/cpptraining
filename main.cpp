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

int add(int x, int y);

int main() {
    using namespace std;
    pAdd = add;
    int zz = (*pAdd)(3, 4);

    cout << "zz=" << zz << endl;
    return 0;
}

int add(int x, int y) {
    return x + y;
}
