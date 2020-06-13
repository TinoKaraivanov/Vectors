#include "triangle.hpp"

//d = ((x2 - x1)2 + (y2 - y1)2 + (z2 - z1)2)1/2

double Triangle::length(Point& p1, Point& p2){
    return pow(pow(p2.getX() - p1.getX(),2) + pow(p2.getY() - p1.getY(),2) + pow(p2.getZ() - p1.getZ(),2),0.5);
   }

///Êîíñòðóêòîð â êîéòî èìàìå ïðîâåðêà çà âàëèäíîñò íà òðèúãúëíèê.
Triangle::Triangle(Point& firstPoint, Point& secondPoint, Point& thirdPoint){
    if(firstPoint.getX() == secondPoint.getX() && firstPoint.getY() == secondPoint.getZ()) throw EPE(1,2);
    if(firstPoint.getX() == thirdPoint.getX() && firstPoint.getY() == thirdPoint.getZ()) throw EPE(1,3);
    if(secondPoint.getX() == thirdPoint.getX() && secondPoint.getY() == thirdPoint.getZ()) throw EPE(2,3);
    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->thirdPoint = thirdPoint;
    cout <<"Triangle with Points:  " << firstPoint << ',' << secondPoint << ',' << thirdPoint << endl;
    aLen = length(this->secondPoint, this->thirdPoint);
    bLen = length(this->firstPoint, this->thirdPoint);
    cLen = length(this->firstPoint, this->secondPoint);
}

double Triangle::maximum() {
    Triangle& t1 = *this;
    double max = t1.aLen;

    if (t1.bLen > max) {
        max = t1.bLen;
}
    if (t1.cLen > max) {
        max = t1.cLen;
}
    return max;
}

double Triangle::Perimetar()
{
    Triangle& t1 = *this;
    return(t1.aLen + t1.bLen + t1.cLen);
}
///Ìåòîä çà èç÷èñëåíèå íà ëèöå íà òðèúãúëíèê ïî Õåðîíîâà ôîðìóëà.
double Triangle::areaTriangle()
{
    Triangle& t1 = *this;
    double p = t1.poluPerimetar();
    return sqrt(p*(p-aLen)*(p-bLen)*(p-cLen));
}

///Ìåòîä çà íàìèðàíå íà ïåðèìåòúðà íà òðèúãúëíèê a+b+c.
double Triangle::poluPerimetar()
{
    Triangle& t1 = *this;
    return (t1.Perimetar())/2;
}

///Ìåòîä çà íàìèðàíå íà ìåäèàíà 1.
double Triangle::mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///ôîðìóëà çà íàìèðàíå íà ìåäèàíà íà mX(mA).
    return(sqrt(2*(ThirdPoint.getZ()*ThirdPoint.getZ())+2*(secondPoint.getY()*secondPoint.getY())-
                (firstPoint.getX()*firstPoint.getX()))/2);
}
///Ìåòîä çà íàìèðàíå íà ìåäèàíà 2.
double Triangle::mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///ôîðìóëà çà íàìèðàíå íà ìåäèàíà íà mY(mB).
    return (sqrt(2*(ThirdPoint.getZ()*ThirdPoint.getZ())+2*(firstPoint.getX()*firstPoint.getX())-
                 (secondPoint.getY()*secondPoint.getY()))/2);
}
///Ìåòîä çà íàìèðàíå íà ìåäèàíà 3.
double Triangle::mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///ôîðìóëà çà íàìèðàíå íà ìåäèàíà íà mZ(mC).
    return(sqrt(2*(firstPoint.getX()*firstPoint.getX())+2*(secondPoint.getY()*secondPoint.getY())-
                (ThirdPoint.getZ()*ThirdPoint.getZ()))/2);
}
///Ìåòîä çà íàìèðàíå íà ìåäèöåíòúð.
double Triangle::mediCentar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{

    double m1 = mX(firstPoint, secondPoint, ThirdPoint);
    double m2 = mY(firstPoint, secondPoint, ThirdPoint);
    double m3 = mZ(firstPoint, secondPoint, ThirdPoint);

    ///ôîðìóëà çà ìåäèöåíòúð.
    return ((m1 + m2 + m3)/3);
    /*((mX(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mY(Point& firstPoint, Point& secondPoint, Point& ThirdPoint) +
    mZ(Point& firstPoint, Point& secondPoint, Point& ThirdPoint))/3);
    */
}

//std::ostream& operator <<(std::ostream& out, const Triangle& p) {
//    out << '(' << (firstpoint) << ',' << (secondpoint) << ',' << (thirdpoint) << ')';
//    return out;
//}
