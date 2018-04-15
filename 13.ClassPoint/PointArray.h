#pragma once

class Point3D;

class PointArray
{
public:
	PointArray(const int how_many, const Point3D& point);
	PointArray(const PointArray &second);
	void Print() const;
	Point3D& operator[](int which) const;
	bool operator==(const PointArray& array);
	PointArray& operator= (const PointArray& array);
	int GetSize() const;
	Point3D GetRow(const int row) const;

	~PointArray();

private:
	Point3D *Ar_array;
	int Ar_size;

};