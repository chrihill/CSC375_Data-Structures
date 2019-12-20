#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
        Queue<int> q;
        q.enque(10);
        q.enque(20);
        int val;
        q.dequeue(val);
        cout << val << endl;

        Queue<int> q2;
        q2 = q;
        q2.enque(30);
        q2.peek(val);
        cout << val << endl;
        q2.dequeue(val);
        cout << val << endl;
        q2.dequeue(val);
        cout << val << endl;
        q2.dequeue(val);
        cout << val << endl;


        return 0;
}
