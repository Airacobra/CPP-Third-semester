#pragma once

//klasa opisujaca tablice
class MyArray
{
public:
	//konstruktor okreslajacy rozmiar i przypisujacy tablice
	MyArray(int*& tab, const int length);
	//kostruktor kopiujacy
	MyArray(MyArray& tempArray);
	//dekonstruktor, zwalnia pamiec
	~MyArray();
	//zwraca ID tablicy (przez referencje)
	int& id();
	//zwraca ID tablciy
	int id() const;
	//zwraca referencje na element w tablicy
	int& at(int index) const;
	//funckja wypisujaca tablica
	void print();
	//zmienia rozmiar tablicy
	void resize(const int newLength);


	const int& size;

private:
	int _size;
	int* _array;
	int _id;
};