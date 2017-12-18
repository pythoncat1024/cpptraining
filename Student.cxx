//
// Created by cat on 2017/12/18.
//

#include <iostream>
#include "Student.h"

void Student::play() {
    std::cout << "I am playing now...\n";
}

void Student::registerIn(std::string str, int ages, int grades) {

    if (ages < 18) {
        ages = 18;
    }
    if (&name == NULL) {
        name = "";
    }
    if (grades < 1) {
        grades = 1;
    }
    this->age = ages;
    this->name = str;
    (*this).grade = grades;
    play();
}


int Student::getAge() {
    return this->age;
}

double Student::getScore() {
    return score;
}


void Student::show() {
    using std::cout;
    using std::endl;

    cout << "Student:{"
            "name:" << this->name << " , age:" << this->age
         << " , grade:" << this->grade << " , score=" << this->score
         << " }\n";

}

const std::string &Student::getName() {
    return this->name;
}

double Student::testing(double score) {
    if (score < 0) score = 0;
    this->score = score;
    return score;
}

void Student::resetInfo() {
    this->score = 0;
    this->grade = 1;
    this->age = 18;
    this->name = "";
    play();
}

