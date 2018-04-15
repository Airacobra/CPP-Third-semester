#ifndef	MAIN_H
#define MAIN_H
#include <iostream>
#include <cstdlib>
typedef struct Fraction
{
	int up;
	int down;

}Fraction;

typedef Fraction*** Matrix;

void InitMatrix (Matrix *first,const int size);
void SetFraction(Fraction *first, const int numenator, const int denomiator);
void Print(Fraction *first, bool check=true);
void FillRowByColumnPlus1 (Matrix *first, const int size);
void FillRowByColumnPlus5 (Matrix *first, const int size);
void PrintMatrix(Matrix first, const int size);
void Sum (Matrix first,Matrix second,const int size,Matrix *sumFirstSecond);
void Clear (Matrix first,const int size);

#endif