#ifndef FRACTION_ARRAY_H
#define FRACTION_ARRAY_H
#include <iostream>
#include "Fraction.h"

class FractionArray
{
	public:
		//tworzy tablice dynamicznie o zadanym rozmiarze
		FractionArray(const int rozmiar);
		//dopisuje do tablicy ulamke o zadanych wartosciach
		void AddFration(const int licznik, const int mianownik);
		//sumuje elementy w tablicy
		Fraction Sum();
		//wypisze tablice ulamkow
		void Print();
		//Destruktor - bedzie czyscil po operatorze new
		~FractionArray();
	private:
		Fraction **tablica;
		int ile;
};

#endif

