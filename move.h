//
// Created by cat on 2017/12/23.
//

#ifndef CPP02_MOVE_H
#define CPP02_MOVE_H


class Move {

private:
    double x, y;
public:
    Move(double a = 0, double b = 0);

    void showMove() const;

    Move add(const Move &m) const;

    void reset(double a = 0, double b = 0);

    Move &add2(const Move &m)  ;

};


#endif //CPP02_MOVE_H
