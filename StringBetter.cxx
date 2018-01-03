//
// Created by cat on 2018/1/3.
//

#include "StringBetter.h"
#include <cstring>
#include <iostream>

bool StringBetter::DEBUG_LIFESTYLE = true;
int StringBetter::num_strings = 0;
using std::strncpy;
using std::strcmp;

StringBetter::StringBetter() {
    this->str = new char[1];
    this->str[0] = '\0';
    this->len = 0;
    if (StringBetter::DEBUG_LIFESTYLE) {
        std::cout << num_strings << "." << this->str << "|create()\n";
    }
    num_strings++;

}

StringBetter::StringBetter(char *str) {
    size_t strLen = std::strlen(str);
    this->len = (unsigned int) strLen;
    this->str = new char[this->len + 1];
    strncpy(this->str, str, this->len + 1);
    if (StringBetter::DEBUG_LIFESTYLE) {
        std::cout << num_strings << "." << this->str << "|create(char*)\n";
    }
    num_strings++;
}

StringBetter::StringBetter(const StringBetter &obj) {
    this->len = obj.len;
    this->str = new char[this->len + 1];
    strncpy(this->str, obj.str, this->len + 1);
    if (StringBetter::DEBUG_LIFESTYLE) {
        std::cout << num_strings << "." << this->str << "|create(StringBetter)\n";
    }
    num_strings++;
}

StringBetter::~StringBetter() {
    delete[]this->str;
    num_strings--;
    if (StringBetter::DEBUG_LIFESTYLE) {
        std::cout << num_strings << "." << this->str << "|destroy\n";
    }
}

StringBetter &StringBetter::operator=(const StringBetter &obj) {
    if (this != &obj) {
        delete[]this->str;
        this->len = obj.len;
        this->str = new char[this->len + 1];
        std::strncpy(this->str, obj.str, this->len + 1);
    }
    return *this;
}

StringBetter &StringBetter::operator=(const char *st) {
    size_t strLen = std::strlen(st);
    this->len = (unsigned int) strLen;
    this->str = new char[this->len + 1];
    std::strncpy(this->str, st, this->len + 1);
    return *this;
}

char StringBetter::operator[](unsigned int index) {
    if (index > this->len) {
        std::cout << "illegal index in range(0," << this->len << ")\n";
    }
    return this->str[index];
}

const char StringBetter::operator[](unsigned int index) const {
    if (index > this->len) {
        std::cout << "illegal index in range(0," << this->len << ")\n";
    }
    return this->str[index];
}

bool operator>(const StringBetter &one, const StringBetter &another) {
    return std::strcmp(one.str, another.str) > 0;
}

bool operator<(const StringBetter &one, const StringBetter &another) {
    return another > one;
}

std::ostream &operator<<(std::ostream &os, const StringBetter &obj) {
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is, StringBetter &obj) {
    unsigned int len = StringBetter::CIN_LIM;
    char temp[len];
    is.getline(temp, len);
    return is;
}

bool operator==(const StringBetter &one, const StringBetter &another) {
    return strcmp(one.str, another.str) == 0;
}

bool operator!=(const StringBetter &one, const StringBetter &another) {
    return !(one == another);
}
