#pragma once
//deklaracja wyprzedzajaca
class NonLeakable;

//klasa sprytny wskaznik
class NonLeakablePtr
{
public:
	//konstruktor ustawiajacy wskaznik na 0
	NonLeakablePtr();
	//kosntruktor kopiujacy, wskaznik argumentu
	//ustawia na 0
	NonLeakablePtr(NonLeakablePtr& pointer);
	//desktruktor zwalniajacy zajete miejsce
	~NonLeakablePtr();
	//przyznaje miejsce w pamieci na obiekt
	//klasy NonLeakable
	void MakeNewObject();
	//wypisuje adres wskazywanego obiektu 
	void Print() const;
	//przeciazenie, ktore zwraca wskaznik na obiekt klasy
	//NonLeakable
	NonLeakable* operator->() const;
	//przeciazenie, zwraca obiekt klasy NonLeakable
	NonLeakable& operator*() const;
	//przeciazenie, ktore zwraca wskaznik na obiekt klasy
	//NonLeakable
	NonLeakable* operator&() const;
	//przeciazenie przypisania, ktore przypisuje adres obiektu do
	//wskaznika, wskazywanego przez argument oraz zeruje wskaznik argumentu
	NonLeakablePtr& operator=(NonLeakablePtr& pointer);

private:
	//wskaznik na obiekt klasy NonLeakable
	NonLeakable* NLP_pointer;
};