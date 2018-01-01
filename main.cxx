#include <iostream>
#include <random>
#include "Vector.h"

//typedef VECTOR::Vector Vector;

void end();

void resetCin();

int main() {

    using namespace std;
    using VECTOR::Vector;

    const unsigned int MAX_FREE = 10;
    cout << "随机漫步模拟.\n";

    double length; // 总位移
    double eachLen;// 单步长度

    int usedTimes = 0;
    while (usedTimes <= MAX_FREE) {
        cout << "请输入总位移长度（退出请按q）：";
        int first = cin.get();
        if (first == 'q') {
            break;
        } else if (isalpha(first)) {
            resetCin();
            cout << "输入单个字符不合法, 请重新输入！\n";
        } else {
            if (cin >> length) {
                cout << "请输入单步位移长度（退出请按q）：";
                if (cin >> eachLen) {
                    // todo:
                    cout << "todo: SUCCESS\n";

                    Vector init{};
                    cout << "init.Length=" << init.getLength() << " , length=" << length << endl;
                    while (init.getLength() < length) {
                        double angle = random() % 360;
                        double el = eachLen;
                        Vector each = Vector(angle, el);
                        cout << "........each:" << each;
                        init += each;
                        usedTimes++;
                    }
                    cout << "RESULT:" << init;

                }
            } else {
                resetCin();
                cout << "输入过多不合法, 请重新输入！\n";
            }
        }
    }

    if (usedTimes > MAX_FREE) {
        cout << "体验机会已经用光，继续体验请充值~^_^\n";
    }
    end();
    return 0;
}

void end() {
    resetCin();
    std::cout << "Bye.\n";
}

void resetCin() {
    std::cin.clear();
    while (std::cin.get() != '\n')continue;
}