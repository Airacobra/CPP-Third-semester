#include "Vector3D.h"
#include <iostream>
#include "VectorTrans3D.h"

Vector3D::Vector3D(const int x, const int y, const int z){
	Qvector[0]=x;
	Qvector[1]=y;
	Qvector[2]=z;
}

void Vector3D::Print(){
	std::cout<<"(";
	for (int row = 0; row < 3; row++)
	{
		if(row < 2) std::cout<<Qvector[row]<<", ";
		else std::cout<<Qvector[row];
	}
	std::cout<<")\n";
}

int Vector3D::Times(const VectorTrans3D &vect){
	int result = 0;

	for(int row = 0; row < 3; row++)
		result +=Qvector[row] * vect.Get(row);

	return result;
}

int Vector3D::Get(const int x) const{
	return Qvector[x];
}

