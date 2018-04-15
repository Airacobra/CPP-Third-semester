#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class Fraction{
	//zaprzyjazna klase przechowujaca tablice ulamkow
	friend class FractionArray;
public:
		//kostruktor przyjmujacy licznik i mianownik ulamka	
		Fraction(const int licznik, const int mianownik);

		//wypisuje zawartosc ulamka
		void Print();

		//dodaje wartosci ulamkow
		Fraction Add(Fraction ulamek);

private:
	 // dwie zmienne private do przechowywania wartoci ulamka
	 int licznik;
	 int mianownik;	
};


#endif