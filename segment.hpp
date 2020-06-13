#ifndef segment_hpp
#define segment_hpp
#include "line.hpp"

class Segment:public Line{
private:
    Point pt;
    Point pst, pend;
    Vector Vect;
    double t1,t2;
    double x,y,z;
    
public:
    
    Segment();
    Segment(Point&, Vector&, double, double);
    Segment(Point& pt1, Point pt2);
    double segLen();
    Point segMid();
    bool segPointCheck();
    double shortDistance();
    bool operator ==(const Point&);
   
    Vector getVect();
    double getT();
    double getX();
    double getY();
    double getZ();
    istream& out(ostream&);
    ostream& in(istream&);
};


#endif
