//
// Created by cat on 2018/1/1.
//

#include "Vector.h"

namespace VECTOR {


    Vector::Vector(const Vector &data) {

        this->xLen = data.xLen;
        this->yLen = data.yLen;
        this->angle = data.angle;
        this->length = data.length;
        this->currentMode = data.currentMode;
    }


    Vector::Vector(double num1,
                   double num2,
                   Vector::Mode currentMode) {
        reset(num1, num2, currentMode);
    }

    void Vector::reset(double num1,
                       double num2,
                       Vector::Mode currentMode) {
        this->currentMode = currentMode;
        if (this->currentMode == POL) {
            this->angle = num1;
            this->length = num2;

            this->xLen = sin(radian2Angle(num1)) * num2;
            this->yLen = cos(radian2Angle(num1)) * num2;
        } else if (this->currentMode == RECT) {
            this->xLen = num1;
            this->yLen = num2;

            this->angle = radian2Angle(atan2(this->yLen, this->xLen));
            double len2 = pow(this->xLen, 2) + pow(this->yLen, 2);
            this->length = pow(len2, 0.5);
        } else {
            throw "error!";
        }
    }

    Vector::~Vector() {
        this->currentMode = POL;
        this->angle = 0;
        this->length = 0;
        this->xLen = 0;
        this->yLen = 0;

    }


    Vector operator+(Vector one, Vector another) {
        Vector obj;

        one = one.set2RECT();
        another = another.set2RECT();

        obj = Vector(one.xLen + another.xLen, one.yLen + another.yLen, Vector::RECT);
        return obj;
    }

    Vector VECTOR::operator+=(Vector one, Vector another) {
        return operator+(one, another);
    }

    Vector &Vector::set2RECT() {
        if (this->currentMode == Vector::RECT) {
            return *this;
        } else if (this->currentMode == Vector::POL) {
            this->currentMode = Vector::RECT;
            this->xLen = this->length * cos(this->angle2Radian(this->angle));
            this->yLen = this->length * sin(this->angle2Radian(this->angle));
        }
        return *this;

    }

    Vector &Vector::set2POL() {
        if (this->currentMode == Vector::POL) {
            return *this;
        } else {
            this->currentMode = Vector::POL;
            this->angle = radian2Angle(atan2(this->yLen, this->xLen));
            double len2 = pow(this->xLen, 2) + pow(this->yLen, 2);
            this->length = pow(len2, 0.5);
        }
        return *this;
    }

    Vector operator-(Vector one, Vector another) {
        Vector::Mode mode = one.currentMode;
        one = one.set2RECT();
        another = another.set2RECT();
        Vector v = Vector(one.xLen - another.xLen, one.yLen - another.yLen, Vector::RECT);
        v.currentMode = mode;
        return v;
    }

    Vector operator-=(Vector one, Vector another) {
        return operator-(one, another);
    }

    Vector Vector::operator*(double factor) {
        Vector obj;
        Vector::Mode mode = this->currentMode;
        this->set2RECT();
        obj = Vector(this->xLen * factor, this->yLen * factor, Vector::RECT);
        obj.currentMode = mode;
        return obj;
    }

    Vector Vector::operator*=(double factor) {
        return operator*(factor);
    }

    Vector operator*(double factor, Vector obj) {
        return obj * factor;
    }

    Vector operator*=(double factor, Vector obj) {
        return operator*(factor, obj);
    }


    Vector Vector::operator-() {
        Mode mode = this->currentMode;
        this->set2RECT();
        Vector v = Vector(-this->xLen, -this->yLen, Vector::RECT);
        v.currentMode = mode;
        return v;
    }


    std::ostream &operator<<(std::ostream &os, Vector &obj) {
        std::ios_base::fmtflags pref;
        std::streamsize preC;
        pref = os.setf(std::ios_base::fixed);  // store prev
        preC = os.precision(1); // store prev

        os << "Vector:(" << obj.xLen << " , " << obj.yLen << ")|[RECT]\t";
        os.precision(2);
        os << "Vector:(" << obj.angle << " , " << obj.length << ")|[POL]\t";

        if (obj.currentMode == Vector::RECT) {
            os << "{RECT}\n";
        } else {
            os << "\t{POL}\n";
        }
        os.setf(pref);  // reset
        os.precision(preC); // reset

        return os;
    }


}