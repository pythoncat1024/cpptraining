//
// Created by cat on 2017/12/23.
//

#include <iostream>
#include "move.h"

Move::Move(double a, double b) {
    this->x = a;
    this->y = b;
}

void Move::showMove() const {
    std::cout << "Move[" << this->x << " , " << this->y << "]\n";
}

Move Move::add(const Move &m) const {
    Move rr = Move();
    rr.x += m.x;
    rr.y += m.y;
    return rr;
}

void Move::reset(double a, double b) {

    this->x = a;
    this->y = b;
}

Move &Move::add2(const Move &m) {
    this->x += m.x;
    this->y += m.y;
    return *this;
}
