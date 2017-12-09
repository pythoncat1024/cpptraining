#include<stdio.h>
#include <iostream>


using namespace std;
const int FieldMax = 47;
const int FieldSelected = 5;
const int SpecialMax = 27;
/**
 玩家从一组被成为区域号码(field number)的号码中选择几个。例如：可以从区域号码1~47中
 选择5个号码；还可以从第二个区间（如1~27）选择一个号码（称为特选号码）。要赢得头奖，必
 须正确猜中所有的号码。中头奖的几率是所有域号码的几率与选中特选号码几率的乘积。例如，在这
 个例子中，中头奖的几率是从47个号码中正确选取5个号码的几率与从27个号码中正确选中1个号码的
 乘积。计算中得这种彩票头奖的几率。
 */
int main(void) {

    double done = 0; // 中奖概率
    double base = 1; // 基数
    int num = FieldMax;
    for (int i = 0; i < FieldSelected; ++i) {
        base *= num;
        num--;
    }
    base *= SpecialMax;

    done = 1.0 / base;

    cout << "头奖的中奖概率为:" << done << endl;
    return 0;
}