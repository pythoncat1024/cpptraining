//
// Created by cat on 2017/12/22.
//

#include <iostream>
#include "Person.h"
#include <cstring>

Person::Person() {
    this->lname = "";
    this->fname[0] = '\0';
}

Person::Person(const string &lname, const char *fname) {

    this->lname = lname;
//    this->fname = fname;
    strncpy(this->fname, fname, LIMIT);
}

void Person::show() const {

    using std::cout;
    using std::endl;
    cout << "firstName:" << this->fname
         << " , lastName:" << this->lname << endl;
}

void Person::FormalShow() const {
    using std::cout;
    using std::endl;
    cout << "lastName:" << this->lname
         << " , firstName:" << this->fname << endl;
}
