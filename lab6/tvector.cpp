#include "stdafx.h"
#include "tvector.h"
#include <cstring>

TVector::TVector()
{
	vals = NULL;
	len = 0;
	rLen = 0;
}

void TVector::Erase(int pos)
{
	if (len == 1)
	{
		Clear();
		return;
	}
	for (int i = pos; i<len - 1; i++)
		vals[i] = vals[i + 1];
	len--;
	if (len == rLen >> 1)
	{
		resize(len);
		rLen = len;
	}
}

void TVector::InsertLast(const velem& elem)
{
	if (rLen)
	{
		if (len >= rLen)
		{
			rLen <<= 1;
			resize(rLen);
		}
	}
	else
	{
		rLen = 1;
		resize(rLen);
	}
	vals[len] = elem;
	len++;
}

velem& TVector::operator[](const size_t idx)
{
	return vals[idx];
}

bool TVector::Empty()
{
	return len == 0;
}

size_t TVector::Length()
{
	return len;
}

void TVector::Clear()
{
	if (!Empty())
	{
		delete[] vals;
		vals = NULL;
		len = 0;
		rLen = 0;
	}
}

void TVector::resize(int newsize)
{
	velem *newVals = new velem[newsize];
	for (int i = 0; i<len; i++)
		newVals[i] = vals[i];
	delete[] vals;
	vals = newVals;
}

TVector::~TVector()
{
	Clear();
}
