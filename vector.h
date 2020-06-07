
#ifndef H_VECTOR_H
#define H_VECTOR_H
#include "point.hpp"
#include <iostream>

class Vector : public Point
{
public:
    Vector();
    Vector(Point&, Point&);
    Vector(double, double, double);
    Vector(const Vector&);


    //Operations
    //Basic
    Vector operator +(const Vector&);
    Vector operator -(const Vector&);

    //Multiplications
    Vector operator *(double);
    double operator *(const Vector&);
    Vector operator ^ (const Vector&);
    double operator ()(Vector&, Vector&);


    //Methods
    double length();
    Vector getDirection();
    bool isNull()const;

    bool ortogonalityCheck(Vector&);
    bool paralellismCheck(Vector&);


    friend std::ostream& operator <<(std::ostream&, const Vector&);
};

#endif
