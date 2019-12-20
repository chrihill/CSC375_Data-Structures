#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
using namespace std;

template<class T>
struct Node{
	T obj;
	Node<T> * next;
};

template <class T>
class Queue{
public:
    Queue(){front = back = nullptr;}
    Queue(const Queue<T> & rhs) {deepCopy(rhs);}
    Queue<T> & operator = (const Queue<T> & rhs){
		if (this == &rhs) return (*this);
		makeEmpty();
		deepCopy(rhs);
		return (*this);
	}
    ~Queue(){makeEmpty();}
    void enque(const T & el);
    bool dequeue(T & el);
    bool peek(T & el)const;
    bool isEmpty()const {return (front == nullptr);}
    void makeEmpty();
private:
    Node<T> * front;
    Node<T> * back;
    void deepCopy(const Queue<T> & rhs);
};

template <class T>
void Queue::deepCopy(const Queue<T> & rhs){
    if (rhs.front == nullptr){ front = back = nullptr; return;}
    Node<T> * currRHS = rhs.front;
    Node<T> * prevNode = new Node<T>;
    prevNode->obj = currRHS->obj;
    head = prevNode;
    currRHS = currRHS->next;
    while(currRHS != nullptr){
        Node<T> * currCopy = new Node<T>;
        currCopy->obj = currRHS->obj;
        prevNode->next = currCopy;
        currRHS = currRHS->next;
        prevNode = currCopy;
    }
    prevNode->next = nullptr;
    back = prevNode;
}



template <class T>
void Queue<T>::enque(const T & el){
    Node<T> * newNode = new Node<T>;
    back->next = newNode;
    newNode->obj = el;
    newNode->next = nullptr;
    if(front == nullptr) {front = back = newNode; return;}
    back = newNode;
    if (front == nullptr) front = newNode;
}

template <class T>
bool Queue<T>::dequeue(T & el){
    if (front == nullptr) return false;
    el = front->obj;
    Node<T> * temp = front;
    front = front->next;
    delete temp;
    if (front == nullptr) back == nullptr;
    return true;
}

template <class T>
bool Queue<T>::peek(T & el) const{
    if (front == nullptr) return false;
    el = front->obj;
    return true;
}

template <class T>
void Queue<T>::makeEmpty(){
    T el;
    while(dequeue(el));
}



#endif // QUEUE_H_INCLUDED
