//
//
//Tetrahedron:: Tetrahedron()
//{
//    this->p1 = Point();
//    this->p2 = Point();
//    this->p3 = Point();
//    this->p4 = Point();
//    Tetrahedron(p1, p2, p3, p4);
//}
//
//Tetrahedron:: Tetrahedron(Point& p1, Point& p2, Point& p3, Point& p4)
//{
//    this->p1 = p1;
//    this->p2 = p2;
//    this->p3 = p3;
//    this->p4 = p4;
//    try
//    {
//        if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4)
//            throw obj1;
//        else
//            Tetrahedron(p1, p2, p3, p4);
//    }catch(EqualPointException& p){
//        cerr << p.whatt() << endl;
//    }
//
//}
//
//Tetrahedron:: ~Tetrahedron(){}
//
//Tetrahedron:: Tetrahedron(const Tetrahedron& rhs)
//{
//    p1 = rhs.p1;
//    p2 = rhs.p2;
//    p3 = rhs.p3;
//    p4 = rhs.p4;
//}
//
//Tetrahedron& Tetrahedron:: operator=(const Tetrahedron& rhs)
//{
//    if(this != &rhs)
//    {
//          p1 = rhs.p1;
//          p2 = rhs.p2;
//          p3 = rhs.p3;
//          p4 = rhs.p4;
//    }
//    return *this;
//}
//
//bool Tetrahedron:: check_if_Correct(){
//    Triangle a(p1,p2,p3);
//    Triangle b(p1,p4,p3);
//    Triangle c(p2,p4,p3);
//    Triangle d(p1,p2,p4);
//    if(a.find_Area() == b.find_Area() && b.find_Area() == c.find_Area() && c.find_Area() == d.find_Area())
//        return true;
//     else
//        return false;
//}
//
//bool Tetrahedron:: check_if_Ortogonal()
//{
//    Segment a(p1, p2);
//    Segment b(p1, p3);
//    Segment c(p2, p3);
//    Segment d(p1, p4);
//    Segment e(p2, p4);
//    Segment f(p3, p4);
//
//    return (a*a + f*f == b*b + e*e == c*c + d*d);
//}
//
//float Tetrahedron:: get_Surface()
//{
//    Triangle a(p1,p2,p3);
//    Triangle b(p1,p4,p3);
//    Triangle c(p2,p4,p3);
//    Triangle d(p1,p2,p4);
//    float res = a.find_Area() + b.find_Area() + c.find_Area() + d.find_Area();
//    return res;
//}
//
//float Tetrahedron:: get_Volume()
//{
//    Vector a(p1, p2);
//    Vector b(p1, p3);
//    Vector c(p1, p4);
//    float temp = a.operator()(b,c);
//    return (temp/6);
//}
//
//
//#include "Tetrahedron.hpp"
