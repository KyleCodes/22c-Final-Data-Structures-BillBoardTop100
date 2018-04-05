#include "Song.h"

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
//		SONG FUNCTION DEFINITIONS
////////////////////////////////////////////

////////////////////////////////////////////
// SONG CONSTRUCTORS
////////////////////////////////////////////

Song::Song()
{
	title = "";
	artist = "";
	position = 0;
	lastWeek = 0;
	tempNum = 1;
}

Song::Song(string title, string artist, int position, int lastWeek)
{
	setTitle(title);
	setArtist(artist);
	setPosition(position);
	setLastWeek(lastWeek);
}

////////////////////////////////////////////
// SETTER FUNCTIONS
////////////////////////////////////////////

void Song::setTitle(string ttl)
{
	this->title = ttl;
}

void Song::setArtist(string art)
{
	this->artist = art;
}

void Song::setPosition(int pos)
{
	this->position = pos;
}

void Song::setLastWeek(int lw)
{
	this->lastWeek = lw;
}

Song Song::createSong()
{
	string title;
	string artist;
	int position;
	int lastWeek;
	cin.ignore();

	//cout << "SONG " << tempNum << endl;
	cout << endl;
	cout << "----------" << endl;
	cout << "Title     :  ";
	getline(cin, title);
	cout << "Artist    :  ";
	getline(cin, artist);
	cout << "Position  :  ";
	cin >> position;
	cout << "Last Week :  ";
	cin >> lastWeek;
	Song tempSong(title, artist, position, lastWeek);
	tempNum = tempNum + 1;

	return tempSong;
}

////////////////////////////////////////////
// GETTER FUNCTIONS
////////////////////////////////////////////

void Song::printSong()
{
	cout << title << endl;
	cout << artist << endl;
	cout << position << endl;
	cout << lastWeek << endl;
}

string Song::returnTitle() const
{
	return this->title;
}

string Song::returnArtist()
{
	return this->artist;
}

int Song::returnPosition()
{
	return this->position;
}

int Song::returnLastWeek()
{
	return this->lastWeek;
}

////////////////////////////////////////////
// OPERATOR OVERLOADS
////////////////////////////////////////////

ofstream& operator<<(ofstream& out, Song& b)
{
	const char tab = '\t';
	out << b.title << tab;
	out << b.artist << tab;
	out << b.position << tab;
	out << b.lastWeek << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Song&b)
{
	const char tab = '\t';
	char c[500];
	in.getline(c, 500, tab);
	b.title = c;
	in.getline(c, 500, tab);
	b.artist = c;
	in.getline(c, 500, tab);
	b.position = atoi(c);
	in.getline(c, 500, '\n');
	b.lastWeek = atoi(c);
	return in;
}

ostream& operator<<(ostream& out, Song& s)
{
	s.printSong();
	return out;
}

bool Song::operator < (const Song &right)
{
	bool status;

	if (this->returnTitle() < right.returnTitle())
		status = true;
	else
		status = false;

	return status;
}

bool Song::operator > (const Song &right)
{
	bool status;

	if (this->returnTitle() > right.returnTitle())
		status = true;
	else
		status = false;

	return status;
}

bool Song::operator == (const Song &right)
{
	bool status;

	if (this->returnTitle() == right.returnTitle())
		status = true;
	else
		status = false;

	return status;
}