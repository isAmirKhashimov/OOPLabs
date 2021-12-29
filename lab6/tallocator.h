#pragma once
#ifndef TALLOCATOR_H
#define TALLOCATOR_H

#include "tvector.h"

class TAllocator
{
public:
	TAllocator(int elmSize, int bunchSize);
	void* Allocate();
	void Deallocate(void* ptr);
	~TAllocator();

private:
	int elemSize;
	int bunchSize;
	TVector *allocated;
	TVector *used;
};

#endif