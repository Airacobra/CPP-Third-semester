#include <iostream>
#include "Matrix3.h"
#include "VectorTrans3D.h"

void Matrix3::Print(){
	for(int row = 0; row < 3; row++){
		std::cout<<"(";
		for(int column = 0; column < 3; column++){
			if(column <2 ) std::cout<<Qmatrix[row][column]<<", ";
			else std::cout<<Qmatrix[row][column];
		}
		std::cout<<")\n";
	}
}

VectorTrans3D Matrix3::Times(const VectorTrans3D &vect){
	VectorTrans3D result(1,1,1);
	for(int row = 0; row < 3; row++){
		int x = 0;
		for(int column = 0; column < 3; column++){
			x += Qmatrix[row][column] * vect.Get(column);
		}
		result.Set(row,x);
	}
	return result;
}

Matrix3 Matrix3::Times(const Matrix3 &matrix){
	Matrix3 result;
	for(int row = 0; row < 3; row++){
		for(int column = 0; column < 3; column++){
			result.Set(row, column, 0);
		}
	}

	for(int row = 0; row < 3; row++){
		for(int column = 0; column < 3; column++){
			for(int k = 0; k < 3; k++){
				int x = result.Get(row, column) + matrix.Get(row,k) * Qmatrix[k][column];
				result.Set(row, column, x);
			}
		}
	}
	return result;
}

void Matrix3::Set(const int row, const int column, const int value){
	Qmatrix[row][column] = value;
}

int Matrix3::Get(const int row, const int column) const {
	return Qmatrix[row][column];
}

