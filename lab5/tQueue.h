#pragma once
#ifndef TQUEUE_H_INCLUDED
#define TQUEUE_H_INCLUDED

#include "rectangle.h"
#include "queueNode.h"
#include "queueNode.cpp"
#include "tIterator.h"
#include <string>
#include <memory>


template<class T>
class TQueue {
private:
	size_t size;
	QueueNode<T> head;
	QueueNode<T>* last;
public:
	// ����������� �� ���������
	TQueue<T>();
	// ����������� ����������� �������.
	TQueue<T>(const TQueue<T>& other);
	// �����, ����������� ������ � ����� �������.
	void Push(const T& rectangle);
	// �����, ��������� ������ ������ �� �������.
	void Pop();
	// �����, ������������ ������ �� ������ � ������� ������
	const T& Top();
	// �����, ����������� ������� �������
	bool Empty();
	// �����, ������������ ����� �������
	size_t Length();
	// �������� ������ ������� � �������:
	// "=> Sn Sn-1 ... S1 =>", ��� Si - ������� ������,
	// � n � ����� ��������� ������ � �������
	void Print(std::ostream& os);
	// �����, ��������� ��� �������� ����������,
	// �� ����������� ������������ ��.
	void Clear();
	TIterator<T> begin();
	TIterator<T> end();
	// ����������
	virtual ~TQueue();
};


#endif