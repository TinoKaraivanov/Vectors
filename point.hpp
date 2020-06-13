#ifndef H_POINT_H
#define H_POINT_H
#include "Libs.h"
class Point
{
protected:
    
public:
    double x, y, z;
    Point();
    Point(double, double, double);

    //Getters
    double getX();
    double getY();
    double getZ();

    void setX(double);
    void setY(double);
    void setZ(double);

    friend bool operator ==(Point, Point);
    friend std::ostream& operator <<(std::ostream&, Point);
};

#endif
#pragma once
