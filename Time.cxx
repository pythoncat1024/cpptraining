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

Time Time::sum(const Time &another) const {
    Time total;
    total.minutes += this->minutes;
    total.hours += this->hours;

    total.hours += another.hours;
    total.minutes += another.minutes;
    total.hours += total.minutes / MINUTE_UNIT; // format start {@
    total.minutes %= MINUTE_UNIT; // format end @}
    return total;
}

void Time::show() const {

    using std::cout;
    cout << "Time{ " << this->hours << "h " << this->minutes << "m }\n";
}
