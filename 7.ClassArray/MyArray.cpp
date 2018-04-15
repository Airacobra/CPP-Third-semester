#include "MyArray.h"
#include <iostream>

MyArray::MyArray(int t_size):size(this->arraySize){
	intArray = new int[t_size];
	for(int i = 0; i < t_size; i++){
		intArray[i] = 0;
	}

	arraySize = t_size;
}

MyArray::MyArray(const MyArray &myArray):size(this->arraySize)
{

	intArray = new int [myArray.size];
	
	for (int i = 0; i < myArray.size; i++){
		intArray[i] = myArray.intArray[i];
	}
	
	arraySize = myArray.size;
}

int & MyArray::at(const int number) const{
	return intArray[number];
}

void  MyArray::print(){
	for(int i = 0; i < size; i++)
		std::cout<<"array["<<i<<"] = "<<intArray[i]<<std::endl;
}

void MyArray::resize(int newSize){
	int *oldIntArray = intArray;
	intArray = new int[newSize];
	int i;
	for(i = 0; i < size; i++) 
		intArray[i]=oldIntArray[i];
	for( ; i < newSize; i++)
		intArray[i]=0;
	arraySize=newSize;
	delete [] oldIntArray;
}

MyArray::~MyArray(){
	delete [] intArray;
}

