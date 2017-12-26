//
// Created by cat on 2017/12/26.
//

#ifndef CPP02_TIME_H
#define CPP02_TIME_H


class Time {

private:
    int hours;
    int minutes;
    static const unsigned short MINUTE_UNIT = 60;
public:
    Time();

    Time(int hours, int minutes);

    void addMin(int min);

    void addHour(int h);

    void reset(int h = 0, int m = 0);

    Time sum(const Time &another) const; // 末尾的const表示不修改 *this

    void show() const;

};


#endif //CPP02_TIME_H
