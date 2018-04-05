////////////////////////////////////////////
//		OWNER: ALEX
/////////////////////////////////////////////////////////////////////
//			LIST CLASS
/////////////////////////////////////////////////////////////////////
// List.h
////////////////////////////////////////////


#ifndef LIST_H
#define LIST_H

#include <cstddef>
#include <iostream>
#include "HNode.h"
#include "LNode.h"
#include <stdexcept>
template < class T>
class List
{
private:
	HNode<T> head;
public:
	List(T i);
	List();
	~List();
	int length();
	void add(int n, T i);
	void remove(int n);
	void removeAll();
	T get(int n);
	void print();
}; // end Node

template < class T>
void List<T>::print()
{
	LNode<T>* temp;
	temp = head.getNext();
	for (int i = 0; i < head.getItem(); i++)
	{
		cout << temp->getItem() << endl;
		temp = temp->getNext();
	}
}

template < class T>
List<T>::List()
{

}

template < class T>
List<T>::List(T i)
{
	LNode<T>* first;
	first = new LNode<T>;
	first->setItem(i);
	head.setNext(first);
	head.setItem(1);
} // end default constructor
template < class T>
List<T>::~List()
{
	removeAll();
} // end default constructor
template < class T>
int List<T>::length()
{
	return head.getItem();
}

template < class T>
void List<T>::add(int n, T i)
{
	if (n == head.getItem() + 1 && n == 1)
	{
		LNode<T>* cur;
		cur = new LNode<T>;
		cur->setItem(i);
		head.setNext(cur);
		head.setItem(head.getItem() + 1);
	}
	else if (n == head.getItem() + 1)
	{
		LNode<T>* temp;
		temp = head.getNext();
		for (int i = 1; i < head.getItem(); i++)
		{
			temp = temp->getNext();
		}
		LNode<T>* cur;
		cur = new LNode<T>;
		cur->setItem(i);
		temp->setNext(cur);
		head.setItem(head.getItem() + 1);
	}
	else
	if (n == 1)
	{
		LNode<T>* first;
		first = new LNode<T>;
		first->setItem(i);
		head.setNext(first);
		head.setItem(1);
		head.setItem(head.getItem() + 1);
	}
	else
	if (n > head.getItem())
	{
	}
	else{
		LNode<T>* temp;
		temp = head.getNext();
		for (int i = 1; i < n; i++)
		{
			temp = temp->getNext();
		}
		LNode<T>* prev;
		prev = temp->getPrev();
		LNode<T>* cur;
		cur = new LNode<T>;
		cur->setItem(i);
		cur->setPrev(prev);
		cur->setNext(temp);
		temp->setPrev(cur);
		prev->setNext(cur);
		head.setItem(head.getItem() + 1);
	}
}

template < class T>
void List<T>::remove(int n)
{
	if (n == head.getItem())
	{
		LNode<T>* temp;
		temp = head.getNext();
		for (int i = 1; i < n - 1; i++)
		{
			temp = temp->getNext();
		}
		delete temp->getNext();
		temp->setNext(NULL);
		head.setItem(head.getItem() - 1);
	}
	else
	if (n == 1)
	{
		LNode<T>* first;
		first = head.getNext();
		head.setNext(first->getNext());
		delete first;
		head.setItem(head.getItem() - 1);
	}
	else
	if (n > head.getItem())
	{
		//throw exception
	}
	else
	{
		LNode<T>* temp;
		temp = head.getNext();
		for (int i = 1; i < n; i++)
		{
			temp = temp->getNext();
		}
		LNode<T>* prev;
		prev = temp->getPrev();
		LNode<T>* next;
		next = temp->getNext();
		next->setPrev(prev);
		prev->setNext(next);
		delete temp;
		head.setItem(head.getItem() - 1);
	}
}
template < class T>
T List<T>::get(int n)
{

	if (n >head.getItem())
	{
		throw std::invalid_argument("out of range");
	}
	LNode<T>* temp;
	temp = head.getNext();
	for (int i = 1; i < n; i++)
	{
		temp = temp->getNext();
	}
	return temp->getItem();
}
template < class T>
void List<T>::removeAll()
{

	while (head.getItem()>0)
	{
		remove(1);
	}
}

#endif