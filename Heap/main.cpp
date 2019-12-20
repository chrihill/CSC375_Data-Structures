#include <iostream>
#include "Heap.h"

using namespace std;



int main()
{
    Heap<int> myHeap;
    myHeap.enqueue(40);
    myHeap.display();
    myHeap.enqueue(20);
    myHeap.display();
    myHeap.enqueue(60);
    myHeap.display();
    myHeap.enqueue(30);
    myHeap.display();
    myHeap.enqueue(90);
    myHeap.display();

    return 0;
}
