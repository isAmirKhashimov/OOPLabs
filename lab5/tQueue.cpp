#include "tQueue.h"
#include <string>

template<class T>
TQueue<T>::TQueue()
{
	size = 0;
	head = QueueNode<T>();
	last = &head;
}

template<class T>
TQueue<T>::TQueue(const TQueue<T>& other): TQueue()
{
	std::shared_ptr<QueueNode<T>> current = other.head.next;
	while (current != NULL)
	{
		this->Push(current->Data);
		current = current->next;
	}
}

template<class T>
void TQueue<T>::Push(const T& value)
{
	last->next = std::shared_ptr<QueueNode<T>>(new QueueNode<T>(value));
	last = last->next.get();
	size++;
}

template<class T>
void TQueue<T>::Pop()
{
	if (size == 0)
	{
		throw;
	}
	auto nextNode = head.next->next;
	head.next = NULL;
	head.next = nextNode;
	size--;
}

template<class T>
const T& TQueue<T>::Top()
{
	if (size == 0)
	{
		throw;
	}
	return head.next->Data;
}

template<class T>
bool TQueue<T>::Empty()
{
	return size == 0;
}

template<class T>
size_t TQueue<T>::Length()
{
	return size;
}

template<class T>
void TQueue<T>::Print(std::ostream& os)
{
	std::shared_ptr<QueueNode<T>> current = head.next;
	std::string output = "";
	while (current != NULL)
	{
		output = std::to_string(current->Data.Area()) + " " + output;
		current = current->next;
	}
	output = "=> " + output + "=>";
	os << output << std::endl;
}

template<class T>
void TQueue<T>::Clear()
{
	while (size != 0)
	{
		Pop();
	}
}

template<class T>
TIterator<T> TQueue<T>::begin()
{
	return TIterator<T>(std::shared_ptr<QueueNode<T>>(&head));
}

template<class T>
TIterator<T> TQueue<T>::end()
{
	return TIterator<T>(std::shared_ptr<QueueNode<T>>(last));
}

template<class T>
TQueue<T>::~TQueue()
{
	Clear();
}

template<class T>
std::ostream& operator<<(std::ostream& os, TQueue<T>& queue)
{
	queue.Print(os);
	return os;
}

