#pragma once

#ifndef TVECTOR_H
#define TVECTOR_H

#include <memory>

class velem
{
public:
	int *usedBy;
	void *value;
};

class TVector
{
	public:
		TVector();
		void Erase(int pos);
		void InsertLast(const velem& elem);
		velem& operator[](const size_t idx);
		void Clear();
		bool Empty();
		size_t Length();
		~TVector();
	private:
		void resize(int newsize);
		velem *vals;
		int len;
		int rLen;
};

#endif
