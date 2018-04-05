////////////////////////////////////////////
//		OWNER: KYLE
/////////////////////////////////////////////////////////////////////
//			FILESTORAGE CLASS
/////////////////////////////////////////////////////////////////////
// FileStorage.h
////////////////////////////////////////////

#ifndef FILESTORAGE_H
#define FILESTORAGE_H
#include <iostream>
#include <fstream>
#include <string>
#include "Song.h">
#include "BST.h"
#include "Hash.h"
using namespace std;

template < class T >
class FileStorage
{
private:
	// FILE PATHS
	string inputfileName;
	string outputFileName;

public:
	// CONSTRUCTORS
	FileStorage();
	FileStorage(string);
	~FileStorage();

	// SETTERS
	void changeFilePath(string);
	void changeOutputName(string);

	// FILE OPERATIONS
	void readFromFile(BST<Song>&, Hash<Song>&);
	void writeToFile(T&) const;
	void deleteContents();
};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//		FUNCTION DEFINITIONS
////////////////////////////////////////////

////////////////////////////////////////////
// FILESTORAGE CONSTRUCTORS
////////////////////////////////////////////

template < class T >
FileStorage<T>::FileStorage()
{
	inputfileName = "testfile.txt";
	outputFileName = "InOrderSort.txt";
}

template < class T >
FileStorage<T>::FileStorage(string newName)
{
	inputfileName = newName;
}

template < class T >
FileStorage<T>::~FileStorage()
{}

////////////////////////////////////////////
// FILENAME OPERATIONS
////////////////////////////////////////////

template < class T >
void FileStorage<T>::changeFilePath(string newFile)
{
	inputfileName = newFile;
}

template < class T >
void FileStorage<T>::changeOutputName(string newFile)
{
	outputFileName = newFile;
}
////////////////////////////////////////////
// INPUT OPERATIONS
////////////////////////////////////////////

template < class T >
void FileStorage<T>::readFromFile(BST<Song>& tree, Hash<Song>& hash)
{
//	tree.removeAll();
	ifstream in;
	Song s;
	//cout << "Opening file" << endl;
	in.open(inputfileName, ios::in);


	while (!in.eof())
	{
		in >> s;
		if (in.fail())
		{
			cout << "Import Complete" << endl;
			return;
		}
		//cout << "Inserting node" << endl;
		tree.insertBNode(s);
		hash.add(s.returnTitle(), s);
	}
	//cout << "Closing file" << endl;
	in.close();
}

////////////////////////////////////////////
// OUTPUT OPERATIONS
////////////////////////////////////////////

template < class T >
void FileStorage<T>::writeToFile(T& obj) const
{
	ofstream out;
	out.open(outputFileName, ios::out | ios::app);
	out << obj;
	//out << '\n';
	out.close();
}

template < class T >
void FileStorage<T>::deleteContents()
{
	ofstream del;
	del.open(outputFileName, ios::out | ios::trunc);
	del.close();
}

#endif










































































//////////////////////////////////////////////
////		FileStorage CLASS
//////////////////////////////////////////////
//// FileStorage.h
//////////////////////////////////////////////
//
//
//// FileStorage is a module that handles FILE OPERATIONS
//// THIS CLASS IS STILL EXPERIMENTAL, SO THINGS WILL BE TEMPORARILY COMMENTED OUT UNTIL WE GET MORE 
//// FUNCTIONALITY FROM BSTs AND HASH TABLES
//
//
//#ifndef FILESTORAGE_H
//#define FILESTORAGE_H
//#include <iostream>
//#include <string>
//#include <fstream>
//#include "Song.h"
//#include "LinkedList.h"
//using namespace std;
//
//class FileStorage
//{
//private:
//	// test with single song, then array of songs
//	string fileName = "testfile.txt";
//
//public:
//	void writeToFile(Song&);
//	//Song readFromFile();
//	void readFromFile(LinkedList<Song>&);
//
//	//void writeToFile();
//	//void readFromFile();
//};
//
//#endif
//
//void FileStorage::writeToFile(Song& track)               // This version works one iteration at a time, and takes 1 song as a parameter
//{
//		//std::remove(fileName.c_str());
//		ofstream out;
//		out.open(fileName, ios::out | ios::app);
//		out << track;
//		out << '\n';
//		out.close();
//}
//
////Song FileStorage::readFromFile()                          // This version works one iteration at a time, for a single song
////{
////	ifstream in;
////	in.open(fileName, ios::in);
////	Song tempSong;
////	in >> tempSong;
////	in.close();
////	return tempSong;
////}
//
//void FileStorage::readFromFile(LinkedList<Song>& list)                           // This version takes a Linked List of songs as a parameter and fills it
//{
//	list.removeAll();
//	ifstream in;
//	in.open(fileName, ios::in);
//
//
//	while (!in.eof())
//	{
//		Song tempSong;
//		in >> tempSong;
//		list.appendNode(tempSong);
//	}
//	in.close();
//}
//
//
//
//
//
////void FileStorage::writeToFile()
////{
////	std::remove(fileName.c_str());
////	ofstream out;
////	out.open(fileName, ios::out);
////	for (int i = 0; i < tally; i++)
////	{
////		out << testSong;
////		if (i != tally - 1)
////			out << '\n';
////	}
////	out.close();
////}
////
////void FileStorage::readFromFile()
////{
////	//bookList.clear(); purpose is to erase anything in vector. we will be erasing linked list memebrs instead when thats up
////	ifstream in;
////	in.open(fileName, ios::in);
////
////	while (!in.eof())
////	{
////		Song b;
////		in >> b;
////		//bookList.push_back(b); adds a new element at the end of vector. we will create a new link in the list instead
////	}
////	in.close();
////}