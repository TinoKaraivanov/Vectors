#include "triangle.hpp"

///Êîíñòðóêòîð â êîéòî èìàìå ïðîâåðêà çà âàëèäíîñò íà òðèúãúëíèê.
Triangle::Triangle(Point& firstPoint, Point& secondPoint, Point& thirdPoint){
    if(firstPoint.getX() == secondPoint.getX() && firstPoint.getY() == secondPoint.getY()) throw EqualPointException(1,2);
    if(firstPoint.getX() == thirdPoint.getX() && firstPoint.getY() == thirdPoint.getY()) throw EqualPointException(1,3);
    if(secondPoint.getX() == thirdPoint.getX() && secondPoint.getY() == thirdPoint.getY()) throw EqualPointException(2,3);

    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->thirdPoint = thirdPoint;
    cout << firstPoint << ',' << secondPoint << ',' << thirdPoint << endl;
}

///Ïîëóïåðèìåòúð íà òðèúãúëíèê
double Triangle::poluPerimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///ôîðìóëà çà ïîëóïåðèìåòúð ñáîð íà 3 ñòðàíè, êîéòî ñå äåëè íà 2.
    return(firstPoint.getX() + secondPoint.getY() + ThirdPoint.getZ())/2;
}
/// Ïðîâåðêà çà òèï íà òðèúãúëíèê.
void Triangle::checkTriangleType(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{


        ///Ïðîâåðêà çà ðàâíîñòðàíåí òðèúãúëíèê, êàòî ñðàâíÿâàìå ñòðàíèòå ìó.
        if(firstPoint.getX() == secondPoint.getY() && secondPoint.getY() == ThirdPoint.getZ()){
            cout<<"Ravnostranen"<<endl;
        }

        ///Ïðîâåðêà çà ðàâíîáåäðåí òðèúãúëíèê, êàòî ñðàâíÿâàìå ñòðàíèòå ìó.
        else if(firstPoint.getX() == secondPoint.getY()|| secondPoint.getY() == ThirdPoint.getZ() ||
                ThirdPoint.getZ() == firstPoint.getX())
        {
                    cout<<"Ravnobedren"<<endl;
        }

        else
        {
            cout<<"Raznostranen"<<endl;
        }


//        /Ïðîâåðêà çà íàé-ãîëÿìà ñòðàíà â òðèúãúëíèêà, çà óëåñíåíèå, çà ïðîâåðêà íà òèïà íà òðèúãúëíèêà.
//    double longest = ThirdPoint.getZ();
//    if(longest < firstPoint.getX()){
//        ThirdPoint.getZ() = longest;
//        longest = firstPoint.getX();
//        firstPoint.getX() = ThirdPoint.getZ();
//    }
//    if(longest < secondPoint.getY()){
//        ThirdPoint.getZ() = longest;
//        longest = secondPoint.getY();
//        secondPoint.getY() = ThirdPoint.getZ();
//    }

    ///Ïðîâåðêà çà ïðàâîúãúëåí òðèúãúëíèê ïî ôîðìóëàòà c^2 = a^2 + b^2.
    if(firstPoint.getX()*firstPoint.getX() + secondPoint.getY()*secondPoint.getY() == longest*longest)
    {
        cout<<"Pravougulen"<<endl;

    }
    ///Ïðîâåðêà çà îñòðîúãúëåí òðèúãúëíèê ïî ôîðìóëàòà a^2 + b^2 > c^2.
    else if(firstPoint.getX()*firstPoint.getX() + secondPoint.getY()*secondPoint.getY() >longest*longest)
    {
        cout <<"Ostrougulen"<<endl;
    }
    else
    {
        cout<<"Tupougulen"<<endl;
    }

}

///Ìåòîä çà èç÷èñëåíèå íà ëèöå íà òðèúãúëíèê ïî Õåðîíîâà ôîðìóëà.
double Triangle::areaTriangle(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    ///Íàìèðàìå ïîëóïåðèìåòúðà íà òðèúãúëíèêà, ÷ðåç ìåòîäà ïî-ãîðå.
    double p = poluPerimetar(firstPoint,secondPoint,ThirdPoint);

    ///õåðîíîâà ôîðìóëà.
    return sqrt(p*(p-firstPoint.getX())*(p-secondPoint.getY())*(p-ThirdPoint.getZ()));
}

///Ìåòîä çà íàìèðàíå íà ïåðèìåòúðà íà òðèúãúëíèê a+b+c.
double Triangle::perimetar(Point& firstPoint, Point& secondPoint, Point& ThirdPoint)
{
    return (firstPoint.getX() + secondPoint.getY() + ThirdPoint.getZ());
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
