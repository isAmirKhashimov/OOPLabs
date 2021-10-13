#include "queueNode.h"

QueueNode::QueueNode(item& value)
{
	prev = NULL;
	next = NULL;
	Data = &value;
}

QueueNode::QueueNode()
{
	prev = NULL;
	next = NULL;
	Data = NULL;
}
