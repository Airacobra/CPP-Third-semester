#pragma once
#include <iostream>

//klasa przechowujaca nr tworzonego obiektu
//i zmiennej statycznej mowiacej o ilosci
//stworzonych obiektow
class NonLeakable
{
public:
	//zaprzyjazniona klasa, ktora trzyma 
	//sprytny wskaznik na obiekt tej klasy
	friend class NonLeakablePtr;

	//konstruktor domyslny glosny
	NonLeakable();
	//wypsiwanie numer obiektu
	void Print() const;
	//kdestruktor glosny
	~NonLeakable();



private:
	//przeciazenie oepratora new, tworzane miejsce
	//na nowy obiekt klasy
	static void* operator new(size_t size);
	//usuwa przydzielone miejsce z przecianego 
	//oepratora new
	static void operator delete(void* ptr);
	//statyczny numer mowiacy o ilosci utworzonych obiektow
	static int ID;
	//nr ID konkretnego obiektu
	int NL_id;

};