//
// Created by cat on 2018/1/1.
//

#include <iostream>
#include <sstream>
#include "complex0.h"

namespace complex0 {
    Complex::Complex(double realNum, double imaginaryNum)
            : realNum(realNum), imaginaryNum(imaginaryNum) {
//        std::cout << "-----------------create Complex("
//                  << realNum << "," << imaginaryNum << ")\n";
    }

    Complex::~Complex() {
//        std::cout << ".....................release Complex\n";
    }


    Complex operator+(const Complex &a, const Complex &b) {
        Complex cp = Complex();
        cp.realNum = a.realNum + b.realNum;
        cp.imaginaryNum = a.imaginaryNum + b.imaginaryNum;
        return cp;
    }

    Complex &operator+=(Complex &a, const Complex &b) {
        a.realNum += b.realNum;
        a.imaginaryNum += b.imaginaryNum;
        return a;
    }

    Complex operator-(const Complex &a, const Complex &b) {
        Complex cp;
        cp.realNum = a.realNum - b.realNum;
        cp.imaginaryNum = a.imaginaryNum - b.imaginaryNum;
        return cp;
    }

    Complex &operator-=(Complex &a, const Complex &b) {
        a.realNum -= b.realNum;
        a.imaginaryNum -= b.realNum;
        return a;
    }

// -------- factor *complex-----
    Complex operator*(double factor, const Complex &obj) {
        Complex cp;
        cp.realNum = factor * obj.realNum;
        cp.imaginaryNum = factor * obj.imaginaryNum;
        return cp;
    }

    Complex &operator*=(double factor, Complex &obj) {
        obj.realNum *= factor * obj.realNum;
        obj.imaginaryNum *= factor * obj.imaginaryNum;
        return obj;
    }


//  complex * complex
    Complex operator*(const Complex &a, const Complex &b) {
        // a=(A,B); b = (C,D); --> a*b=(A*C-B*D,A*D+B*C);
        Complex cp;
        cp.realNum = a.realNum * b.realNum - a.imaginaryNum * b.imaginaryNum;
        cp.imaginaryNum = a.realNum * b.imaginaryNum + a.imaginaryNum * b.realNum;
        return cp;
    }

    Complex &operator*=(Complex &a, const Complex &b) {
        Complex t = Complex(a.realNum, a.imaginaryNum);
        a.realNum = t.realNum * b.realNum - t.imaginaryNum * b.imaginaryNum;
        a.imaginaryNum = t.realNum * b.imaginaryNum + t.imaginaryNum * b.realNum;
        return a;
    }

    Complex Complex::operator~() const {
        Complex cp;
        cp.realNum = this->realNum;
        cp.imaginaryNum = -this->imaginaryNum;
        return cp;
    }


    std::ostream &operator<<(std::ostream &os, const Complex &cp) {
        os << "Complex(" << cp.realNum << "," << cp.imaginaryNum << ")\n";
        return os;
    }

    std::istream &operator>>(std::istream &iis, Complex &cp) {
        double xx;
//        std::stringstream ss;
//        std::string input;
//        getline(iis, input);
        if (iis >> xx) {
            cp.realNum = xx;
        } else {
            return iis;
        }

        if (iis >> xx) {
            cp.imaginaryNum = xx;
        } else {
            return iis;
        }
//        iis >> cp.realNum;
//        iis >> cp.imaginaryNum;
        iis.clear();
        return iis;
    }


}
