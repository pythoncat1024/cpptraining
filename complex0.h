//
// Created by cat on 2018/1/1.
//

#ifndef CPP02_COMPLEX0_H
#define CPP02_COMPLEX0_H


#include <iosfwd>

namespace complex0 {

    class Complex {
    private:
        double realNum;
        double imaginaryNum;
    public:
        explicit Complex(double realNum = 0, double imaginaryNum = 0);

        virtual ~Complex();

        // inline getter
        double getImaginaryNum() const { return imaginaryNum; };

        double getRealNum() const { return realNum; };

        //  operator
        friend Complex operator+(const Complex &a, const Complex &b);

        friend Complex &operator+=(Complex &a, const Complex &b);

        friend Complex operator-(const Complex &a, const Complex &b);

        friend Complex &operator-=(Complex &a, const Complex &b);

        friend Complex operator*(double factor, const Complex &obj);

        friend Complex &operator*=(double factor, Complex &obj);


        friend Complex operator*(const Complex &a, const Complex &b);

        friend Complex &operator*=(Complex &a, const Complex &b);

        Complex operator~() const;

        // io
        friend std::ostream &operator<<(std::ostream &os, const Complex &cp);

        friend std::istream &operator>>(std::istream &iis,  Complex &cp);
    };

};


#endif //CPP02_COMPLEX0_H
