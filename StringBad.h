//
// Created by cat on 2018/1/2.
//

#ifndef CPP02_STRINGBAD_H
#define CPP02_STRINGBAD_H


class StringBad {

private:
    char *str;
    unsigned int len;
    static int nums;
    static bool DEBUG_LIFESTYLE;
    static bool DEBUG_OPERATOR;
public:
    StringBad();

    StringBad(const char *str);

    StringBad(const StringBad &obj); // 复制构造
    virtual ~StringBad();

    friend std::ostream &operator<<(std::ostream &os, const StringBad &obj);

    StringBad& operator=(const StringBad &obj);

};


#endif //CPP02_STRINGBAD_H
