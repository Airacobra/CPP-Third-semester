#ifndef ARRAYH
#define ARRAYH

//struktura przechowująca informacje dotyczące tworzonej tablice(rozmiary kolumn, wierszy i wskaźnik na dynamicznie alokowaną tablicę)

typedef struct Array
{
	int *ColumnsSize;//tablica rozmiarów kolumny dla każdego rzędu
	int Rows;
	int **Tab;
	
}Array;


//dynamiczna alokacja struktury Array wysyłany jest wskaźnik przez referencję - tworzy tablicę o zadanej liczbie wierszy i kolumn
void CreateArray (Array *& firstArray, const int *columns, const int rows);

//wypełnia całą tablicę zadaną wartością
void FillWith(Array * firstArray, const int value);

//wypisuje tablicę na ekran
void Print (const Array & firstArray);  

//ustawia określony element tablicy na daną wartość, jeżeli wartość ta wychodzi poza zakres tablicy to wartość nie jest zmieniana i jest wyświetlana informacja index out of bonds
void SetElement(const int row, const int column, Array ** firstArray, const int value);

//wypisuje maksimum lokalne dla danego wiersza i globalne dla całej tablice
void  PrintMax (const Array * firstArray);  

//usuwa wszystkie dynamicznie zaalakowane elementy, aby uniknąć problemów związanych z wyciekami pamięci
void Clear (Array ** firstArray);

#endif

