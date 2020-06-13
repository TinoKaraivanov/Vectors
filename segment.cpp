#include "segment.hpp"
#include "exceptions.hpp"

Segment::Segment() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

double Segment::getT() {
    return this->t1;
}
double Segment::getX() {
    return this->x;
}
double Segment::getY() {
    return this->y;
}
double Segment::getZ() {
    return this->z;
}

Segment::Segment(Point& pt1, Point pt2){
    pst = pt1;
    pend = pt2;
    
}

Segment::Segment(Point& pt1, Vector& vect1, double t1, double t2){
    if (t1 < 0 || t2 > 1){throw SIE();}
    pst.setX(pt1.getX() + vect1.getX() * t1);
    pst.setY(pt1.getY() + vect1.getY() * t1);
    pst.setZ(pt1.getZ() + vect1.getZ() * t1);
    
    pend.setX(pt1.getX() + vect1.getX() * t2);
    pend.setY(pt1.getY() + vect1.getY() * t2);
    pend.setZ(pt1.getZ() + vect1.getZ() * t2);
    cout << "Initialized: " << pst << " / " << pend << endl;
}

Vector Segment::getVect(){
    return this->Vect;
}

double Segment::segLen(){
    return sqrt(pow((pst.getZ() - pend.getZ()),2)
    +pow((pst.getX() - pend.getX()),2)
    +pow((pst.getY() - pend.getY()),2));
}



Point Segment::segMid(){
    Point ptMid;
    ptMid.setX((pend.getX() + pst.getX())/2);
    ptMid.setY((pend.getY() + pst.getY())/2);
    ptMid.setZ((pend.getZ() + pst.getZ())/2);

    return ptMid;
}


bool Segment::operator ==(const Point &pC) {
    Segment AC(pst, pC);
    Segment BC(pend, pC);
    return segLen() == AC.segLen() + BC.segLen();
}

istream& Segment::ext(ostream& in) const {
}

ostream& Segment::ins(ostream& out) const {
    return out;
}
