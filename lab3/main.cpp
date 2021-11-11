#include <iostream>
#include "tQueue.h"

using namespace std;

int main()
{
    TQueue queue;
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
