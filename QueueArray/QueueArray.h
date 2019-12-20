#ifndef QUEUEARRAY_H_INCLUDED
#define QUEUEARRAY_H_INCLUDED

#include <string>
#include <iostream>

#include "Array.h"

using namespace std;

template <class T>
class Queue {
public:
    Queue() : els(2){front = back = -1;}

    void enqueue(const T & el);
    bool dequeue(T & el);
    bool peek(T & el);
    bool isEmpty() const {return (front == -1);}
    void makeEmpty() {front = back = -1;}
private:
    Array<T> els;
    int front;
    int back;
};

template <class T>
void Queue<T>::enqueue(const T & el) {
    if (front == -1){ //If Array is empty
        els[0] = el;
        front = back = 0;
        return;
    }
    if ((back == front -1) or (front == 0 && back == els.length() - 1)) //If Array is full
       els.changeSize(els.length()*2);
       if(back < front){
        for(int i=0;i<=back;i++){
            els[els.length()/2 +i] = els[i];
        }
        back = els.length()/2 + back;
       }
        back++;
        if(back = els.length()) back = 0;
        els[back] = el;
        return;
}

template <class T>
bool Queue<T>::peek(T & el){
    if (front == -1) return false;
    el = els[front];
    return true;
}

template <class T>
bool Queue<T>::dequeue(T & el) {
    if (front == -1) return false;
    el = els[front];
    if (front == back) {front = back = -1; return true;}
    front++;
    if (front >= els.length()) front = 0;
    return true;
}

#endif // QUEUEARRAY_H_INCLUDED
