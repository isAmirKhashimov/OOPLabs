#include "tQueue.h"
#include <string>

TQueue::TQueue()
{
	size = 0;
	head = QueueNode();
	last = &head;
}

TQueue::TQueue(const TQueue& other): TQueue()
{
	QueueNode* current = other.head.next;
	while (current != NULL)
	{
		this->Push(current->Data);
		current = current->next;
	}
}

void TQueue::Push(const Rectangle& rectangle)
{
	last->next = new QueueNode(rectangle);
	last = last->next;
	size++;
}

void TQueue::Pop()
{
	if (size == 0)
	{
		throw;
	}
	auto nextNode = head.next->next;
	delete(head.next);
	head.next = nextNode;
	size--;
}

const Rectangle& TQueue::Top()
{
	if (size == 0)
	{
		throw;
	}
	return head.next->Data;
}

bool TQueue::Empty()
{
	return size == 0;
}

size_t TQueue::Length()
{
	return size;
}

void TQueue::Clear()
{
	while (size != 0)
	{
		Pop();
	}
}

TQueue::~TQueue()
{
	Clear();
}

std::ostream& operator<<(std::ostream& os, const TQueue& queue)
{
	QueueNode* current = queue.head.next;
	std::string output = "";
	while (current != NULL)
	{
		output = std::to_string(current->Data.Area()) + " " + output;
		current = current->next;
	}
	output = "=> " + output + "=>";
	os << output << std::endl;
	return os;
}
