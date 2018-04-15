#include <iostream>
#include "Main.h"

float * InicjalizujCiagGeometryczny (const rozmiarCiagu rozmiar, const float iloraz){
	float *tab;
	tab = new float[rozmiar];

	tab[0]=1;
	for(int index=1; index<rozmiar; index++)
		tab[index]=tab[index-1]*iloraz;
	return tab;
}

void Wypisz(float* geometryczny, const int rozmiar){
	std::cout<<"(";
	for(int index=0; index<rozmiar; index++){
		std::cout<<*(geometryczny+index);

		if(index!=rozmiar-1){
			std::cout<<" ";
		}
	}
	std::cout<<")\n";
}

float Suma(float* geometryczny, const int rozmiar){
	float wynik;
	for(int index=0; index<rozmiar; index++){
		wynik+=*(geometryczny+index);
	}
	return wynik;
}


float Iloczyn(float *geometryczny, const int rozmiar){
	float wynik;
	for(int index=0; index<rozmiar; index++){
		wynik*= *(geometryczny+index);
	}
	return wynik;
}


float Max(float *geometryczny, const int rozmiar){
	float maksymalny = *geometryczny;
	for(int index=1; index<rozmiar; index++){
		if(*(geometryczny+index)>maksymalny){
			maksymalny = *(geometryczny+index);
		}
	}
	return maksymalny;
}

float Min(float *geometryczny, const int rozmiar){
	float minimalny = *geometryczny;
	for(int index=1; index<rozmiar; index++){
		if(*(geometryczny+index)<minimalny){
			minimalny = *(geometryczny+index);
		}
	}
	return minimalny;
}


void WykonajIWypisz(operacja funkcja, float* geometryczny, const int rozmiar){
	std::cout<<"SUMA: "<<Suma(geometryczny,rozmiar)<<"\n";
	std::cout<<"ILOCZYN: "<<Iloczyn(geometryczny,rozmiar)<<"\n";
	std::cout<<"MAX: "<<Max(geometryczny,rozmiar)<<"\n";
	std::cout<<"MIN: "<<Min(geometryczny,rozmiar)<<"\n";
}