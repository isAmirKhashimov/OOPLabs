#include "stdafx.h"
#include "queueNode.h"
#define sNode std::shared_ptr<QueueNode<T>>

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
