////////////////////////////////////////////
//		OWNER: ALEX
/////////////////////////////////////////////////////////////////////
//			LNODE CLASS
/////////////////////////////////////////////////////////////////////
// LNode.h
////////////////////////////////////////////


#ifndef LNODE_H
#define LNODE_H

#include <cstddef>
#include <iostream>
template < class T>
class LNode
{
private:
	T item; // A data item

	LNode<T>* next; // Pointer to next LNode
	LNode<T>* prev; // Pointer to prev LNode
public:
	LNode();
	~LNode();
	LNode(const T& anItem);
	LNode(const T& anItem, LNode<T>* nextLNodePtr);
	void setItem(const T& anItem);
	void setNext(LNode<T>* nextLNodePtr);
	void setPrev(LNode<T>* nextLNodePtr);
	T getItem();
	LNode<T>* getNext();
	LNode<T>* getPrev();
}; // end LNode

template < class T>
LNode<T>::LNode() :next(nullptr)
{
} // end default constructor
template < class T>
LNode<T>::~LNode()
{
} // end default constructor

template < class T>
LNode<T>::LNode(const T& anItem) : item(anItem), next(nullptr)
{
} // end constructor
template < class T>
LNode<T>::LNode(const T& anItem, LNode<T>* nextLNodePtr) :
item(anItem), next(nextLNodePtr)
{
} // end constructor
template < class T>
void LNode<T>::setItem(const T& anItem)
{
	item = anItem;
} // end setItem
template < class T>
void LNode<T>::setNext(LNode<T>* nextLNodePtr)
{
	next = nextLNodePtr;
} // end setNext
template < class T>
void LNode<T>::setPrev(LNode<T>* nextLNodePtr)
{
	prev = nextLNodePtr;
} // end setNext
template < class T>
T LNode<T>::getItem()
{
	return item;
} // end getItem
template < class T>
LNode<T>* LNode<T>::getNext()
{
	return next;
} // end getNext
template < class T>
LNode<T>* LNode<T>::getPrev()
{
	return prev;
} // end getNext

#endif