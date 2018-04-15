#include "Main.h"


void InitMatrix (Matrix *first,const int size)
{
	
	
	*first = new Fraction **[size];
	for(int i=0; i<size; i++)
	{
		(*first)[i] = new Fraction *[size];
	}
	
}

void SetFraction(Fraction *first, const int numenator, const int denomiator)
{
	first->up = numenator;
	first->down = denomiator;
}

void Print(Fraction *first, bool check)
{
	int times = first->up/first->down;
	if(times == 0)
	{
		std::cout<<first->up<<"/"<<first->down;
	}
	else if(first->up % first->down == 0)
	{
		std::cout<<times;
	}
	else
	{
		std::cout<<times<<" "<<first->up%first->down<<"/"<<first->down;
	}
	if(check)
	{
		delete first;
	}

}

void FillRowByColumnPlus1 (Matrix *first, const int size)
{
	
	for(int rows=0;rows<size;rows++)
	{
		for(int columns=0;columns<size;columns++)
		{
			(*first)[rows][columns] = new Fraction;
			SetFraction((*first)[rows][columns],rows+1,columns+1);
		}
	}
	


}

void FillRowByColumnPlus5 (Matrix *first, const int size)
{
	

	for(int rows=0;rows<size;rows++)
	{
		for(int columns=0;columns<size;columns++)
		{
			(*first)[rows][columns] = new Fraction;
			SetFraction((*first)[rows][columns],rows+1,columns+5);
		}
	}
}

void PrintMatrix(Matrix first, const int size)
{
	for(int rows=0; rows<size; rows++)
	{
		for(int columns=0; columns<size; columns++)
		{
			Print(first[rows][columns],false);
			std::cout<<"\t";
		}
		std::cout<<"\n";
	}
}
void Sum (Matrix first,Matrix second,const int size,Matrix *sumFirstSecond)
{	
	InitMatrix(sumFirstSecond, size);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			int numerator = first[i][j]->up * second[i][j]->down + first[i][j]->down * second[i][j]->up;
			int denominator = first[i][j]->down * second[i][j]->down;
			(*sumFirstSecond)[i][j] = new Fraction;
			SetFraction((*sumFirstSecond)[i][j], numerator, denominator);
		}
	}

}

void Clear (Matrix first,const int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0; j<size;j++)
		{
			delete first[i][j];
		}
	}
	for(int i=0; i<size;i++)
	{
		delete [] first[i];
	}
	delete [] first;

}