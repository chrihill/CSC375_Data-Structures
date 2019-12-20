#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <iostream>
#include "Array.h"

using namespace std;

template<class T>
class Heap{
public:
    Heap():els(2) {heapSize = 0;}
    void enqueue(const T & el);
    void dequeue(T & el);
    bool isEmpty() {return (heapSize==0);}
    bool makeEmpty() {heapSize=0;}
    void display() {for (int i=0;i<heapSize;i++) {cout << els[i] << " ";} cout << endl;}
private:
    Array<T> els;
    int heapSize;
};

template<class T>
void Heap<T>::enqueue(const T & el){
    if(heapSize >= els.length()) els.changeSize(heapSize * 2);
    els[heapSize++] = el;
    int currIndex = heapSize - 1;
    int par;
    while(par>0){
        int par = (currIndex - 1)/2;
        if(el > els[par]) {currIndex = par; els[currIndex] = els[par];}
        else break;
        currIndex = par;
    }
    els[currIndex] = el;
}

/*template<class T>
void Heap::dequeue(const T & el){

}
*/

#endif // HEAP_H_INCLUDED
