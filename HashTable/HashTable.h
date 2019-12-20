#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <string>
#include <iostream>
#include "Array.h"
#include "List.h"

using namespace std;

template <class T>
class HashTable{
public:
    HashTable(int (*hf)(const T& el),int s):table(s){hashfn = hf;}
    bool insert(const T & el);
	bool retrieve(T & el);
	bool remove(T & el);
	bool update(T & el);
	void makeEmpty();
private:
    Array<LinkedList<T> > table;
	int (*hashfn)(const T& el);
};

template <class T>
bool HashTable<T>::insert(const T & el){
    int index = hashfn(el);
    if (index<0||index>=table.length()) return false;
    table[index].insert(el);
}

template <class T>
bool HashTable<T>::retrieve(T & el){
    int index = hashfn(el);
    if (index<0||index>=table.length()) return false;
    if (!table[index].retrieve(el)) return false;
    return true;
}

template <class T>
bool HashTable<T>::remove(T & el){
    int index = hashfn(el);
    if (index<0||index>=table.length()) return false;
    if (!table[index].remove(el)) return false;
    return true;
}

template <class T>
bool HashTable<T>::update(T & el){

}

template <class T>
void HashTable<T>::makeEmpty(){

}


#endif // HASHTABLE_H_INCLUDED
