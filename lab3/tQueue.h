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
	//  онструктор по умолчанию
	TQueue();
	//  онструктор копировани€ очереди.
	TQueue(const TQueue& other);
	// ћетод, добавл€ющий фигуру в конец очереди.
	void Push(const Rectangle& rectangle);
	// ћетод, убирающий первую фигуру из очереди.
	void Pop();
	// ћетод, возвращающий ссылку на первую в очереди фигуру
	const Rectangle& Top();
	// ћетод, провер€ющий пустоту очереди
	bool Empty();
	// ћетод, возвращающий длину очереди
	size_t Length();
	// ќператор вывода очереди в формате:
	// "=> Sn Sn-1 ... S1 =>", где Si - площадь фигуры,
	// а n Ц номер последней фигуры в очереди
	friend std::ostream& operator<<(std::ostream& os, const TQueue& queue);
	// ћетод, удал€ющий все элементы контейнера,
	// но позвол€ющий пользоватьс€ им.
	void Clear();
	// ƒеструктор
	virtual ~TQueue();
};

#endif