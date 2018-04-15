#include <iostream>
#include "Array.h"

void CreateArray (Array *& firstArray, const int *columns, const int rows)
{
	firstArray = new Array;
	firstArray->ColumnsSize = new int [rows];
	
	for(int i =0; i < rows ; i++)
		firstArray->ColumnsSize[i] = columns[i];


	firstArray->Rows = rows;


	firstArray->Tab = new int*[rows];

	for(int i =0 ; i < rows ; i++)
		firstArray->Tab[i] = new int[columns[i]];

}

void FillWith(Array * firstArray, const int value)
{

	
	for(int i = 0; i < firstArray->Rows ; i++)
		for(int j = 0; j < firstArray->ColumnsSize[i] ; j++)
			firstArray->Tab[i][j] = value;

}

void Print (const Array & firstArray)
{
	for(int i = 0; i < firstArray.Rows ; i++)
	{
		for(int j = 0; j < firstArray.ColumnsSize[i] ; j++)
		{
			std::cout<<firstArray.Tab[i][j];

			if(j!=firstArray.ColumnsSize[i] - 1)
				std::cout<<" ";
		}

		std::cout<<std::endl;
	}
	
}

void SetElement(const int row, const int column, Array ** firstArray, const int value)
{
	if(!(row>=(*firstArray)->Rows) && !(column>=(*firstArray)->ColumnsSize[row]))
		(*firstArray)->Tab[row][column] = value;
	else
		std::cout<<"Index out of bounds"<<std::endl;
}

void PrintMax(const Array * firstArray)
{

	std::cout<<std::endl<<"maximum"<<std::endl;


	int globalmax = firstArray->Tab[0][0];

	for(int i = 0; i < firstArray->Rows ; i++)
		{
			int localmax = firstArray->Tab[i][0];
			for(int j = 0; j < firstArray->ColumnsSize[i] ; j++)
			{
				if(firstArray->Tab[i][j] > localmax)
				{
					localmax = 	firstArray->Tab[i][j];
				}

				if(localmax > globalmax)
					globalmax = localmax;

			}
		std::cout<<"max "<<i<<": "<<localmax<<std::endl;

	}

	std::cout<<"global max: "<<globalmax<<std::endl;
}

void Clear (Array ** firstArray)
{
	for(int i =0 ; i < (*firstArray)->Rows ; i++)
		delete [] (*firstArray)->Tab[i];


	delete [] (*firstArray)->Tab;

	delete [] (*firstArray)->ColumnsSize;

	delete *firstArray;

}

