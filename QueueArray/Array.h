#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

template <class T>
class Array {
public:
	Array(int size);
	T & operator [] (int index);
	void changeSize(int newSize); // either increase or decrease the size of the array
	const int length() { return capacity; }
	string errMsg() {
	    if (err == 0) return "No error\n";
	    string msg = "";
	    if (err & 1) msg += "Invalid size for constructor\n";
	    if (err & 2) msg += "Invalid index\n";
	    if (err & 4) msg += "Invalid size for changeSize\n";
	    return msg;
	}

	Array<T> & operator = (const Array<T> & rhs);
	Array(const Array<T> & rhs) {deepCopy(rhs);}
	~Array() {delete [] els;}

private:
	T * els;
	int capacity;
	T dud;
	int err;
	void deepCopy(const Array<T> &rhs);

};

template <class T>
Array<T> & Array<T>::operator = (const Array<T> & rhs){
    if (this == &rhs) return (*this);
    delete [] els;
    deepCopy(rhs);
    return (*this);
}

template <class T>
void Array<T>::deepCopy(const Array<T> &rhs){
    els = new T[rhs.capacity];
    for (int i =0; i<rhs.capacity;i++){
        els[i] = rhs.els[i];
    }
    capacity = rhs.capacity;
    err = rhs.err;
}

template <class T>
Array<T>::Array(int size) { /* allocate space for els; initialize capacity */
    if (size <= 0) { err = 1; size = 1; }
    else { err = 0; }
    els = new T[size];
    capacity = size;
}

template <class T>
T & Array<T>::operator [] (int index) {
    if (index < 0 || index >= capacity) { err |= 2; return dud; }
    return els[index];
}

template <class T>
void Array<T>::changeSize(int newSize) {
    if (newSize <= 0) { err |= 4; return; }
	int howMuchToCopy;
	// set howMuchToCopy to the smaller of capacity and newSize
	howMuchToCopy = (capacity < newSize ? capacity : newSize);

	T * tempArr = new T[newSize];
	for (int i = 0; i < howMuchToCopy; i++) {
		tempArr[i] = els[i];
	}
	delete [] els;
	els = tempArr;
	capacity = newSize;
}



#endif // ARRAY_H_INCLUDED
