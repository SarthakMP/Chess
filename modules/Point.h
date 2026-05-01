#pragma once
#include<Behavior.h>
#include<ostream>

class Point
{
    
public:
    int x, y;
    friend std::ostream& operator<<(std::ostream& os,const Point& p);
    Point() :x(0), y(0) {}

    Point(int i1, int i2) : x(i1), y(i2) {}

    explicit Point(Vector2& v) : x(static_cast<int>(v.x)), y(static_cast<int>(v.y)) {}
    

};

inline std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.x << "," << p.y << "\n";
    return os;
}
