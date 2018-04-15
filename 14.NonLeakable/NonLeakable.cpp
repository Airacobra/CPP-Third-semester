#include "NonLeakable.h"
#include <cstdlib>

int NonLeakable::ID = 0;

NonLeakable::NonLeakable()
{
	std::cout<<"Constructing object "<<ID<<"\n";
	NL_id = ID;
	ID++;
}

void NonLeakable::Print() const
{
	std::cout<<"This is object with ID="<<NL_id<<"\n";
}

NonLeakable::~NonLeakable()
{
	std::cout<<"Destroying object "<<NL_id<<"\n";
}


void* NonLeakable::operator new(size_t size)
{
	void * ptr = malloc(size);
	return ptr;

}

void NonLeakable::operator delete(void* ptr)
{
	free(ptr);
}