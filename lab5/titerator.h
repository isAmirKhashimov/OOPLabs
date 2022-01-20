#pragma once
//TITERATOR.H

#ifndef TITERATOR_H
#define TITERATOR_H

#include <memory>

template<class E> class TIterator
{
public:
	TIterator<E>(QueueNode<E> *node)
	{
		cur = node;
	}

	E* operator*()
	{
		return &(cur->Data);
	}

	E* operator->()
	{
		return &(cur->Data);
	}

	void operator++()
	{
		cur = cur->next.get();
	}

	TIterator<E> operator++(int)
	{
		TIterator iter(cur);
		++(*this);
		return iter;
	}

	bool operator==(TIterator const& i)
	{
		return cur == i.cur;
	}

	bool operator!=(TIterator const& i)
	{
		return cur != i.cur;
	}

private:
	QueueNode<E> *cur;
};

#endif
