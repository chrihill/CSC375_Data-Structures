#include <iostream>
#include "QueueArray.h"

using namespace std;

int main()
{
     Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    int val;
    q.dequeue(val);
    cout << val << endl;
    Queue<int> q2;
    q2 = q;
    q2.enqueue(30);
    q2.peek(val);
    cout << val << endl;
    q2.dequeue(val);
    cout << val << endl;
    q2.dequeue(val);
    cout << val << endl;
    cout << q2.isEmpty() << endl;
    q.dequeue(val);
    cout << val << endl;
    q.makeEmpty();
    cout << q.isEmpty() << endl;

    return 0;
}
