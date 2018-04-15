#include "NonLeakablePtr.h"
#include "NonLeakable.h"

NonLeakablePtr::NonLeakablePtr()
{
	NLP_pointer = 0;
}

NonLeakablePtr::NonLeakablePtr(NonLeakablePtr& pointer)
{
	NLP_pointer = pointer.NLP_pointer;
	pointer.NLP_pointer = 0;
}

NonLeakablePtr::~NonLeakablePtr()
{
	if(NLP_pointer)
	{
	delete NLP_pointer;
	NLP_pointer = 0;
	}
}

void NonLeakablePtr::MakeNewObject()
{
	if(NLP_pointer) delete NLP_pointer;
	NLP_pointer = new NonLeakable;
}

void NonLeakablePtr::Print() const
{
	if(NLP_pointer) std::cout<<"Object pointing to "<<NLP_pointer<<"\n";
	else std::cout<<"Object pointing to nothing\n";
}

NonLeakable* NonLeakablePtr::operator->() const
{
	return NLP_pointer;
}

NonLeakable& NonLeakablePtr::operator*() const
{
	return *NLP_pointer;
}

NonLeakable* NonLeakablePtr::operator&() const
{
	return NLP_pointer;
}

NonLeakablePtr& NonLeakablePtr::operator=(NonLeakablePtr& pointer)
{
	if(NLP_pointer == pointer.NLP_pointer) return *this;
	NLP_pointer = pointer.NLP_pointer;
	pointer.NLP_pointer = 0;
	return *this;
}