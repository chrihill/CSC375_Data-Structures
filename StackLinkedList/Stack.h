#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
struct Node{
	T obj;
	Node<T> * next;
};

template <class T>
class Stack{
public:
    Stack() {top = nullptr;}
    Stack(const Stack<T> & rhs) {deepCopy(rhs);}
    Stack<T> & operator = (const Stack<T> & rhs);
    ~Stack(){makeEmpty();}

    void push(const T & el);
    bool pop(T & el);
    bool peek(T & el)const;
    bool isEmpty()const {return(top == nullptr);}
    void makeEmpty() {T el; while(pop(el));}
private:
    Node<T> * top;
    T * el;
    void deepCopy(const Stack<T> & rhs);
};

template <class T>
void Stack<T>::deepCopy(const Stack<T> & rhs){
    if (rhs.top == nullptr){ top= nullptr; return;}
    Node<T> * currRHS = rhs.top;
    Node<T> * prevNode = new Node<T>;
    prevNode->obj = currRHS->obj;
    top = prevNode;
    currRHS = currRHS->next;
    while(currRHS != nullptr){
        Node<T> * currCopy = new Node<T>;
        currCopy->obj = currRHS->obj;
        prevNode->next = currCopy;
        currRHS = currRHS->next;
        prevNode = currCopy;
    }
    prevNode->next = nullptr;
}

template<class T>
Stack<T> & Stack<T>::operator = (const Stack<T> & rhs){
		if (this == &rhs) return (*this);
		makeEmpty();
		deepCopy(rhs);
		return (*this);
}

template <class T>
void Stack<T>::push(const T & el){
	Node<T> * newNode = new Node<T>;
	newNode->obj = el;
	newNode->next = top;
	top = newNode;
}

template <class T>
bool Stack<T>::pop(T & el){
	if (isEmpty()) return false;
	el = top->obj;
	Node<T> * temp = top;
	top = top->next;
	delete temp;
	return true;
}

template <class T>
bool Stack<T>::peek(T & el) const {
	if (isEmpty()) return false;
	el = top->obj;      //Sets elements
	return true;
}
#endif // STACK_H_INCLUDED
