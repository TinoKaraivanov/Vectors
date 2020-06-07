#ifndef line_hpp
#define line_hpp
#include "point.hpp"
#include "vector.hpp"

class Line:public Vector{
private:
    Point p1;
    Point p2;
public:
    Line();
    Point LineStart();
    Point LineEnd();
    Line (Point , Vector );
    Line (Point& , Point& );
    double lenght(Point&, Point&);
    Vector getDirection(Point&, Point&);
    Vector normalVector(Line&, Point&);
    
    
    //getters
    double getX() {
          return this->x;
      }

    double getY() {
          return this->y;
      }

    double getZ() {
          return this->z;
      }

    
};
    
#endif
