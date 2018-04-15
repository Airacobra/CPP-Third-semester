#include "MyArray.h"

#include <iostream>

MyArray::MyArray(int*& tab, const int length) : size(_size), _size(length)
{
	_array = tab;
}
MyArray::MyArray(MyArray& tempArray) : size(_size), _size(tempArray.size), _id(tempArray._id)
{
	_array = new int[_size];
	for(int index=0; index < _size; index++)
		_array[index] = tempArray._array[index];
}
MyArray::~MyArray()
{
	delete[] _array;
}
int& MyArray::id() 
{
	return _id;
}
int MyArray::id() const
{
	return _id;
}
int& MyArray::at(int index) const
{
	return _array[index];
}
void MyArray::print()
{
	std::cout << "Content of array with ID=" << _id << std::endl;
	for(int index=0; index<_size; index++)
	{
		std::cout<< "array[" << index << "] = " << _array[index] << std::endl;
	}
}
void MyArray::resize(const int newLength)
{
	int oldSize = _size;
	int* tempArray = new int[newLength];
	int index =0;
	for(; index < oldSize; index++)
	{
		tempArray[index] = _array[index];
	}
	for(; index<newLength; index++)
	{
		tempArray[index] = 0;
	}
	delete[] _array;
	
	_array = tempArray;
	_size = newLength;
}