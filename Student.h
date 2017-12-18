//
// Created by cat on 2017/12/18.
//

#ifndef CPP02_STUDENT_H
#define CPP02_STUDENT_H


#include <string>

class Student {

public:
    Student(const std::string &name, int age = 18, int grade = 1);

private:
    std::string name;
    int age;
    double score;
    int grade;

    void play();

public:
    void registerIn(std::string name, int age, int grade);

    const std::string &getName();

    std::string *getNameP(); // 看一下默认的参数是不是空指针：并不是空指针
    int getAge();

    double getScore();

    void show();

    double testing(double score);

    void resetInfo();
};


#endif //CPP02_STUDENT_H
