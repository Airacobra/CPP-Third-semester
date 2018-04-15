#pragma once

class Angle
{
public:
	Angle (const Angle& first);
	static Angle fromRadians(const double rad);
	static Angle fromDegrees(const double deg);
	operator double() const;
	Angle& add(double deg);
	double toDeg() const;
	double toRad() const;
	static Angle distance(double first, double second);
	double GetAngle() const;

private:
	//kat w stopniach!!
	Angle(const double rad);
	
	double angle;
};
