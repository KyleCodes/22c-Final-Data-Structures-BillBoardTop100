////////////////////////////////////////////
//		OWNERS: KYLE / JOSH 
/////////////////////////////////////////////////////////////////////
//			BST CLASS
/////////////////////////////////////////////////////////////////////
// BST.h
////////////////////////////////////////////

#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include "BNode.h"
#include "Song.h"
#include "FileStorage.h"
using namespace std;

template < class T >
class BST
{
private:
	// SORT TYPE
	int sortType;

	// ROOT POINTER
	BNode<T>* root;

	// FILE IO HELPER
//	FileStorage<T> file;


	// BST PRIVATE STANDARD FUNCTIONS 
	void insert(BNode<T>*&, BNode<T>*&);
	void deleteSubTree(BNode<T>*);
	void deleteBNode(T, BNode<T>*&);
	void makeDeletion(BNode<T>*&);

	// BST PRIVATE DISPLAY FUNCTIONS 
	void inOrder(BNode<T>*) const;
	void preOrder(BNode<T>*) const;
	void postOrder(BNode<T>*, int) const;
	void printLevelOrder(BNode<T>*) const;
	void printGivenLevel(BNode<T>*, int) const;
	int height(BNode<T>*) const;
	void TreeDisplay(BNode<T>* root, int indent);

	// BST SAVE DISPLAY FUNCTIONS 
	void saveInOrder(BNode<T>*) const;
	//void savePreOrder(BNode<T>*) const;
	//void savePostOrder(BNode<T>*);
	//void saveLevelOrder(BNode<T>*);
	//void saveGivenLevel(BNode<T>*, int);

public:
	int addE = 0;
	int removeE = 0;
	int searchE = 0;
	int searches = 0;
	int additions = 0;
	int deletions = 0;
	// BST CONSTRUCTORS
	BST();
	~BST();

	// BST STANDARD FUNCTIONS 
	bool isEmpty();
	void insertBNode(T);
	void remove(T);
	bool search(T);
	void removeAll();

	// BST DISPLAY FUNCTIONS
	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	void breadthDisplay();
	void FinalPrint();

	// TREE SAVE FUNCTIONS
	void saveInOrder();
	//void savePostOrder();
	//void savePreOrder();
	//void breadthSave();

	void print();
	void printRecurse(BNode<T>*, int level);

	// COMPARE FUNCTIONS
//	bool compareFriends(const FriendInfo&, const FriendInfo&);
	bool equalMembers(Song&, Song&);
	void changeSortType(int);
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//		FUNCTION DEFINITIONS
////////////////////////////////////////////

////////////////////////////////////////////
// BST CONSTRUCTOR
////////////////////////////////////////////
template < class T >
BST<T>::BST()
{
	root = NULL;
}

template < class T >
BST<T>::~BST()
{
	deleteSubTree(root);
}

////////////////////////////////////////////
// BST STANDARD FUNCTIONS
////////////////////////////////////////////

template < class T >
bool BST<T>::isEmpty()
{
	bool status;
	if (!root)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}

template <class T>
void BST<T>::insertBNode(T obj)
{
	additions += 1;
	BNode<T>* newPtr = new BNode<T>;

	cout << "    INSERTING" << endl;
	//cout << obj << endl;

	newPtr->data = obj;
	newPtr->left = NULL;
	newPtr->right = NULL;

	insert(root, newPtr);
	addE += 5;
}

template < class T >
void BST<T>::insert(BNode<T>*& currPtr, BNode<T>*& newPtr)
{
	addE += 1;
	if (currPtr == NULL)
	{
		addE += 1;
		currPtr = newPtr;
	}
	else if (newPtr->data < currPtr->data)
	{
		addE += 2;
		insert(currPtr->left, newPtr);
	}
	else
	{
		addE += 1;
		insert(currPtr->right, newPtr);
	}
}

template < class T >
void BST<T>::remove(T obj)
{
	deletions += 1;
	deleteBNode(obj, root);
}

template < class T >
void BST<T>::deleteBNode(T obj, BNode<T>*& currPtr)
{
	//if (obj < currPtr->data)
	removeE += 1;
	if (obj == currPtr->data)
	{
		removeE += 1;
		makeDeletion(currPtr);
	}
	else if (obj < currPtr->data)
	{
		removeE += 2;
		deleteBNode(obj, currPtr->left);
	}
	else if (currPtr->data < obj)
	{
		removeE += 4;
		deleteBNode(obj, currPtr->right);
	}
	else
	{
		removeE += 2;
		cout << "compared succesffully, deleting" << endl;
		makeDeletion(currPtr);
	}
}

template < class T >
void BST<T>::makeDeletion(BNode<T>*& currPtr)
{
	BNode<T>* tempBNode;
	removeE += 1;
	if (currPtr == NULL)
	{
		removeE += 2;
		cout << "BNode is already Empty" << endl;
	}
	else if (currPtr->right == NULL)
	{
		//	cout << "currptr->right == NULL" << endl;
		tempBNode = currPtr;
		currPtr = currPtr->left;
		delete tempBNode;
		removeE += 5;
	}
	else if (currPtr->left == NULL)
	{
		removeE += 6;
		//	cout << "currptr->left == NULL" << endl;
		tempBNode = currPtr;
		currPtr = currPtr->right;
		delete tempBNode;
	}
	else
	{
		removeE += 8;
		//	cout << "else" << endl;
		tempBNode = currPtr->right;
		while (tempBNode->left){
			removeE += 3;
			tempBNode = tempBNode->left;
		}
		tempBNode->left = currPtr->left;
		tempBNode = currPtr;

		currPtr = currPtr->right;
		delete tempBNode;
	}
}

template < class T >
void BST<T>::removeAll()
{
	deleteSubTree(root);
}

template < class T >
void BST<T>::deleteSubTree(BNode<T>* currPtr)
{
	if (currPtr != NULL)
	{
		if (currPtr->left)
			deleteSubTree(currPtr->left);
		if (currPtr->right)
			deleteSubTree(currPtr->right);
		delete currPtr;
	}
}

template < class T >
bool BST<T>::search(T obj)
{
	searches += 1;
	BNode<T>* currPtr = root;
	searchE += 1;
	while (currPtr)
	{
		searchE += 9;
		if (obj == currPtr->data)
			return true;
		else if (obj < currPtr->data)
			currPtr = currPtr->left;
		else
			currPtr = currPtr->right;
		equal
	}
	return false;
}


////////////////////////////////////////////
// BST DISPLAY FUNCTIONS
////////////////////////////////////////////

template < class T >
void BST<T>::printInOrder()
{
	inOrder(root);
}

template < class T >
void BST<T>::inOrder(BNode<T>* ptr) const
{
	if (ptr != NULL)
	{
		inOrder(ptr->left);
		cout << "___________________________" << endl;
		cout << ptr->data;

		inOrder(ptr->right);
	}
}

template < class T >
void BST<T>::printPreOrder()
{
	preOrder(root);
}

template < class T >
void BST<T>::preOrder(BNode<T>* ptr) const
{
	if (ptr != NULL)
	{
		cout << ptr->data << endl;
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

template < class T >
void BST<T>::printPostOrder()
{
	postOrder(root);
}

template < class T >
void BST<T>::postOrder(BNode<T>* ptr, int indent = 0) const
{
	/*if (ptr != NULL)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->data << endl;
	}*/


	if (ptr != NULL)
	{
		if (ptr->left)
		{
			postOrder(ptr->left, indent + 4);
		}
		if (ptr->right)
		{
			postOrder(ptr->right, indent + 4);
		}
		if (indent)
		{
			cout << setw(indent) << ' ';
		}
		cout << ptr->data << "\n ";
	}
}

template <class T>
void BST<T>::breadthDisplay()
{
	printLevelOrder(root);
}


template < class T >
void BST<T>::printLevelOrder(BNode<T>* ptr) const
{
	int h;
	h = height(ptr);
	for (int i = 1; i <= h; i++)
	{
		printGivenLevel(ptr, i);
	}
}

template < class T >
void BST<T>::printGivenLevel(BNode<T>* ptr, int level) const
{
	if (ptr == NULL)
	{
		return;
	}
	if (level == 1){
		cout << ptr->data << endl;
	}
	else if (level > 1)
	{
		printGivenLevel(ptr->left, level - 1);
		printGivenLevel(ptr->right, level - 1);
	}
}

template < class T >
int BST<T>::height(BNode<T>* BNode) const
{
	if (BNode == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(BNode->left);
		int rheight = height(BNode->right);

		if (lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return(rheight + 1);
		}
	}
}

////////////////////////////////////////////
// BST SAVE FUNCTIONS
////////////////////////////////////////////

template < class T >
void BST<T>::saveInOrder()
{
	FileStorage<T> FIO;
	FIO.changeOutputName("BillB100.txt");
	FIO.deleteContents();
	saveInOrder(root);
}

template < class T >
void BST<T>::saveInOrder(BNode<T>* ptr) const
{
	FileStorage<T> FIO;
	FIO.changeOutputName("BillB100.txt");
	if (ptr != NULL)
	{
		FIO.writeToFile(ptr->data);
		saveInOrder(ptr->left);
		saveInOrder(ptr->right);
	}
}
//
//template < class T >
//void BST<T>::savePreOrder()
//{
//	savePreOrder(root);
//}
//
//template < class T >
//void BST<T>::savePreOrder(BNode<T>* ptr) const
//{
//	if (ptr != NULL)
//	{
//		FIO.changeOutputName("PreOrderSort.txt");
//		FIO.writeToFile(ptr->data);
//		savePreOrder(ptr->left);
//		savePreOrder(ptr->right);
//	}
//}
//
//template < class T >
//void BST<T>::savePostOrder()
//{
//	FIO.changeOutputName("LastNameSort.txt");
//	FIO.deleteContents();
//	savePostOrder(root);
//}
//
//template < class T >
//void BST<T>::savePostOrder(BNode<T>* ptr)
//{
//	if (ptr != NULL)
//	{
//		savePostOrder(ptr->left);
//		savePostOrder(ptr->right);
//		FIO.writeToFile(ptr->data);
//	}
//}
//
//template <class T>
//void BST<T>::breadthSave()
//{
//	saveLevelOrder(root);
//}
//
//
//template < class T >
//void BST<T>::saveLevelOrder(BNode<T>* ptr)
//{
//	FIO.changeOutputName("BirthdaySort.txt");
//	FIO.deleteContents();
//
//	int h;
//	h = height(ptr);
//	for (int i = 1; i <= h; i++)
//	{
//		saveGivenLevel(ptr, i);
//	}
//}
//
//template < class T >
//void BST<T>::saveGivenLevel(BNode<T>* ptr, int level)
//{
//	if (ptr == NULL)
//	{
//		return;
//	}
//	if (level == 1){
//		FIO.writeToFile(ptr->data);
//	}
//	else if (level > 1)
//	{
//		saveGivenLevel(ptr->left, level - 1);
//		saveGivenLevel(ptr->right, level - 1);
//	}
//}

template < class T >
void BST<T>::printRecurse(BNode<T>* ptr, int level)
{
	//right
	//me
	//left
	if (ptr->right != NULL)
	{
		printRecurse(ptr->right, level + 1);
	}
	for (int i = 0; i < level; i++)
	{
		cout << "        ";
	}
	//cout << ptr->data<<endl;
	string tempOut = ptr->data.returnTitle();
	string finalOut = tempOut.substr(0, 8);
	cout << finalOut;

	cout << endl;
	if (ptr->left != NULL)
	{
		printRecurse(ptr->left, level + 1);
	}
}

template < class T >
void BST<T>::print()
{
	printRecurse(root, 0);
}

////////////////////////////////////////////
// COMPARE FUNCTIONS
////////////////////////////////////////////
//
//template < class T >
//bool BST<T>::compareFriends(const FriendInfo& left, const FriendInfo& right)
//{
//	switch (this->sortType)
//	{
//	case 1:
//	{
//			  if (left.returnTitle() < right.returnTitle())
//				  return true;
//			  else
//				  return false;
//	}
//	case 2:
//	{
//			  if (left.returnLastName() < right.returnLastName())
//				  return true;
//			  else
//				  return false;
//	}
//	}
//
//}

template < class T >
bool BST<T>::equalMembers(Song& left, Song& right)
{
	if (left.returnTitle() == right.returnTitle() && left.returnArtist() == right.returnArtist())
		return true;
	else
		return false;
}

template < class T >
void BST<T>::changeSortType(int select)
{
	this->sortType = select;
}

# endif