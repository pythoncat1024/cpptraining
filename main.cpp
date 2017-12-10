#include <iostream>

typedef double (*FuncAdd)(double, double);

double add(double, double);

double calculate(double a, double d, double (*add)(double, double));

/**
 设计一个名为 calculate()的函数，它接受两个double值和一个指向函数的指针，而被指向的函数
 接受两个double的参数，并返回一个double的值。calculate()函数的类型也是double,并返回
 被指向的函数使用calculate()的两个double参数计算得到的值。例如，假设add()函数的定义如下：
 double add(double x,double y)
 {
    return x+y;
 }
 则下述代码中的函数调用将导致calculate()把2.5和10.4传递给add()函数，并返回add()的返回值：
 double q = calculate(2.5,10.4,add);
 */

int main() {
    using namespace std;
    double a, b;
    cout << "请输入两个小数，以空格作为间隔，回车表示一组输入完成：";
    while ((cin >> a) && cin >> b) {
        while (cin && cin.get() != '\n') {
            continue;
        }
        cin.clear();
        double ret = calculate(a, b, add);
        cout << "calculate(" << a << "," << b << ")=" << ret << endl;
        cout << "请输入两个小数，以空格作为间隔，回车表示一组输入完成：";
    }
    cout << "Bad Input,Done." << endl;
    cout << "使用指针数组，让calculate()连续调用这些函数：" << endl;

    int time = 3;
    FuncAdd arr[time]; // 函数指针数组
    for (int i = 0; i < time; ++i) {
        arr[i] = add;
    }

    a = 1.23, b = 4.56;
    for (int j = 0; j < time; ++j) {
        double ret = calculate(a, b, add);
        cout << "calculate(" << a << "," << b << ")=" << ret << endl;
    }
    return 0;
}

double calculate(double a, double d, double (*add)(double, double)) {

    return add(a, d);
}

double add(double a, double b) {
    return a + b;
}
