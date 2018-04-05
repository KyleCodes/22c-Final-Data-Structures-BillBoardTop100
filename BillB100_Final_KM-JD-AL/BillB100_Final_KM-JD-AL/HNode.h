////////////////////////////////////////////
//		OWNER: ALEX
/////////////////////////////////////////////////////////////////////
//			HNODE CLASS
/////////////////////////////////////////////////////////////////////
// HNode.h
////////////////////////////////////////////


#ifndef HNODE_H
#define HNODE_H

#include <cstddef>
#include "LNode.h"
#include <iostream>
template < class T>
class HNode
{
private:
	int item; // A data item
	LNode<T>* first; // Pointer to next node
	LNode<T>* last; // Pointer to next node
public:
	HNode();
	~HNode();
	void setItem(int);
	void setNext(LNode<T>* nextNodePtr);
	void setLast(LNode<T>* lastNodePtr);
	int getItem();
	LNode<T>* getNext();
	LNode<T>* getLast();
}; // end Node

template < class T>
HNode<T>::HNode() : last(nullptr), first(nullptr)
{
	item = 0;
} // end default constructor
template < class T>
HNode<T>::~HNode()
{
	delete first;
	delete last;
} // end default destructor
template < class T>
void HNode<T>::setItem(int anItem)
{
	item = anItem;
} // end setItem
template < class T>
void HNode<T>::setNext(LNode<T>* nextNodePtr)
{
	first = nextNodePtr;
} // end setNext
template < class T>
void HNode<T>::setLast(LNode<T>* nextNodePtr)
{
	last = nextNodePtr;
} // end setNext
template < class T>
int HNode<T>::getItem()
{
	return item;
} // end getItem
template < class T>
LNode<T>* HNode<T>::getNext()
{
	return first;
} // end getNext
template < class T>
LNode<T>* HNode<T>::getLast()
{
	return last;
} // end getNext

#endif