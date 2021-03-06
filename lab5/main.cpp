#include <iostream>
#include "tQueue.h"
#include "tQueue.cpp"
using namespace std;

int main()
{
	TQueue<Rectangle> queue = TQueue<Rectangle>();
	for (int i = 0; i < 30; i++)
	{
		Rectangle *rct = new Rectangle();
		rct->apixes[0].x = i + 1;
		queue.Push(*rct);
		delete rct;
	}
	for (Figure *elem : queue)
	{
		cout << *elem << " " << endl;
	}
    Rectangle rect1, rect2;
    cin >> rect1;
    cin >> rect2;
    queue.Push(rect1);
    queue.Push(rect2);
    cout << queue.Length() << "  " << queue.Top();
    cout << queue;
    rect2.apixes[0].x = 42;
    queue.Push(rect2);
    cout << queue.Length() << "  " << queue.Top();
    cout << queue;
    queue.Pop();
    cout << queue.Length() << "  " << queue.Top();
    cout << queue;
    queue.Pop();
    cout << queue.Length() << "  " << queue.Top();
    cout << queue;
}
