#pragma once
#ifndef QUEUE_NODE_H_INCLUDED
#define QUEUE_NODE_H_INCLUDED
#include "rectangle.h"

typedef Rectangle item;
class QueueNode
{
public:
	QueueNode(item&);
	QueueNode();
	item* Data;

	QueueNode* prev;
	QueueNode* next;

};

#endif