#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Array.h"

template <class T>
class Stack {
public:
    Stack() : els(2), top(-1) { }
    void push(const T & el);
    bool pop(T & el);
    bool peek(T & el);
    bool isEmpty() const { return (top == -1); }
    void makeEmpty() { top = -1; }
private:
    Array<T> els;
    int top;
};

template <class T>
void Stack<T>::push(const T & el) {
    top++;
    if (top >= els.length()) {
        els.changeSize(els.length() * 2);
    }
    els[top] = el;
}

template <class T>
bool Stack<T>::pop(T & el) {
    if (top == -1) return false;
    el = els[top]; // set el...
    top--;
    return true;
}

template <class T>
bool Stack<T>::peek(T & el) {
    if (top == -1) return false;
    el = els[top]; // set el...
    return true;
}

#endif // STACK_H_INCLUDED
