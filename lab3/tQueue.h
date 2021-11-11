#pragma once
#ifndef TQUEUE_H_INCLUDED
#define TQUEUE_H_INCLUDED

#include "rectangle.h"
#include "queueNode.h"

#define sNode std::shared_ptr<QueueNode>

class TQueue {
private:
	size_t size;
	QueueNode head;
	QueueNode* last;
public:
	// ����������� �� ���������
	TQueue();
	// ����������� ����������� �������.
	TQueue(const TQueue& other);
	// �����, ����������� ������ � ����� �������.
	void Push(const Rectangle& rectangle);
	// �����, ��������� ������ ������ �� �������.
	void Pop();
	// �����, ������������ ������ �� ������ � ������� ������
	const Rectangle& Top();
	// �����, ����������� ������� �������
	bool Empty();
	// �����, ������������ ����� �������
	size_t Length();
	// �������� ������ ������� � �������:
	// "=> Sn Sn-1 ... S1 =>", ��� Si - ������� ������,
	// � n � ����� ��������� ������ � �������
	friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
	// �����, ��������� ��� �������� ����������,
	// �� ����������� ������������ ��.
	void Clear();
	// ����������
	virtual ~TQueue();
};

#endif