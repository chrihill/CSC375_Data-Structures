#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
struct Node{
	T obj;
	Node<T> * next;
};


template<class T>
class List{
public:
	List() {start=curr=nullptr;}
	List(const List<T> & rhs) {deepCopy(rhs);}
	List<T> & operator = (const List<T> & rhs);
	~List() {makeEmpty();}

	void insert(const T & el);  //O(1) steps
	bool find(const T & el);    //O(n) steps    t/f & sets curr.
	bool retrieve(T & el);	    //O(n) steps    'T' cannot be const in this case because 'T' can change in a list.
	bool replace(const T & el); //O(1) steps
	bool remove(T & el);        //O(n) steps
	bool first(T & el);         //O(1) steps
	bool getNext(T & el);       //O(1) steps

	bool isEmpty() const {return(start==nullptr);}
	void makeEmpty();

private:
	Node<T> * start;
	Node<T> * curr;
	void deepCopy(const List<T> & rhs);
};

template <class T>
void List<T>::deepCopy(const List<T> & rhs){
    if(rhs.start == nullptr){start = curr = nullptr; return;} //Checks to see if linkedlist is empty
    Node<T> * currRHS = rhs.start;
    Node<T> * prevNode = new Node<T>;
    prevNode->obj = currRHS->obj;
    start = prevNode;
    if(rhs.curr == currRHS) curr = prevNode;
    currRHS = currRHS->next;
    while(currRHS != nullptr){
            Node<T> * currCopy = new Node<T>;
            currCopy->obj = currRHS->obj;
            prevNode-> next = currCopy;
            if(rhs.curr == currRHS) curr = currCopy;
            currRHS =  currRHS->next;
            prevNode = currCopy;
    }
    prevNode->next = nullptr;
    if(rhs.curr == nullptr) curr = nullptr;
}

template<class T>
List<T> & List<T>::operator = (const List<T> & rhs){
    if(this==&rhs) return(*this);
    makeEmpty();
    deepCopy(rhs);
    return(*this);
}

template<class T>
void List<T>::makeEmpty(){
    curr = start;
	while (curr != nullptr){
		Node<T> * n = curr;
		curr = curr->next;
		delete n;
	}
	start = curr = nullptr;
}

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

#endif // LIST_H_INCLUDED
