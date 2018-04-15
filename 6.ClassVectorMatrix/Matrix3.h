#pragma once 

class VectorTrans3D;

class Matrix3{
public:
	void Print();
	VectorTrans3D Times(const VectorTrans3D &vect);
	Matrix3 Times(const Matrix3 &matrix);
	void Set(const int row, const int column, const int value);
	int Get(const int row, const int column) const;
private:
	int Qmatrix[3][3];	
};

