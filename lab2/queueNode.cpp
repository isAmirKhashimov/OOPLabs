#include "queueNode.h"

QueueNode::QueueNode(const item& value)
{
	next = NULL;
	Data = value;
}

QueueNode::QueueNode()
{
	next = NULL;
}
