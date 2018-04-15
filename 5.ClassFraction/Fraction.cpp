#include "Fraction.h"

Fraction::Fraction(const int x, const int y){
	licznik = x;
	mianownik = y;
}

void Fraction::Print(){
	int calkowita = licznik/mianownik;
	if(calkowita == 0) std::cout<<licznik<<"/"<<mianownik;
	else std::cout<< calkowita<<" "<<licznik%mianownik<<"/"<<mianownik;
	std::cout<<"\n";
}

Fraction Fraction::Add(Fraction second){
	second.licznik = second.licznik * mianownik + licznik *second.mianownik;
	second.mianownik = mianownik * second.mianownik;
	return second;
}









