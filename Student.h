//
// Created by cat on 2017/12/18.
//

#ifndef CPP02_STUDENT_H
#define CPP02_STUDENT_H


#include <string>

class Student {

private:
    std::string name;
    int age;
    double score;
    int grade;

    void play();

public:
    void registerIn(std::string name, int age, int grade);

    const std::string &getName();

    int getAge();

    double getScore();

    void show();

    double testing(double score);

    void resetInfo();
};


#endif //CPP02_STUDENT_H
