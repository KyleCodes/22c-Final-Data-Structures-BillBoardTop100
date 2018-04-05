////////////////////////////////////////////
//		OWNER: ALEX
/////////////////////////////////////////////////////////////////////
//			HASH CLASS
/////////////////////////////////////////////////////////////////////
// Hash.h
////////////////////////////////////////////


#ifndef HASH_H
#define HASH_H

#include <cstddef>
#include "List.h"
#include "touple.h"
#include "Song.h"
#include <string>
#include <iostream>
using namespace std;
template < class T>
class Hash
{
private:
	// current length of myArray
	int currentPrime = 73;
	int num = 0;
	//an array of linked lists containing a touple item with a key of string type, and an item of T
	List<touple<T>> *myArray = new List<touple<T>>[currentPrime];
	// function takes a string and returns a number between 0 and current prime-1(inclusive)
	int HashVal(string k);
	int nextPrime();
	int getnum(string k);
	void updateCollisions();
public:
	int searchE = 0;
	int addE = 0;
	int removeE = 0;
	int searches = 0;
	int additions = 0;
	int deletions = 0;
	int collisions = 0;
	int numPreMod = 10;
	// constructor
	Hash();
	//destructor
	~Hash();
	//adds a touple with key and val to the linked list at index hashVal(key)of myArray
	void add(string k, T val);
	//returns current prime
	int getPrime();
	//searches the linked list at index hashVal(key) of myArray for a touple with key == k
	T search(string k);
	//does the same as search but removes the node from linked list instead of returning it
	void remove(string k);
	//prints all values in hash order
	void printall();
};

//constructor 
template < class T>
Hash<T>::Hash()
{
}

//destructor
template < class T>
Hash<T>::~Hash()
{
	delete[] myArray;
}

template < class T>
int Hash<T>::getnum(string k)
{
	int val = 0;
	//adds the asci values of each char to num
	for (int i = 0; i < k.length(); i++)
	{
		char x = k.at(i);
		val += int(x);
	}

	//returns num
	return num;
}
template < class T>
int Hash<T>::getPrime()
{
	return currentPrime;
}
template < class T>
void Hash<T>::updateCollisions()
{
	collisions = 0;
	for (int i = 0; i <currentPrime; i++)
	{
		if (myArray[i].length()>1)
		{
			collisions = collisions + myArray[i].length() - 1;
		}
	}

	if ((collisions-numPreMod)>15)
	{
		numPreMod = 0;
		int np = nextPrime();
		touple<T> *temp = new touple<T>[num];
		int count = 0;
		addE += 3;
		for (int i = 0; i < currentPrime; i++)
		{
			for (int j = 0; j < myArray[i].length(); j++)
			{
				temp[count] = myArray[i].get(j);
				count++;
				addE += 6;
			}
			addE += 3;
		}
		currentPrime = np;
		delete[] myArray;
		myArray = new List<touple<T>>[np];
		num = 0;
		addE += 4;
		for (int i = 0; i < count; i++)
		{
			addE += 6;
			this->add(temp[i].getKey(), temp[i].getItem());
		}
		delete[] temp;
	}
}

template < class T>
int Hash<T>::HashVal(string k)
{
	int num = 0;
	//adds the asci values of each char to num
	for (int i = 0; i < k.length(); i++)
	{
		char x = k.at(i);
		int n = int(x);
		num += int(x);
	}
	//makes num less then current prime(so its a valid index)
	num = num % currentPrime;

	//returns num
	return num;
}

//returns the next highest prime number
template < class T>
int Hash<T>::nextPrime()
{
	//weather or not the number is a prime
	bool prime = false;
	// next prime,
	int np = currentPrime;
	while (!prime)
	{
		np++;
		for (int i = 2; i*i <= np; i++)
		{
			if ((np / i)*i == np)
			{
				prime = true;
				break;
			}
		}

	}
	return np;
}

template < class T>
void Hash<T>::add(string k, T val)
{
	additions += 1;
	//create a touple tup with a value and a key
	touple<T> tup(val, k);
	//find index tup should be added to
	int ind = HashVal(k);

	/*for (int j = 1; j <= myArray[ind].length(); j++)
	{
		if (getnum(myArray[ind].get(j).getKey()) == getnum(k))
		{
			numPreMod += 1;
		}
	}*/
	//adds tup to the end of the linked list at index ind in the array
	myArray[ind].add(myArray[ind].length() + 1, tup);
	num++;
	addE += 3;
	updateCollisions();
}

template < class T>
T Hash<T>::search(string k)
{
	searches += 1;
	// get the index of key
	int ind = this->HashVal(k);
	//traverse the linked list at index of the array
	for (int i = 1; i <= myArray[ind].length(); i++)
	{
		searchE+=2;
		//if the key in the current node of the linked list matches k
		if (myArray[ind].get(i).getKey() == k)
		{
			//returns the value in touple in the current node of the linked list
			searchE += 1;
			return myArray[ind].get(i).getItem();
		}
		searchE += 2;
	}
	cout << "ERROR, Song not found" << endl;
	Song tempSong("""", """", 0, 0);
	return tempSong;
}

template < class T>
void Hash<T>::remove(string k)
{
	deletions += 1;
	// get the index of key
	int ind = this->HashVal(k);

	//traverse the linked list at index of the array
	for (int i = 1; i <= myArray[ind].length(); i++)
	{
		removeE += 2;
		//if the key in the current node of the linked list matches k
		if (myArray[ind].get(i).getKey() == k)
		{
			removeE += 1;
			//deletes the node in linked list
			myArray[ind].remove(i);
		}
		removeE += 2;
	}
}

template < class T>
void Hash<T>::printall()
{
	for (int i = 0; i < currentPrime; i++)
	{
		for (int j = 0; j < myArray[i].length();j++)
		{
			cout << "___________________________" << endl;
			cout<<myArray[i].get(j).getItem();
			//cout << endl;
		}
	}
}

#endif