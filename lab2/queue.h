#pragma once
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "queueNode.h"

class Queue
{
private:
	size_t _size;

public:
	Queue();
	Queue(const Queue&);
	~Queue();
	size_t size();
	bool empty();
	item* top();
	void push(item&);
	item* pop();

	friend std::ostream& operator<<(std::ostream& os, const Queue& dt);

	QueueNode* head;
	QueueNode* tail;


};

#endif