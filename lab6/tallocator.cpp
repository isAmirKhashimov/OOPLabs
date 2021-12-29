#include "stdafx.h"
#include "tallocator.h"

TAllocator::TAllocator(int elmSize, int bnchSize)
{
	elemSize = elmSize;
	bunchSize = bnchSize;
	allocated = new TVector();
	used = new TVector();
}

void* TAllocator::Allocate()
{
	if (allocated->Empty())
	{
		char *newBlock = (char*)malloc(sizeof(int)+elemSize*bunchSize);
		*(int*)(newBlock) = 0;
		for (int i = 0; i < bunchSize; i++)
		{
			allocated->InsertLast(velem { (int*)newBlock, (void*)(newBlock + sizeof(int) + i * elemSize) });
		}
	}
	int lastIdx = allocated->Length() - 1;
	void *block = ((*allocated)[lastIdx]).value;
	(*((*allocated)[lastIdx].usedBy))++;
	used->InsertLast((*allocated)[lastIdx]);
	allocated->Erase(lastIdx);
	return block;
}

void TAllocator::Deallocate(void* ptr)
{
	int fid = -1;
	for (int i = 0; i < used->Length(); i++)
	{
		if (((*used)[i]).value == ptr)
		{
			fid = i;
			break;
		}
	}
	(*((*used)[fid].usedBy))--;
	allocated->InsertLast((*used)[fid]);
	int *block = ((*used)[fid]).usedBy;
	if (*block == 0)
	{
		for (int i = allocated->Length()-1; i >= 0 ; i--)
		{
			if ((*allocated)[i].usedBy == block)
			{
				allocated->Erase(i);
			}
		}
		free(block);
	}
	used->Erase(fid);
}

TAllocator::~TAllocator()
{
	delete allocated;
	delete used;
}
