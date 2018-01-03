//
// Created by cat on 2018/1/3.
//

#ifndef CPP02_STRINGBETTER_H
#define CPP02_STRINGBETTER_H


#include <ostream>

class StringBetter {

private:
    static const unsigned int CIN_LIM = 81;

    char *str;
    unsigned int len;
    static int num_strings;
    static bool DEBUG_LIFESTYLE;

public:
    // inline
    unsigned int length() { return this->len; }

    // constructor
    StringBetter();

    StringBetter(char *str);

    StringBetter(const StringBetter &obj);

    // destructor
    virtual ~StringBetter();

    // operator methods
    StringBetter &operator=(const StringBetter &obj);

    StringBetter &operator=(const char *st);

    char operator[](unsigned int index);

    const char operator[](unsigned int index) const;

    // friend operator methods
    friend bool operator>(const StringBetter &one, const StringBetter &another);

    friend bool operator<(const StringBetter &one, const StringBetter &another);

    friend bool operator==(const StringBetter &one, const StringBetter &another);

    friend bool operator!=(const StringBetter &one, const StringBetter &another);

    // friend operator io
    friend std::ostream &operator<<(std::ostream &os, const StringBetter &obj);

    friend std::istream &operator>>(std::istream &is, StringBetter &obj);

    // static function
    static int HowMany() {
        return num_strings;
    }
};


#endif //CPP02_STRINGBETTER_H
