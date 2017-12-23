//
// Created by cat on 2017/12/23.
//
#include <iostream>
#include "stack.h"

bool catStack::Stack::isEmpty() {
    return (this->arr.size()) == 0;
}



unsigned int catStack::Stack::add(catStack::Item obj) {
    this->arr.push_back(obj);
    return (unsigned int) this->arr.size();
}

unsigned int catStack::Stack::remove() {

    if (this->arr.size()>0) {
//        this->arr[top - 1] = NULL;
        this->arr.pop_back();
    } else {
        std::cout << " is already empty \n";
    }
    return (unsigned int) this->arr.size();
}

catStack::Stack::Stack() {
    std::cout << "stack create...\n";
}

catStack::Stack::~Stack() {

    std::cout << "stack destroy...\n";
}
