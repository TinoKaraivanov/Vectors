#include "segment.hpp"
#include "exceptions.hpp"

Segment::Segment() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Segment::Segment(Point& pt1, Vector& vect1, double t){
    if (t < 0 || t > 1){
        throw EXCEPTT();
    }
    
    this->x = pt1.getX() + vect1.getX() * t;
    this->y = pt1.getY() + vect1.getY() * t;
    this->z = pt1.getZ() + vect1.getZ() * t;
    cout << "Segment: " << x << "\t" << y << "\t" << z << "\t" << endl;
}

unsigned Segment::segLen(){
    return sqrt(pow((Vector::getZ() - Point::getZ()),2)
    +pow((Vector::getX() - Point::getX()),2)
    +pow((Vector::getY() - Point::getY()),2));
}

unsigned Segment::lenSeg(Vector& vect2,Point& pt2){
    return sqrt(pow((vect2.getZ() - pt2.getZ()),2)
    +pow((vect2.getX() - pt2.getX()),2)
    +pow((vect2.getY() - pt2.getY()),2));
    
}
//Vector::Vector(Point& p1, Point& p2) {
//    this->x = p2.getX() - p1.getX();
//    this->y = p2.getY() - p1.getY();
//    this->z = p2.getZ() - p1.getZ();
//}
