#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    int el;
    stack1.pop(el); cout << el << endl;
    stack1.pop(el); cout << el << endl;

    stack1.push(40);
    stack1.pop(el); cout << el << endl;
    stack1.pop(el); cout << el << endl;

    cout << stack1.pop(el) << endl;
    return 0;
}
