#include "ComplexNumber.h"
#include <iostream>

ComplexNumber::ComplexNumber(const double real, const double imaginary){
	_re = real;
	_im = imaginary;
}

ComplexNumber::ComplexNumber(const double real){
	_re = real;
	_im = 0;
}

void ComplexNumber::Print() const{
	if(_im != 0)
		std::cout<<_re<<" + "<<_im<<"i"<<std::endl;
	else std::cout<<_re<<std::endl;
}

double& ComplexNumber::Real() {
	return _re;
}

double& ComplexNumber::Imaginary(){
	return _im;
}

double ComplexNumber::Real() const{
	return _re;	
}

double ComplexNumber::Imaginary() const{
	return _im;
}

ComplexNumber::operator double() const {
	double length = this->_re * this->_re  + this->_im * this->_im;
	return length;
}

ComplexNumber& ComplexNumber::Add(double real){
	this->_re += real;
	return *this;
} 

ComplexNumber& ComplexNumber::Add(const ComplexNumber &first){
	this->_re += first._re;
	this->_im += first._im;
	return *this;
}