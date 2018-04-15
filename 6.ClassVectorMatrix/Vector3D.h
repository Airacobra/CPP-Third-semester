#pragma once 

class VectorTrans3D;

class Vector3D{
public:
	Vector3D(const int x, const int y, const int z);
	void Print();
	int Times(const VectorTrans3D &vect);
	int Get(const int x) const;
private:
	int Qvector[3];
};


