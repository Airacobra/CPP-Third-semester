#pragma once
#include <iostream>

class ComplexNumber;

class Register
{
public:
	static void Clear()
	{
		
		check = false;

	}
	static Register& Retrieve()
	{
		if(!check)
		{
		std::cout<<"Creating register\n";
		head = new Register;
		}
		return *head;
		

	}
	void Print();
	void Write(ComplexNumber &number);
	ComplexNumber Read();
	~Register();
	void Set(const int real_part, const int imagine_part) ;

private:
	static bool check;
	int real; 
	int imagine;
	static Register *head;
	
};