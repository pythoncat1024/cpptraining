//
// Created by cat on 2018/1/2.
//

#include <cstring>
#include <iostream>
#include "StringBad.h"

int StringBad::nums = 0;
bool StringBad::DEBUG_LIFESTYLE = true;
bool StringBad::DEBUG_OPERATOR = true;

StringBad::StringBad() {
    this->str = new char[1]; // 为什么要 new char[] ,为何和析构函数的 delete [] str 对应！
    this->str[0] = '\0';
    this->len = 0;
    if (StringBad::DEBUG_LIFESTYLE) {
        std::cout << StringBad::nums << "." << str << "|create..\n";
    }
    StringBad::nums++;
}

StringBad::StringBad(const char *str) {
    size_t len = std::strlen(str);
    this->len = (unsigned int) len;
    this->str = new char[this->len + 1];
    std::strncpy(this->str, str, this->len + 1);
    if (StringBad::DEBUG_LIFESTYLE) {
        std::cout << StringBad::nums << "." << str << "|create##\n";
    }
    StringBad::nums++;
}


StringBad::StringBad(const StringBad &obj) { // 复制构造函数 在 StringBad sb1 = sb2; 的时候调用
    this->len = obj.len;
    this->str = new char[this->len + 1];
    std::strncpy(this->str, obj.str, this->len + 1);

    if (StringBad::DEBUG_LIFESTYLE) {
        std::cout << StringBad::nums << "." << str << "|create^^\n";
    }
    StringBad::nums++;
}

StringBad::~StringBad() {
    StringBad::nums--;
    delete[]this->str;
    if (StringBad::DEBUG_LIFESTYLE) {
        std::cout << StringBad::nums << "*" << str << "|release..\n";
    }
}

std::ostream &operator<<(std::ostream &os, const StringBad &obj) {
    os << obj.str << "|toString()\n";
    return os;
}

StringBad &StringBad::operator=(const StringBad &obj) { // 赋值运算符 在 sb1 = sb2; 的时候调用
    if (StringBad::DEBUG_OPERATOR) {
        std::cout << str << ":operator=\n";
    }
    if (this == &obj) {
        return *this;  // 如果是把自己赋值给自己，就直接返回自己
    }
    delete[]this->str; // 释放之前的
    this->len = obj.len;
    this->str = new char[this->len + 1]; // 申请新的
    std::strncpy(this->str, obj.str, this->len + 1);
    return *this;
}


