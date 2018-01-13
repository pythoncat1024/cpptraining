//
// Created by cat on 2018/1/13.
//

#include <iostream>
#include "SuperClass.h"

SuperClass::SuperClass(const std::string &name, int age)
        : name(name), age(age) {
    std::cout << "SuperClass(const std::string &name, int age)\n";

}

SuperClass::SuperClass(const SuperClass &sub) {
    this->name = sub.name;
    this->age = sub.age;
    std::cout << "SuperClass(const SuperClass &sub)\n";
}


void SuperClass::show() const {

    std::cout << "SuperClass-> name:" << this->name << " , age:" << this->age;

}

SuperClass &SuperClass::operator=(const SuperClass &sup) {
    std::cout << "SuperClass::operator=(const SuperClass &sup)\n";
    this->age = sup.age;
    this->name = sup.name;
    return *this;
}

SuperClass::~SuperClass() {

    std::cout << "~SuperClass()\n";
}

SubClass::SubClass(const std::string &name, int age, const std::string &id)
        : SuperClass(name, age), id(id) {

    std::cout << "SubClass(const std::string &name, int age, const std::string &id)\n";
}

SubClass::SubClass(const SuperClass &sub, const std::string &id)
        : SuperClass(sub), id(id) {
    std::cout << "SubClass(const SuperClass &sub, const std::string &id)\n";
}

void SubClass::show() const {
    SuperClass::show();
    std::cout << " , id:" << this->id;

    std::cout << "|#### SubClass\n";
}

SubClass::~SubClass() {

    std::cout << "::~SubClass()\n";
}

