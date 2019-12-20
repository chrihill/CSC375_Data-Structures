#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


#include <iostream>

using namespace std;

template<class T>
struct Node{
	T obj;
	Node<T> * next;
};

template<class T>
class LinkedList{
public:
	LinkedList() {head = nullptr;}
	LinkedList(const LinkedList<T> & rhs) {deepCopy(rhs);}
	LinkedList<T> & operator = (const LinkedList<T> & rhs){
		if (this == &rhs) return (*this);
		makeEmpty();
		deepCopy(rhs);
		return (*this);
	}
	~LinkedList() {makeEmpty();}

	void addEl(const T &el);
	bool findEl(const T &el)const;
	bool removeEl(const T &el);
private:
	Node<T> * head;
	T * el;
	int capacity;
	void makeEmpty();
	void deepCopy(const LinkedList<T> & rhs);
};

template <class T>
void LinkedList<T>::makeEmpty(){
	Node<T> * curr = head;
	while (curr != nullptr){
		Node<T> * n = curr;
		curr = curr->next;
		delete n;
	}
	head = nullptr;
}

template <class T>
void LinkedList<T>::deepCopy(const LinkedList<T> & rhs){
    if(rhs.head == nullptr){head = nullptr; return;} //Checks to see if linkedlist is empty
    Node<T> * currRHS = head;
    Node<T> * prevNode = new Node<T>;
    prevNode->obj = currRHS->obj;
    head = prevNode;
    currRHS = currRHS->next;
    while(currRHS != nullptr){
            Node<T> * currCopy = new Node<T>;
            currCopy->obj = currRHS->obj;
            prevNode-> next = currCopy;
            currRHS =  currRHS->next;
            prevNode = currCopy;
    }
    prevNode->next = nullptr;
}

template<class T>
void LinkedList<T>::addEl(const T &el){
	Node<T> * newNode = new Node<T>;
	newNode->obj = el;
	newNode->next = head;
	head = newNode;
}

template<class T>
bool LinkedList<T>::findEl(const T &el)const{
	Node<T> * curr = head;
	while(curr != nullptr){
		if(curr->obj == el) return true;
		curr = curr->next;
	}
	return false;
}

template<class T>
bool LinkedList<T>::removeEl(const T &el){
	if (head == nullptr) return false;

	Node<T> * curr = head;
	if(curr->obj == el){
		head = curr->next;
		delete curr;
		return true;
	}
	while(curr->next != nullptr){
		if(curr->next->obj == el){
			Node<T> * n = curr->next;
			curr->next = curr->next->next;
			delete n;
			return true;
		}
		curr = curr->next;
	}
	return false;
}

#endif // LINKEDLIST_H_INCLUDED
