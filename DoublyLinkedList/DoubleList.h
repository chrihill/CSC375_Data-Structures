#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
struct Node{
	T obj;
	Node<T> * next;
	Node<T> * prev;
};


template<class T>
class List{
public:
	List() {start=curr=nullptr;}

	void insert(const T & el);  //O(1) steps
	bool find(const T & el);    //O(n) steps    t/f & sets curr.
	bool retrieve(T & el);	    //O(n) steps    'T' cannot be const in this case because 'T' can change in a list.
	bool replace(const T & el); //O(1) steps
	bool remove(T & el);        //O(1) steps
	bool first(T & el);         //O(1) steps
	bool getNext(T & el);       //O(1) steps

	bool isEmpty() const {return(start==nullptr);}
	void makeEmpty() {}

private:
	Node<T> * start;
	Node<T> * curr;
};

template<class T>
void List<T>::insert(const T & el){
    Node<T> * newNode = new Node<T>;
	newNode->obj = el;
	newNode->next = start;
	start = newNode;
	curr = nullptr;
}

template<class T>
bool List<T>::find(const T & el){
    T item;
    if (!first(item)) return false;
    if (item==el) return true;
    while (getNext(item)){
        if (item==el) return true;
    }
    curr = nullptr;
    return false;
}

template<class T>
bool List<T>::retrieve(T & el){
    if (find(el)) {el = curr->obj; return true;}
    return false;
}

template<class T>
bool List<T>::replace(const T & el){
    if (curr==nullptr) return false;
    curr->obj = el;
    return true;
}

template<class T>
bool List<T>::remove(T & el){
    if (start == nullptr) return false;
	curr = start;
	if(curr->obj == el){
        el = curr->obj;
		start = curr->next;
		delete curr;
		curr = nullptr;
		return true;
	}
	while(curr->next != nullptr){
		if(curr->next->obj == el){
		    el = curr->next->obj;
			Node<T> * n = curr->next;
			curr->next = curr->next->next;
			delete n;
			curr = nullptr;
			return true;
		}
		curr = curr->next;
	}
	curr = nullptr;
	return false;
}


template<class T>
bool List<T>::first(T & el){
    if(start==nullptr) return false;
    curr = start;
    el = curr->obj;
    return true;
}

template<class T>
bool List<T>::getNext(T & el){
    if (curr==nullptr)return false;
    if(curr->next==nullptr) return false;
    curr = curr->next;
    el = curr->obj;
    return true;
}


#endif // DOUBLELIST_H_INCLUDED
