#include "Point3D.h"
#include "PointArray.h"



PointArray::PointArray(const int how_many, const Point3D& point)
{
	Ar_size = how_many;
	Ar_array = new Point3D[how_many];
	for(int row = 0; row < how_many; row++)
	{
		Ar_array[row] = point;
	}
	
}

PointArray::PointArray(const PointArray &second)
{
	Ar_size = second.Ar_size;
	Ar_array = new Point3D[Ar_size];
	for(int row = 0; row < Ar_size; row++)
	{
		Ar_array[row] = second.Ar_array[row];
	}
}

void PointArray::Print() const
{
	for(int row = 0; row < Ar_size; row++)
	{
		std::cout<<Ar_array[row]<<"\n";
	}
}


PointArray::~PointArray()
{
	Ar_size = 0;
	delete [] Ar_array;
}

Point3D& PointArray::operator[](int which) const
{
	return Ar_array[which];
}

bool PointArray::operator==(const PointArray& array)
{
	if(Ar_size != array.GetSize()) return false;
	for(int row = 0; row < Ar_size; row++)
	{
		if(!(Ar_array[row] == array.Ar_array[row])) return false;
	}
	return true;
}


int PointArray::GetSize() const
{
	return Ar_size;
}

Point3D PointArray::GetRow(const int row) const
{
	return Ar_array[row];
}

PointArray& PointArray::operator= (const PointArray& array)
{
	if(this == &array) return *this;
	delete [] Ar_array;
	Ar_size = array.Ar_size;
	Ar_array = new Point3D[Ar_size];
	for(int row = 0; row < Ar_size; row++)
	{
		Ar_array[row] = array.Ar_array[row];
	}
	return *this;
}