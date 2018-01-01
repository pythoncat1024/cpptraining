//
// Created by cat on 2018/1/1.
//

#ifndef CPP02_STEP_H
#define CPP02_STEP_H

#include <iostream>
#include <cmath>
#include <math.h>

#define Math_PI 3.1415927
/**
 * 矢量类
 */
namespace VECTOR {
    class Vector {

    public:
        enum Mode {
            /*正坐标*/ RECT,/*极坐标*/ POL
        };
    private:
        Mode currentMode;
        double angle; // 角度 （0～360度）
        double length; // 步长👅（1～3m)
        double xLen; // x 方向的位移
        double yLen; // y 方向的位移

        Vector set2RECT() const; // 转成正坐标
        Vector set2POL() const; // 转成正坐标

        double radian2Angle(double radian) const // 弧度转角度
        {
            return 1.0 * radian / Math_PI * 180;
        }

        double angle2Radian(double angle) const // 角度转弧度
        {
            return 1.0 * angle * Math_PI / 180;
        }

    public:
        Vector(double num1 = 0, double num2 = 0, Mode currentMode = POL);

        Vector(const Vector &data);

        double getLength() {
            return this->length;
        };

        virtual ~Vector();

        void reset(double num1 = 0, double num2 = 0, Mode currentMode = POL);

// operator
        Vector operator*(double factor);

        Vector operator*=(double factor);

        Vector operator-();

        // friend operator
        friend std::ostream &operator<<(std::ostream &os, Vector &obj); // toString

        friend Vector operator+(const Vector &one, const Vector &another);

        friend Vector operator+=(Vector &one, const Vector &another);

        friend Vector operator-(const Vector &one, const Vector &another);

        friend Vector operator-=(Vector &one, const Vector &another);

        friend Vector operator*(double factor,  Vector &obj);

        friend Vector operator*=(double factor, Vector &obj);
    };


}

#endif //CPP02_STEP_H
