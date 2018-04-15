#include "Complex.h"
#include "Register.h"
#include <iostream>

Register* Register::head = 0;
bool Register::check = false;

void Register::Print()
{
	if(check)
	{
	std::cout<<"Register stores number: "<<real<<" + "<<imagine<<"i\n";
	}
	else std::cout<<"Register is empty\n";
}
void Register::Write(ComplexNumber &number)
{
	check = true;
	real = number.GetReal();
	imagine = number.GetImagine();

}
ComplexNumber Register::Read()
{
	ComplexNumber complex;
	complex.SetReal(real).SetImaginary(imagine);
	return complex;
	
}
Register::~Register()
{
	delete head;
}

void Register::Set(const int real_part, const int imagine_part)
{
	real = real_part;
	imagine = imagine_part;
}