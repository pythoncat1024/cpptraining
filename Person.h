//
// Created by cat on 2017/12/22.
//

#ifndef CPP02_PERSON_H
#define CPP02_PERSON_H

#include <string>

using std::string;

class Person {

private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];

public:
    Person();

    Person(const string &lname, const char *fname = "Heyyou");

    void show() const;  // firstName,lastName format

    void FormalShow() const; // lastName, firstName format
};


#endif //CPP02_PERSON_H
