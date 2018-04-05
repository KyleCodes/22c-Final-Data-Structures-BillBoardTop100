////////////////////////////////////////////
//		OWNER: KYLE / JOSH
/////////////////////////////////////////////////////////////////////
//			SONG CLASS
/////////////////////////////////////////////////////////////////////
// Song.h
////////////////////////////////////////////

// Song is a module that creates the SONG DATA TYPE


#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Song
{
private:
	// SONG INFORMATION
	string title;
	string artist;	
	int position;	// CURRENT POSITION ON TOP 100 LIST
	int lastWeek;	// POSITION IT WAS AT 1 WEEK AGO
	int tempNum;

public:
	// CONSTRUCTORS
	Song();										// Sets values to Null
	Song(string, string, int, int);             // Collects pre established data and uses to construct

	// DESTRUCTOR
	//~Song();

	// SETTER FUNCTIONS
	void setTitle(string);
	void setArtist(string);
	void setPosition(int);
	void setLastWeek(int);
	Song createSong();							// Collects user input and returns a song object with that information 
	Song createSong(string, string, int, int);

	// GETTER FUNCTIONS
	string returnTitle() const;
	string returnArtist();
	int returnPosition();
	int returnLastWeek();

	// DISPLAY FUNCTION
	void printSong();							// Prints contents of a song object to screen	

	// OPERATOR OVERLOADS                       
	friend ostream& operator<<(ostream& out, Song& s);			// For use with stream outputting
	//friend istream& operator<<(istream& in, Song& s);
	friend ofstream& operator<<(ofstream& out, Song& s);		// For use with FSTREAM Storage
	friend ifstream& operator>>(ifstream& in, Song& s);
	bool operator < (const Song &right);
	bool operator > (const Song &right);
	bool operator == (const Song &right);
};



#endif