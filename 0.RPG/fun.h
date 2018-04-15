#pragma once

//Tektst powitalny, informuje o potrzebie wpisaniu imienia bohatera
void welcome();

//Funkcja ta zwraca imie postaci wpisane przez gracza
std::string getPlayerName(const unsigned int);

//Przydziela 20 poczatkowych punktow bohaterowi, oraz wypisuje statystyki
//(funkcja karze bohatera za zle wpisanie liczby przy rozdawaniu statystyk)
void createCharacter(const char[][20], int*, const std::string*);

//informuje gracza o regulach i nadchodzacej pierwszej walce
void Info();

//randomizuje napotkanego przeciwnika
void randomizeMonster(int*);

//oblicza liczbe zadanych obrazen w funkcji duel(ponizej)
int attackResult(int , int );

//awans postaci po ubiciu potwora, +1 do statystyk
void addSkillPoint(const char , int* , const std::string*);

//	Odpala algorytm walki miedzy bohaterem, a potworem
//	Wygra ten, kto obnizy poziom zycia rywala do 0
//	funkcja zwraca true albo false, co wskazuje na kontynuacje przygody lub jej brak
bool duel(const char [][20], int*, const std::string*, int*);

//dodaje statystyki pokonanego przeciwnika do konocowej tabeli (vectory zamiast realloca)
void addTrophyToVector(int*, std::vector< std::vector<int> > &);

//wypisuje statystyki bohatera tuz prze smiercia
void printCurrentCharacterStatistics(const char [][20], int*, const std::string*);

//wypisuje statystyki potwora, ktory pokonal bohatera
void printLastMonsterAttributes(const char [][20], int*, int);

//wypisuje tabele pokonaych potworow
void showTrophyCollection(const std::vector< std::vector<int> > &);