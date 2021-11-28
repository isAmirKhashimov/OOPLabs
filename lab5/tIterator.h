#pragma once


#include "tQueue.h"

template <class T>
class TIterator
{
private:
	std::shared_ptr<QueueNode<T>> current;
public:
	TIterator<T>(std::shared_ptr<QueueNode<T>> node)
	{
		current = node;
	}
	T* operator*()
	{
		return &(current->Data);
	}
	T* operator->()
	{
		return &(current->Data);
	}
	TIterator<T>* operator++(int)
	{
		return new TIterator<T>(current->next);
	}
	bool operator==(TIterator const& another)
	{
		return current->next == another.current->next;
	}
	bool operator!=(TIterator const& another)
	{
		return current != another.current;
	}

};

