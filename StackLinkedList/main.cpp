#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    Stack<int> stack2;
    stack2 = stack1;

    int el;
    stack1.pop(el); cout << el << endl;
    stack1.pop(el); cout << el << endl;

    stack1.push(40);
    stack1.pop(el); cout << el << endl;
    stack1.pop(el); cout << el << endl;

    cout << stack1.pop(el) << endl;

    cout << stack2.isEmpty() << endl;
    stack2.pop(el); cout << el << endl;
    stack2.pop(el); cout << el << endl;
    stack2.peek(el); cout << el << endl;
    cout << stack2.isEmpty()<< endl;
    stack2.makeEmpty();
    cout << stack2.peek(el) << endl;

    return 0;
}
