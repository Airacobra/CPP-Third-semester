#include "FractionArray.h"

FractionArray::FractionArray(const int rozmiar){
	tablica = new Fraction *[rozmiar +1];
    ile = 0;
}

void FractionArray::AddFration(const int x, const int y){
	tablica[ile] = new Fraction(x,y);
	ile++;
}

Fraction FractionArray::Sum(){
	tablica[ile] = new Fraction(1,1);

	
	int numerator = tablica[0]->licznik;
	int denominatr = tablica[0]->mianownik;

	for(int rzad = 1; rzad < ile; rzad++)
	{
		numerator = numerator * tablica[rzad]->mianownik + denominatr * tablica[rzad]->licznik;
		denominatr = denominatr * tablica[rzad]->mianownik;
	}

	tablica[ile]->licznik = numerator;
	tablica[ile]->mianownik = denominatr;

	return *tablica[ile];

} 

void FractionArray::Print(){
	for(int rzad = 0; rzad < ile; rzad ++){
		std::cout<<rzad<<": ";
		tablica[rzad]->Print();
	}
}

FractionArray::~FractionArray(){
	for(int rzad = 0; rzad<=ile; rzad++) 
		delete tablica[rzad];

	delete [] tablica;
	ile = 0;

}
/*

Fraction FractionArray::Sum()
{
	array[how_many] = new Fraction(1,1);
	
	int numerator = array[0]->up;
	int denominatr = array[0]->down;

	for(int row = 1; row < how_many; row++)
	{
		numerator = numerator * array[row]->down + denominatr * array[row]->up;
		denominatr = denominatr * array[row]->down;
	}

	array[how_many]->up = numerator;
	array[how_many]->down = denominatr;

	return *array[how_many];
}

*/