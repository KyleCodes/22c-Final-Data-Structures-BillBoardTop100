////////////////////////////////////////////
//		OWNER: ALEX
/////////////////////////////////////////////////////////////////////
//			TOUPLE CLASS
/////////////////////////////////////////////////////////////////////
// touple.h
////////////////////////////////////////////


#ifndef TUPLE_H
#define TUPLE_H

#include <cstddef>
#include <string>
#include <iostream>
using namespace std;
template < class T>
class touple
{
private:
	T item;
	string key;
public:
	touple();
	touple(T i, string k);
	~touple();
	T getItem();
	string getKey();
	void setKey(string k);
	void setItem(T i);
	template <class T> friend std::ostream& operator<<(std::ostream&, touple<T>);
};

template < class T>
touple<T>::touple()
{
} // end default constructor

template < class T>
touple<T>::touple(T i, string k)
{
	key = k;
	item = i;
} // end default constructor

template < class T>
touple<T>::~touple()
{
} // end default constructor

template < class T>
T touple<T>::getItem()
{
	return item;
}

template < class T>
string touple<T>::getKey()
{
	return key;
}

template < class T>
void touple<T>::setKey(string k)
{
	key = k;
}

template < class T>
void touple<T>::setItem(T i)
{
	item = i;
}

template <class T>
std::ostream& operator<<(ostream& o, touple<T> tup)
{
	o << tup.getItem() << "," << tup.getKey();
	return o;
}

#endif