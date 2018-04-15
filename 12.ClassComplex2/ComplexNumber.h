#pragma once

//klasa pracujaca na liczbach zespolonych
class ComplexNumber{
public:
	//konstruktor tworzocy liczbe zespolona
	ComplexNumber(const double real, const double imaginary);
	//konstruktor tworzacy liczbe rzeczywista
	ComplexNumber(const double real);
	//funckja wypisujaca liczbe zespolona
	void Print() const;
	//przypisuje czesc rzeczywista
	double& Real();
	//przypisuje czesc urojona
	double& Imaginary();
	//zwraca czesc rzeczywista
	double Real() const;
	//zwraca czesc urojona
	double Imaginary() const;
	//funkcja dokonujaca konwersji na double
	operator double() const;
	//funckja ta dodaje zadana wartosc do liczby 
	//zespolonej, na rzecz ktorej zostala wywolana
	ComplexNumber& Add(double real); 
	//funckja ta dodaje zadana wartosc do liczby 
	//zespolonej, na rzecz ktorej zostala wywolana
	ComplexNumber& Add(const ComplexNumber &first); 

private:
	//do przechowywania liczby rzeczywistej
	double _re;
	//do przechowywania liczby urojunej
	double _im;
};