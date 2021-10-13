#include <iostream>
#include "queue.h"
#include "rectangle.h"

using namespace std;

int main()
{
    Queue queue;
    Rectangle rect(cin);
    Rectangle rect2(cin);
    Rectangle rect3 = rect2;
    queue.push(rect);
    queue.push(rect2);
    queue.push(rect3);
    queue.pop();

    Queue queue2 = queue;
    cout << queue2;
    cout << (rect2 == rect);
    cout << (rect2 == rect3);
}
