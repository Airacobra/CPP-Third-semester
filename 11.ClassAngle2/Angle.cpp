#include "Angle.h"
#include <iostream>
#include <cmath>

Angle::Angle(const double rad){
	if(rad > 2 * M_PI){
		double rad_change = rad;

		while(rad_change > 2 * M_PI) rad_change -= 2*M_PI;
		deg_angle = rad_change * 180/ M_PI;
	}

	else if(rad < 0){
		double rad_change = rad;

		while(rad_change < 0) rad_change += 2*M_PI;
		deg_angle = rad_change * 180 / M_PI;
	}
	else deg_angle = rad * 180 / M_PI;
}

double Angle::rad() const {
	return deg_angle * M_PI / 180;
}

double Angle::deg() const {
	return deg_angle;
}

double & Angle::deg(){
	return deg_angle;
}

Angle Angle::distance(double first, double second){
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

Angle::operator double() const {
	return deg_angle;
}
