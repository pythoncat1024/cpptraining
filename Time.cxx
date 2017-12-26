//
// Created by cat on 2017/12/26.
//

#include <iostream>
#include "Time.h"

Time::Time() {
    this->hours = 0;
    this->minutes = 0;
}

Time::Time(int hours, int minutes)
        : hours(hours), minutes(minutes) {
    this->hours = hours;
    this->minutes = minutes;
}

void Time::addMin(int min) {
    this->minutes += min;
    this->hours += this->minutes / MINUTE_UNIT;
    this->minutes = this->minutes % MINUTE_UNIT;
}

void Time::addHour(int h) {
    this->hours += h;
}

void Time::reset(int h, int m) {
    this->hours = h;
    this->minutes = m;
}
//
//Time Time::sum(const Time &another) const {
//    Time total;
//    total.minutes += this->minutes;
//    total.hours += this->hours;
//
//    total.hours += another.hours;
//    total.minutes += another.minutes;
//    total.hours += total.minutes / MINUTE_UNIT; // format start {@
//    total.minutes %= MINUTE_UNIT; // format end @}
//    return total;
//}

void Time::show() const {

    using std::cout;
    cout << "Time{ " << this->hours << "h " << this->minutes << "m }\n";
}

Time Time::operator+(const Time &another) const {
    Time total;
    total.minutes += this->minutes;
    total.hours += this->hours;

    total.hours += another.hours;
    total.minutes += another.minutes;
    total.hours += total.minutes / MINUTE_UNIT; // format start {@
    total.minutes %= MINUTE_UNIT; // format end @}
    return total;
}

Time Time::operator-(const Time &another) const {
    Time cmp;
    int totSelf = this->minutes + this->hours * MINUTE_UNIT;
    int totOther = another.minutes + another.hours * MINUTE_UNIT;
    int diff = totSelf - totOther;

    cmp.minutes = diff % MINUTE_UNIT;
    cmp.hours = diff / MINUTE_UNIT;

    return cmp;
}

Time Time::operator*(double factor) const {
    Time multi;
    int total = (int) (this->hours * MINUTE_UNIT * factor
                       + this->minutes * factor);
    multi.minutes = total % MINUTE_UNIT;
    multi.hours += total / MINUTE_UNIT;
    return multi;
}

Time operator*(double factor, const Time &t) {
    // 这里的参数为何定义为 const Time &t ?
    // 因为按照c++的规则，const 形参可以接受，const和非const的实参，而非const形参，不能接受const实参！
    // （因为此时可能会改变这个参数，特别是对于引用参数）
    return t * factor; // 调用 [Time Time::operator*(double factor) const]
}
