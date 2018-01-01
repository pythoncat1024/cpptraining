//
// Created by cat on 2018/1/1.
//

#ifndef CPP02_STEP_H
#define CPP02_STEP_H

#include <iostream>
#include <math.h>

/**
 * 矢量类
 */
namespace VECTOR{
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

        Vector &set2RECT(); // 转成正坐标
        Vector &set2POL(); // 转成正坐标

        double radian2Angle(double radian) // 弧度转角度
        {
            return 1.0 * radian / M_PI * 180;
        }

        double angle2Radian(double angle)// 角度转弧度
        {
            return 1.0 * angle * M_PI / 180;
        }

    public:
        Vector(double num1 = 0, double num2 = 0, Mode currentMode = POL);

        Vector(const Vector &data);


        virtual ~Vector();

        void reset(double num1 = 0, double num2 = 0, Mode currentMode = POL);

// operator
        Vector operator*(double factor);

        Vector operator-();

        // friend operator
        friend std::ostream &operator<<(std::ostream &os, Vector &obj); // toString

        friend Vector operator+(Vector one, Vector another);

        friend Vector operator-(Vector one, Vector another);

        friend Vector operator*(double factor, Vector obj);
    };


}

#endif //CPP02_STEP_H
