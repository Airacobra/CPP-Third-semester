#include <iostream>
#include "VectorTrans3D.h"
#include "Vector3D.h"
#include "Matrix3.h"

VectorTrans3D::VectorTrans3D(const int x, const int y, const int z){
	Qvector[0]=x;
	Qvector[1]=y;
	Qvector[2]=z;
}

void VectorTrans3D::Print(){
	for(int row = 0; row<3; row++)
		std::cout<<Qvector[row]<<"\n";
}

Matrix3 VectorTrans3D::Times(const Vector3D &vect){
	Matrix3 result;
	for(int row = 0; row < 3; row++){
		for(int column = 0; column < 3; column++)
			result.Set(row,column,Qvector[row] * vect.Get(column));
	}
	return result;
}

int VectorTrans3D::Get(const int x) const {
	return Qvector[x];
}

void VectorTrans3D::Set(const int row, const int value){
	Qvector[row] = value;
}
