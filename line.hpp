#ifndef line_hpp
#define line_hpp
#include "vector.hpp"

class Line:public Vector{
private:
    Point p1;
    Point p2;
    Vector vect;
public:
    Line();
    Line (Point& ,Vector&);
    Line (Point& ,Point&);
    double lenght(Point&, Point&);
    Vector getDirection();
    Vector nmv();
    Vector getVect();
    Point getP1();
    Point getP2();
    double angle(Line&);
    
    bool lineParCheck(Line&);
    
    //overloading
    bool operator +  (Point&);
    bool operator || (Line&);
    bool operator != (Line&);
    bool operator |  (Line&);
    bool operator && (Line&);
    
    
};
    
#endif
