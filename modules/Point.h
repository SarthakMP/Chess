#pragma once
#include<ostream>
class Point2D
{
public:
	float x, y;

	Point2D(int i1,int i2) {
		x = int(i1);
		y = int(i2);
	}

	Point2D(float i1, float i2) {
		x = i1;
		y = i2;
	}


};

std::ostream& operator <<(std::ostream& os, Point2D p) {
	return os << "(" << p.x << "," << p.y << ")"<<"\n";
}