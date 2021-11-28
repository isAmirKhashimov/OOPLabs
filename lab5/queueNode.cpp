#include "queueNode.h"

template<class T>
QueueNode<T>::QueueNode(const T& value)
{
	next = NULL;
	Data = value;
}

template<class T>
QueueNode<T>::QueueNode()
{
	next = NULL;
}


