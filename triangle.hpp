#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"point.hpp"

class Triangle : public Point{
public:
    Triangle(Point&, Point&, Point&);
    Triangle(double&, double&, double&);
    void checkTriangleType();
    double Perimetar();
    double areaTriangle();
    double poluPerimetar();
    double mX(Point&, Point&, Point&);
    double mY(Point&, Point&, Point&);
    double mZ(Point&, Point&, Point&);
    double mediCentar(Point&, Point&, Point&);
    double length(Point&, Point&);
    void largestSide(double,double,double);
    double maximum();
private:
    Point firstPoint;
    Point secondPoint;
    Point thirdPoint;
    double aLen,bLen,cLen;
    double longest;
};
#endif // TRIANGLE_H
