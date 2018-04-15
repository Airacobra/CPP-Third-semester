#include "Complex.h"
#include "Register.h"
#include <iostream>


void ComplexNumber::Print() const
{
	std::cout<<real<<" + "<<imagine<<"i\n";
}
ComplexNumber::ComplexNumber()
{
	real = 0;
	imagine = 0;
}


ComplexNumber::ComplexNumber(const int real_part, const int imagine_part )
{
	std::cout<<"Creating number: "<<real_part<<" + "<<imagine_part<<"i\n";
	real = real_part;
	imagine = imagine_part;
}
ComplexNumber::ComplexNumber(const ComplexNumber &complex)
{
	real = complex.real;
	imagine = complex.imagine;
}
ComplexNumber& ComplexNumber::SetReal(const int number)
{
	this->real = number;
	return *this;
}
void ComplexNumber::SetImaginary(const int number)
{
	this->imagine = number;
}
void ComplexNumber::Save(Register &reg)
{
	reg.Set(real,imagine);
}
ComplexNumber ComplexNumber::Add(ComplexNumber number) const
{
	int real_part = number.GetReal() + real;
	int imagine_part = number.GetImagine() + imagine;
	ComplexNumber complex(real_part,imagine_part);
	
	return complex;
}

int ComplexNumber::GetReal()
{
	return real;
}
int ComplexNumber::GetImagine()
{
	return imagine;
}	

ComplexNumber::~ComplexNumber()
{
	std::cout<<"Deleting: "<<real<<" + "<<imagine<<"i\n";
}