#pragma once

typedef int rozmiarCiagu;

typedef float* ciag;

typedef float (*operacja)(float *, const int);

//Inicjalizuje ciag geometryczny o zadanym rozmiarze ciagu i ilorazie q
float * InicjalizujCiagGeometryczny (const rozmiarCiagu rozmiar, const float iloraz);

//wypisuje kolejne elementy ciagu geometrycznego
void Wypisz(float* gemotryczny, const int rozmiar);

//Wypisuje sume ciagu geometrycznego
float Suma(float* geometryczny, const int rozmiar);

//Wypisuje iloczny ciagu geometrycznego
float Iloczyn(float *geometryczny, const int rozmiar);

//Wyznacz max element z ciagu
float Max(float*geometryczny, const int rozmiar);

//Wyznacz min element z ciagu
float Min(float *geometryczny, const int rozmiar);

//Wykonuje zadana operacje (suma, iloczyn, max, min) oraz wypisuje wynik
//dla zadanego ciagu geometrycznego z podanym rozmiarem
void WykonajIWypisz(operacja funkcja, float* geometryczny, const int rozmiar);