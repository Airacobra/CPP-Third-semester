#include "Angle.h"
#include <iostream>
#include <cmath>

Angle::Angle(const double rad)
{
		if(rad > 2*M_PI)
	{

		double rad_change = rad;
		

		while(rad_change > 2 * M_PI ) rad_change -= 2*M_PI;
		angle = rad_change * 180 / M_PI;
	}
	else if( rad <  0)
	{
		double rad_change = rad;
		while(rad_change < 0) rad_change += 2*M_PI;
		angle = rad_change * 180 / M_PI;
	}
	else angle = rad * 180 / M_PI;
}

Angle::Angle (const Angle& first)
{
	angle = first.GetAngle();
}

double Angle::GetAngle() const
{
	return angle;
}

Angle Angle::fromRadians(const double rad)
{
	double deg = rad;
	if(rad < 0)
		{
			
			while(deg < 0) deg += 2*M_PI;
			
		}
	else if(rad > 2* M_PI)
	{
		
		while(deg > 2 * M_PI) deg -= 2*M_PI;

	}
	

	Angle first(deg);
	return first;
}

Angle Angle::fromDegrees(const double deg)
{
	double rad = deg;
	if(deg > 360)
	{
		while (rad > 360) rad -= 360;
	}
	else if(rad < 0)
	{
		while(rad < 0) rad += 360;
	}
	

	Angle first(rad * M_PI /180);
	return first;
}

Angle::operator double() const
{
	return angle;
}

Angle& Angle::add(double deg)
{
	this->angle += deg;
	if(angle > 360)
	{
		while(angle > 360) angle -= 360;
	}

	return *this;
}

double Angle::toDeg() const
{
	
	return angle;
}

double Angle::toRad() const
{
	
	return angle * M_PI / 180;
}

Angle Angle::distance(double first, double second)
{
	if(first<second) 
		{
			Angle third((first - second) * M_PI / 180);
			return third;
		}
	else 
		{
			Angle third((second - first) * M_PI / 180);
			return third;
		}
	
}
