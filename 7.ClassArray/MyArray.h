#pragma once

class MyArray{
public:
	const int &size;

	MyArray(int size);
	MyArray(const MyArray &myArray);

	int & at(const int number) const;
	void print();
	void resize(int newSize);
	~MyArray();

private:
	int *intArray;
	int arraySize;


};
