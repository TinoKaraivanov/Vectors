#include "segment.hpp"
#include "exceptions.hpp"

Segment::Segment() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
    //Constructors
Segment::Segment(Point& pt1, Point pt2){
    pst = pt1;
    pend = pt2;
}
Segment::Segment(Point& pt1, Vector& vect1, double it1, double it2){
    if (t1 < 0 || t2 > 1){throw SIE();}
    t1 = it1;
    t2 = it2;
    pst.setX(pt1.getX() + vect1.getX() * t1);
    pst.setY(pt1.getY() + vect1.getY() * t1);
    pst.setZ(pt1.getZ() + vect1.getZ() * t1);
    
    pend.setX(pt1.getX() + vect1.getX() * t2);
    pend.setY(pt1.getY() + vect1.getY() * t2);
    pend.setZ(pt1.getZ() + vect1.getZ() * t2);
}
Segment::Segment(Segment& s1, Segment& s2) {
    this->pst = s2.pst;
    this->pend = s2.pend;
    this->Vect = s2.Vect;
}
    //namirane na sreda na otsechka, koqto vrushta tochka s koordinati
double Segment::segLen(){
    return sqrt(pow((pst.getZ() - pend.getZ()),2)
    +pow((pst.getX() - pend.getX()),2)
    +pow((pst.getY() - pend.getY()),2));
}
    //namirane na duljina na otsechka, koqto vrushta polojitelno realno chislo
Point Segment::segMid(){
    Point ptMid;
    ptMid.setX((pend.getX() + pst.getX())/2);
    ptMid.setY((pend.getY() + pst.getY())/2);
    ptMid.setZ((pend.getZ() + pst.getZ())/2);
    return ptMid;
}
    //Operators
    //proverqva dali edna tochka leji za dadena otsechka
bool Segment::operator ==(const Point &pC) {
    Segment AC(pst, pC);
    Segment BC(pend, pC);
    return segLen() == AC.segLen() + BC.segLen();
}
std::ostream& operator <<(std::ostream& out, const Segment& s1) {
    out <<'(' << s1.pst.x << ',' << s1.pst.y << ',' << s1.pst.z <<
        "),("<<s1.pend.x << ',' << s1.pend.y << ',' << s1.pend.z <<"),["
        <<s1.t1 << ',' << s1.t2 << ']';
    return out;
}
istream &operator >>(istream  &input, Segment& s) {
    input >> s.pst >> s.pend >> s.t1 >> s.t2;
     return input;
}
