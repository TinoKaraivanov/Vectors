#include "triangle.hpp"
#include "segment.hpp"

int main(){
    Point pt1 (1,7,1);
    Point pt2 (2,6,4);
    Point pt3 (3,2,5);
    Vector v1(pt1,pt3);
    Triangle tr(pt1,pt2,pt3);
    Line l1 (pt1, v1);
    Line l2 (pt1,pt3);
    Line l3 (pt1,pt2);
    Segment s1(pt1, v1, 1, 1);

    return 0;
}

