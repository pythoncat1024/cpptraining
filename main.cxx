#include <iostream>
#include <sstream>
#include <random>
#include <fstream>
#include "Vector.h"

void end();

void resetCin();

void executeFromUser();

void execute(std::ostream &os, double length, double step);

void executeTimes(unsigned int times);

const unsigned int MAX_FREE = 10;

bool USER_INPUT = false; // 是否每次都让用户输入

static int usedTimes = 0;

static int currentSteps = 0;

int main() {
    using namespace std;
    using VECTOR::Vector;
    Vector v1 = Vector(20, 30, Vector::RECT);
    Vector v2 = Vector(40, 50, Vector::RECT);

    v1 += v2;
    cout << v1 << endl;

//    executeFromUser();
    executeTimes(100);

    std::ofstream out;
    out.open("abc.txt");
    out.close();
    return 0;
}

void executeTimes(unsigned int times) {
    using namespace std;
    using VECTOR::Vector;

    cout << "随机漫步模拟.\n";

    ofstream out;
    out.open("output.txt");
    double avg = 0;
    double length; // 总位移
    double eachLen;// 单步长度
    string input;
    stringstream ostr;

    cout << "请输入总位移长度（退出请按q）：";
    getline(cin, input);
    ostr << input;
    while (1) {
        if (ostr >> length) {
            cout << "length==" << length;
            ostr.clear();
            cout << "请输入单步位移长度（退出请按q）：";
            getline(cin, input);
            ostr << input;
            if (ostr >> eachLen) {
                cout << "todo: SUCCESS\n";
                for (int pos = 0; pos < times; ++pos) {
                    execute(out, length, eachLen);
                    avg += currentSteps;
                }
                goto fuck;
            } else {
                cout << "输入不合法, 请重新输入！\n";
            }
        } else {
            cout << "输入不合法, 请重新输入！\n";
        }
    }
    fuck:;

    avg = avg / times;
    streamsize precision = cout.precision(2);
    streamsize precision1 = out.precision(2);
    cout << "随机漫步目标位移为" << length << "时的平均步数为：" << avg << "\n";
    out << "随机漫步目标位移为" << length << "时的平均步数为：" << avg << "\n";
    cout.precision(precision);
    out.precision(precision1);
    out.close();
}

void execute(std::ostream &os, double length, double step) {
//    using namespace std;
    using VECTOR::Vector;
    Vector init{};
//    cout << "init.Length=" << init.getLength() << " , length=" << length << endl;
    while (init.getLength() < length) {
        currentSteps++;
        double angle = random() % 360;
        double el = step;
        Vector each = Vector(angle, el);
//                    cout << "........each:" << each;
        init += each;
    }
    std::streamsize precision = os.precision(2);
    os << "RESULT:" << init;
    os << "这一次走完目标距离(" << length << ")一共用了[" << currentSteps << "]步，";
    os << "目前距离长度为：" << init.getLength() << " > 目标长度：" << length << std::endl;
    usedTimes++;
//    os << "还有(" << (MAX_FREE - usedTimes) << ")次机会\n";
    os.precision(precision);
}

void executeFromUser() {
    using namespace std;
    using VECTOR::Vector;
    cout << "随机漫步模拟.\n";
    double length; // 总位移
    double eachLen;// 单步长度

    string input;
    stringstream ostr;
    while (usedTimes <= MAX_FREE) {
        cout << "请输入总位移长度（退出请按q）：";
        getline(cin, input);
        ostr << input;
        if (ostr >> length) {
            cout << "length==" << length;
            ostr.clear();
            cout << "请输入单步位移长度（退出请按q）：";
            getline(cin, input);
            ostr << input;
            if (ostr >> eachLen) {
                cout << "todo: SUCCESS\n";
                execute(cout, length, eachLen);
                if (!USER_INPUT) {
                    goto fuck;
                }
            } else {
                cout << "输入不合法, 请重新输入！\n";
            }
        } else {
            cout << "输入不合法, 请重新输入！\n";
        }
    }

    if (usedTimes > MAX_FREE) {
        cout << "体验机会已经用光，继续体验请充值~^_^\n";
    }
    end();
    fuck:;
}

void end() {
    resetCin();
    std::cout << "Bye.\n";
}

void resetCin() {
    std::cin.clear();
    while (std::cin.get() != '\n')continue;
}