#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

template <class T>
struct Node {
	T obj;
	Node<T> * next;
};

template <class T>
class LinkedList {
public:
    LinkedList() { start = curr = nullptr; }
    LinkedList(const LinkedList<T> & rhs) { deepCopy(rhs); }
    LinkedList<T> & operator = (const LinkedList<T> & rhs);
    ~LinkedList() { makeEmpty(); }

    void insert(const T & el);      // O(1) steps
    bool find(const T & el);        // O(n) steps
    bool retrieve(T & el);          // O(n) steps
    bool replace(const T & el);     // O(1) steps
    bool remove(T & el);            // O(n) steps
    bool first(T & el);             // O(1) steps
    bool getNext(T & el);           // O(1) steps

    bool isEmpty() const { return (start == nullptr); }
    void makeEmpty();
private:
    Node<T> * start;
    Node<T> * curr;
    void deepCopy(const LinkedList<T> & rhs);
};

template <class T>
LinkedList<T> & LinkedList<T>::operator = (const LinkedList<T> & rhs) {
    if (this == &rhs) return (*this);
    makeEmpty();
    deepCopy(rhs);
    return (*this);
}

template <class T>
void LinkedList<T>::makeEmpty() {
	curr = start;
	while (curr != nullptr) {
		Node<T> * n = curr;
		curr = curr->next;
		delete n;
	}
	start = curr = nullptr;
}

template <class T>
void LinkedList<T>::deepCopy(const LinkedList<T> & rhs) {
	if (rhs.start == nullptr) { start = curr = nullptr; return; }
	Node<T> * currRHS = rhs.start;
	Node<T> * prevNode = new Node<T>;
	prevNode->obj = currRHS->obj;
	start = prevNode;
	if (rhs.curr == currRHS) curr = prevNode;
	currRHS = currRHS->next;
	while(currRHS != nullptr) {
		Node<T>* currCopy = new Node<T>;
		currCopy->obj = currRHS->obj;
		prevNode->next = currCopy;
		if (rhs.curr == currRHS) curr = currCopy;
		currRHS = currRHS->next;
		prevNode = currCopy;
	}
	prevNode->next = nullptr;
	if (rhs.curr == nullptr) curr = nullptr;
}

template <class T>
void LinkedList<T>::insert(const T & el) {
	Node<T> * newNode = new Node<T>;
	newNode->obj = el;
	newNode->next = start;
	start = newNode;
    curr = nullptr;
}

template <class T>
bool LinkedList<T>::find(const T & el) {
    T item;
    if (!first(item)) return false;
    if (item == el) return true;
    while(getNext(item)) {
        if (item == el) return true;
    }
    curr = nullptr;
    return false;
}

template <class T>
bool LinkedList<T>::retrieve(T & el) {
    if (find(el)) { el = curr->obj; return true; }
    return false;
}

template <class T>
bool LinkedList<T>::replace(const T & el) {
    if (curr == nullptr) return false;
    curr->obj = el;
    return true;
}

template <class T>
bool LinkedList<T>::remove(T & el) {
	if (start == nullptr) return false;
	curr = start;
	if (curr->obj == el) {
        el = curr->obj;
		start = curr->next;
		delete curr;
		curr = nullptr;
		return true;
	}
	while (curr->next != nullptr) {
		if (curr->next->obj == el) {
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

template <class T>
bool LinkedList<T>::first(T & el) {
    if (start == nullptr) return false;
    curr = start;
    el = curr->obj;
    return true;
}

template <class T>
bool LinkedList<T>::getNext(T & el) {
    if (curr == nullptr) return false;
    if (curr->next == nullptr) return false;
    curr = curr->next;
    el = curr->obj;
    return true;
}

#endif // LINKEDLIST_H_INCLUDED
