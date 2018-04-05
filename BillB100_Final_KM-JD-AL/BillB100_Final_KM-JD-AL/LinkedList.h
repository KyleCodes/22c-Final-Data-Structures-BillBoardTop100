////////////////////////////////////////////
//		LinkedList CLASS
////////////////////////////////////////////
// LinkedList.h
////////////////////////////////////////////


// LinkedList is a module that handles our DATA STRUCURE
// FOR JOSH, I made chages to the DISPLAYLIST CLASS, to make it output Song Objects correctly
// ALSO, I added the REMOVEALL funtion, which clears the linked list - copied code from the destructor
// ALSO, I added the SAVELIST function, which steps through the list and saves the songs to a file


#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
using namespace std;

//CONTAINS THE NODE CLASS AND ALL MEMBER FUNCTIONS THAT OPERATE ON NODE AND STACK.

template <class T>
class LinkedList
{
protected:
	struct Node
	{
		Node *previous;
		T data;
		Node *next; //next pointer of type node
	};
	Node *head; // head pointer of type node or top of stack or front of queue
	Node *rear; // rear pointer
	int count; //counter

public:
	// Default Constructor 
	LinkedList();

	// Destructor 
	virtual ~LinkedList(); // destroyer will destroy the list

	// Mutator Functions
	void appendNode(T); // apendNode will add a new node to the end of the linked list
	void addNode(T);
	void deleteNode(T);
	void insertFirst(T);
	void removeFirst();
	void addLast(T);
	void removeAll();


	// Accessor Functions
	int top();
	void findAny(T);
	bool isEmpty();
	void displayList() const;// this will allow us to display the entire linked list or certain nodes
	void saveList() const;
};
template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
}

template <class T>
void LinkedList<T>::appendNode(T input) // apendNode will add a new node to the end of the linked list
{
	Node *newNode; // Dynamically Allocating a New Node
	Node *currPtr; // Allows us to move through by pointing at each node

	newNode = new Node;
	newNode->data = input;
	newNode->next = NULL;

	if (!head) //newNode becomes the first node in the list if there are no other nodes
	{
		head = newNode;
	}

	else
	{
		currPtr = head;

		while (currPtr->next != NULL) // this allows us to go through the linked list and add newNode as the last node . While the node that currptr is pointing to does not = null.
		{
			currPtr = currPtr->next; // sets curptr to the node that cuurptr points too, thereby moving through the list. 
		}
		currPtr->next = newNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::displayList() const // this will allow us to display the entire linked list or certain nodes
{

	Node *currPtr; // to move through the stack by pointing at nodes

	currPtr = head; // sets currptr to head so we can start from the top node in the stack

	cout << endl;
	while (currPtr != NULL)
	{
		cout << currPtr->data << endl;; // displays current values

		currPtr = currPtr->next; // sets curptr to the node that cuurptr points too, thereby moving through the list.  While the node that currptr is pointing to does not = null.
	}
	cout << endl;

}

template <class T>
void LinkedList<T>::saveList() const
{
	FileStorage file;

	Node *currPtr; // to move through the stack by pointing at nodes

	currPtr = head; // sets currptr to head so we can start from the top node in the stack

	while (currPtr != NULL)
	{
		file.writeToFile(currPtr->data);

		currPtr = currPtr->next; // sets curptr to the node that cuurptr points too, thereby moving through the list.  While the node that currptr is pointing to does not = null.
	}
	cout << endl;

}



template <class T>
void LinkedList<T>::findAny(T input)
{
	Node *temp;
	Node *currPtr; // to move through the list by pointing at nodes
	Node *searchnumber;
	temp = head;
	currPtr = head;

	while (currPtr != NULL && currPtr->data != input)
	{
		temp = currPtr;
		currPtr = currPtr->next; // does a loop through the linked list to find the node data.
	}

	if (currPtr != NULL)
	{
		searchnumber = currPtr;
		currPtr = currPtr->next;
		cout << " " << searchnumber << " Found";
	}
	else
	{
		cout << "dosnt exist" << endl;
	}
}

template <class T>
void LinkedList<T>::addNode(T input)
{
	Node *newNode; // ynamically created new node
	Node *currPtr; // to move through the list by pointing at nodes
	Node *previousNode = NULL; // a pointer to the previous node
	newNode = new Node;
	newNode->data = input;

	if (!head)   //if there are nodes, head is set to our newly created node and its next pointer is set to null.
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		currPtr = head; //otherwise we set our curr pointer to the head to start.
		previousNode = NULL;

		while (currPtr != NULL && currPtr->data < input)
		{
			previousNode = currPtr;
			currPtr = currPtr->next;

		}
		if (previousNode == NULL) // if this is the 1st node in the linked list
		{
			head = newNode;
			newNode->next = currPtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = currPtr;
		}

	}
	count++;
}
template <class T>
void LinkedList<T>::deleteNode(T input)
{
	Node *currPtr; // to point to nodes and move through the list
	Node *previousNode = NULL; // to point to the previous node

	if (!head) // if there is no head, return.
		return;
	if (head->data == input) // if what you want to delete is the first node delete it and set the next one as the new head.
	{
		currPtr = head->next;
		delete head;
		head = currPtr;
	}
	else
	{
		currPtr = head;

		while (currPtr != NULL && currPtr->data != input) // goes through the loop until curr ptr = null or you reach the num you want to delete
		{
			previousNode = currPtr; //continues to set previous to curr
			currPtr = currPtr->next; // sets curr to its next
		}
		// once its done alters the new previousNode and currPtr pointers.
		if (currPtr != NULL)
		{
			previousNode->next = currPtr->next; // this links the previous pointers next node to the currptr's next node effectively making prev before curr again.
			delete currPtr;
		}
		else if (currPtr == NULL)
		{
			previousNode = currPtr;
			delete currPtr;
		}

	}
	count--;

}

template <class T>
LinkedList<T>::~LinkedList() // destroyer will destroy the list
{
	Node *currPtr;
	Node *nextNode;


	//we will set the curr ptr to the head;
	currPtr = head;

	while (currPtr != NULL) // while currptr doesnt equal null
	{
		nextNode = currPtr->next; // use this pointer to save the next node
		delete currPtr; // delete curr ptr
		currPtr = nextNode; // set curr ptr to the nextnode value we defined earlier
	}

}

template <class T>
void LinkedList<T>::insertFirst(T input) // insert first function for stack inheritance.
{
	Node *newNode; // pointer to a new node

	newNode = new Node;
	newNode->data = input;

	if (isEmpty() == true)
	{
		head = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = head; //to set newnode before top, we make top the node that newnode's next pointer points to
		head = newNode; // now we set top = newnode. 
	}
	count++;
}

template <class T>
void LinkedList<T>::removeFirst() // remove first function for stack inheritance.
{

	Node *temp;

	if (isEmpty() == true)
	{
		cout << "Queue is empty." << endl;
	}
	else
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	count--;
}

template <class T>
bool LinkedList<T>::isEmpty()  // checker for stack and linked list
{
	bool status;
	if (!head)
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
void LinkedList<T>::addLast(T data)
{
	Node *newNode;

	newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if (isEmpty())
	{
		head = newNode;
		rear = newNode;
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}

	count++;

}

template <class T>
int LinkedList<T>::top()
{
	Node *Ptr;
	Ptr = head->next;       //FUCK AROUND WITH THIS
	if (isEmpty())
	{
		cout << "Stack is empty!\n" << endl;
		return NULL;
	}

	return Ptr->data;
}

template <class T>
void LinkedList<T>::removeAll()
{
	Node *currPtr;
	Node *nextNode;

	if (!this->isEmpty())
	{
			//we will set the curr ptr to the head;
			currPtr = head;

		while (currPtr != NULL) // while currptr doesnt equal null
		{
			nextNode = currPtr->next; // use this pointer to save the next node
			delete currPtr; // delete curr ptr
			currPtr = nextNode; // set curr ptr to the nextnode value we defined earlier
		}
	}
}
#endif