#pragma once
#include <iostream>
class Point3D
{
public:
	friend class PointArray;
	friend std::ostream& operator<< (std::ostream& o, const Point3D& point);
	explicit Point3D(const int x, const int y, const int z);
	bool operator==(const Point3D& compare);

private:
	Point3D();
	int P_x;
	int P_y;
	int P_z;

};

