#ifndef segment_hpp
#define segment_hpp
#include "line.hpp"

class Segment:public Line{
private:
    Point pt;
    Vector Vect;
    double t;
    double x,y,z;
    
    
public:
    Segment();
    Segment(Point&, Vector&, double);
    unsigned segLen();
    unsigned lenSeg(Vector&, Point&);
    Point segMid(Vector&, Point&);
};




#endif
