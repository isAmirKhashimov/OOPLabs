#include "queue.h"
#include <iostream>

Queue::Queue()
{
	head = new QueueNode();
	tail = new QueueNode();

	head->next = tail;
	tail->prev = head;

	_size = 0;
}

Queue::Queue(const Queue& other): Queue()
{
	QueueNode* current = other.head;
	while (current->next != other.tail)
	{
		current = current->next;
		push(*current->Data);
	}
}

Queue::~Queue()
{
	std::cout << "I\'m Destructor\n";
}

size_t Queue::size()
{
	return _size;
}

bool Queue::empty()
{
	return _size == 0;
}

item* Queue::top()
{
	if (empty())
		throw;
	return head->next->Data;
}

void Queue::push(item& value)
{
	QueueNode* prelast = tail->prev;
	QueueNode* additional = new QueueNode(value);
	tail->prev = additional;
	prelast->next = additional;
	additional->next = tail;
	additional->prev = prelast;
	_size++;
}

item* Queue::pop()
{
	if (empty())
		throw;
	QueueNode* deleted = head->next;
	head->next = deleted->next;
	if (deleted->next != NULL)
		deleted->next->prev = head;
	_size--;
	return deleted->Data;
}

std::ostream& operator<<(std::ostream& os, const Queue& dt)
{
	QueueNode* current = dt.head;
	while (current->next != dt.tail)
	{
		current = current->next;
		current->Data->Print(os);
	}
	return os;
}

