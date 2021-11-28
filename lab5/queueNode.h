#pragma once
#ifndef QUEUE_NODE_H_INCLUDED
#define QUEUE_NODE_H_INCLUDED
#include "rectangle.h"
#include <memory>

template<class T>
class QueueNode
{
public:
	QueueNode(const T&);
	QueueNode();
	T Data;
	std::shared_ptr<QueueNode<T>> next;
};

#endif