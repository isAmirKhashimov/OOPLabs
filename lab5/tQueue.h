#pragma once
#ifndef TQUEUE_H_INCLUDED
#define TQUEUE_H_INCLUDED

#include "rectangle.h"
#include "queueNode.h"
#include "queueNode.cpp"
#include "titerator.h"
#include <string>

#define sNode std::shared_ptr<QueueNode<T>>

template<class T>
class TQueue {
private:
	size_t size;
	QueueNode<T> head;
	QueueNode<T>* last;
public:
	//  онструктор по умолчанию
	TQueue<T>();
	//  онструктор копировани€ очереди.
	TQueue<T>(const TQueue<T>& other);
	// ћетод, добавл€ющий фигуру в конец очереди.
	void Push(const T& rectangle);
	// ћетод, убирающий первую фигуру из очереди.
	void Pop();
	// ћетод, возвращающий ссылку на первую в очереди фигуру
	const T& Top();
	// ћетод, провер€ющий пустоту очереди
	bool Empty();
	// ћетод, возвращающий длину очереди
	size_t Length();
	// ќператор вывода очереди в формате:
	// "=> Sn Sn-1 ... S1 =>", где Si - площадь фигуры,
	// а n Ц номер последней фигуры в очереди
	void Print(std::ostream& os);
	// ћетод, удал€ющий все элементы контейнера,
	// но позвол€ющий пользоватьс€ им.
	void Clear();
	// итератор начала
	TIterator<T> begin();
	// итератор конца
	TIterator<T> end();
	// ƒеструктор
	virtual ~TQueue();
};


#endif