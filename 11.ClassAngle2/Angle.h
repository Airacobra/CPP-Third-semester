#pragma once

class Angle{
public:
	explicit Angle(const double rad);
	double rad() const;
	double deg() const;
	double & deg();
	static Angle distance(double first, double second);
	operator double() const;

private:	
	double deg_angle;
};
