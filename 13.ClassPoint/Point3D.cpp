#include "Point3D.h"


Point3D::Point3D(const int x, const int y, const int z)
{
	P_x = x;
	P_y = y;
	P_z = z;
}

Point3D::Point3D()
{
	P_x = 0;
	P_y = 0;
	P_z = 0;
}

bool Point3D::operator==(const Point3D& compare)
{
	if(P_x != compare.P_x) return false;
	if(P_y != compare.P_y) return false;
	if(P_z != compare.P_z) return false;
	return true;
}


std::ostream& operator<< (std::ostream& o, const Point3D& point)
{
  return o <<"("<<point.P_x<<", "<<point.P_y<<", "<<point.P_z<<")";
}