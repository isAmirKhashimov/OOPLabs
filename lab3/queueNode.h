#pragma once
#ifndef QUEUE_NODE_H_INCLUDED
#define QUEUE_NODE_H_INCLUDED
#include "rectangle.h"
#include <memory>
#define sNode std::shared_ptr<QueueNode>

typedef Rectangle item;
class QueueNode
{
public:
	QueueNode(const item&);
	QueueNode();
	item Data;

	sNode next;
};

#endif