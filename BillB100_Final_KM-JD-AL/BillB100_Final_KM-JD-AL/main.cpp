////////////////////////////////////////////
//				Kyle Muldoon
//				Jasraj Dhudwal
//				Alex Lambert
//			CIS 22C Final Project
////////////////////////////////////////////
//				MAIN FILE
////////////////////////////////////////////


// THIS PROGRAM EMULATES THE BILLBOARD TOP 100 LISTINGS.
//
// Main.cpp handles user interaction with the program through the use of Menus


#include <iostream>
#include <string>
#include <Windows.h>
#include "MMSystem.h"
#include "Song.h"
#include "FileStorage.h"
#include "LinkedList.h"
#include "Hash.h"
using namespace std;


int main()
{
	Song song;									// Song Instance, used for appending new items to linked list
	FileStorage<BST<Song>> FIO;							// Manages Fstream, reads from file to songList and stores songList to file
	BST<Song> songTree;
	Hash<Song> songHash;   // Linked List that exists at runtime to hold song database
	int menuSelect;							// used for selecting menu choice
	int searchchoice;
	string SongName;
	string artist;
	bool status;

	cout << "**************************************" << endl;
mainMenu:
	cout << "               Main Menu              " << endl;
	cout << "______________________________________" << endl;
	if (songTree.isEmpty())
		cout << "The Billboard list is currently empty" << endl << endl;
	else
		cout << endl;													// Draws Menu On Screen
	cout << "    1) Load from File            " << endl;
	cout << "    2) Save to File              " << endl;
	cout << "    3) Display Tree              " << endl;
	cout << "    4) Search                    " << endl;
	cout << "    5) Add a Song                " << endl;
	cout << "    6) Delete a Song             " << endl;
	cout << "    7) Enter Music Player        " << endl;
	cout << "    8) Efficiency Calculator     " << endl;
	cout << "    9) Quit                      " << endl;
	cout << endl;
	cout << "             ";

getInput:
	cin >> menuSelect;
	if (cin.fail() || menuSelect <0 || menuSelect > 9)
	{
		cout << "Invalid" << endl;
		goto getInput;
	}


	switch (menuSelect)
	{
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 1:		// CASE 1 LOADS A TEXT FILE STORING SONG INFROMATION INTO THE BINARY TREES
	{
					int fileChoice;
					cout << "////////////////////////////////////////////////////////" << endl;
					cout << "      Load this week's list, or submit an update." << endl;
					cout << "        ***This will delete the existing List***     " << endl;
					cout << endl;
					cout << "    1)  BillB100.txt           " << endl;
					cout << "    2)  Custom File Path       " << endl;
					cout << "    3)  Return                 " << endl;
					cout << endl;
					cout << "             ";
				fileChoice:
					cin >> fileChoice;
					cout << endl;
					if (cin.fail() || menuSelect < 0 || menuSelect > 3)
					{
						cout << "Invalid entry, Try again." << endl;
						goto fileChoice;
					}
					else if (fileChoice == 3)
					{
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						goto mainMenu;
					}
					else if (fileChoice == 2)
					{
						string newFilePath;

						cout << "         Drag and drop your TXT file here" << endl;
						cout << "NOTICE: Please delete quotation marks at beginning and end" << endl;
						cout << endl;
						cout << "             " << endl;
						cin.ignore();
						getline(cin, newFilePath);
						FIO.changeFilePath(newFilePath);
					}
					else
					{
						FIO.changeFilePath("BillB100.txt");
					}

					cout << "////////////////////////////////////////////////////////" << endl << endl;
					cout << "Opening file" << endl;

					FIO.readFromFile(songTree, songHash);
		
					cout << "Closing file" << endl;
					cout << "Operation Successful" << endl;
					cout << endl;
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					goto mainMenu;
	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 2: // CASE 2 SAVES THE SORTED SONG TREE INTO A TEXT FILE
	{
		cout << "////////////////////////////////////////////////////////" << endl << endl;
				status = songTree.isEmpty();
				if (status == true)
				{
					cout << "Error, Tree is empty" << endl << endl;
					cout << "////////////////////////////////////////////////////////" << endl << endl;
				}
				else
				{
					cout << "Saving to BillBoard100.txt" << endl;
					songTree.saveInOrder();
				}
				goto mainMenu;
	}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 3:		// CASE 3 DISPLAYS THE SONG LIST TO THE SCREEN
	{
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					status = songTree.isEmpty();
					if (status == true)
					{
						cout << "    LIST IS EMPTY! There are no Songs to display" << endl << endl;
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						goto mainMenu;
					}
				dispSelect:
					cout << "How would you like to display the list?" << endl;
					cout << endl;
					cout << "   1) Hash Table Sequence   " << endl;
					cout << "   2) Key Sequence          " << endl;
					cout << "   3) Indented Tree         " << endl;
					cout << "   4) Return                " << endl;
					cout << endl;
					cout << "          ";

					cin >> menuSelect;
					cout << endl;
					cout << "////////////////////////////////////////////////////////" << endl << endl;


					switch (menuSelect)
					{
					case 1:
					{
						songHash.printall();
						cout << endl;
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						break;
					}

					case 2:
					{
						songTree.printInOrder();
						cout << endl;
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						break;
					}

					case 3:
					{
						songTree.print();
						cout << endl;
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						break;
					}

					case 4:
					{
						goto mainMenu;
						break;
					}
					default:
					{
						cout << "Invalid input, try again" << endl;
						break;
					}
					}

					goto dispSelect;
	}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 4:		// CASE 4 SEARCHES THE TREE TO SEE IF A SONG EXISTS 
	{
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					status = songTree.isEmpty();
					if (status == true)
					{
						cout << "LIST IS EMPTY! There are no Songs to search for" << endl << endl;
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						goto mainMenu;
					}
					cout << "                   Enter the TITLE of the Song" << endl;
					cout << "          ";

					cin.ignore();
					getline(cin, SongName);
					song = songHash.search(SongName);

					cout << "Title      :  " << song.returnTitle() << endl;
					cout << "Artist     :  " << song.returnArtist() << endl;
					cout << "Position   :  " << song.returnPosition() << endl;
					cout << "Last Week  :  " << song.returnLastWeek() << endl << endl;
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					goto mainMenu;

					//////////////////////////////////////////////////////////////////////////////////////////////////////////////
					//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 5:		// CASE 5 ADDS NEW SONGS TO THE TREE
	{

					int songCount;
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					cout << "How many Songs would you like to Add?" << endl;
					cout << "             ";
					cin >> songCount;
					for (int i = 0; i < songCount; i++)
					{
						song = song.createSong();
						songTree.insertBNode(song);
						songHash.add(song.returnTitle(), song);
					}
					cout << "Succssfully added!" << endl << endl;
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					goto mainMenu;
	}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 6:		// CASE 6 DELETES SONGS FROM THE TREE
	{
					cout << "////////////////////////////////////////////////////////" << endl << endl;
					status = songTree.isEmpty();
					if (status == true)
					{
						cout << "  LIST IS EMPTY! There are no Songs to Delete" << endl << endl;
						cout << "////////////////////////////////////////////////////////" << endl << endl;
						goto mainMenu;
					}
					cout << "   Enter the TITLE of the Song to Delete" << endl;
					cout << "          ";

					cin.ignore();
					getline(cin, SongName);
					song = songHash.search(SongName);
					string tempTitle = song.returnTitle();

					if (tempTitle == SongName)
					{
						cout << "Removing Song" << endl;
						songHash.remove(SongName);
						songTree.remove(song);
						cout << "Successfully Deleted." << endl;
						goto mainMenu;
					}
					else
					{
						cout << "That Song wasn't found." << endl;
						goto mainMenu;
					}
	}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 7:		// CASE 7 ENTERS THE USER INTO THE MUSIC PLAYER
	{

	songMenu:
		int songChoice;
		cout << endl << endl;
		//cout << "Grabbing a set of songs from the Billboard hot 100" << endl;
		cout << "________________________________________________________" << endl;
		cout << "////////////////////////////////////////////////////////" << endl;
		cout << "               LISTEN TO THE TOP 10 HITS                " << endl;
		cout << "________________________________________________________" << endl;
		cout << endl;
		cout << "    1)  Despacito                " << endl;
		cout << "    2)  I'm the One              " << endl;
		cout << "    3)  That's What I like       " << endl;
		cout << "    4)  Shape of you             " << endl;
		cout << "    5)  Humble                   " << endl;
		cout << "    6)  MASK Off                 " << endl;
		cout << "    7)  Something Just LIke This " << endl;
		cout << "    8)  Stay                     " << endl;
		cout << "    9)  Congratulations          " << endl;
		cout << "    10) XO TOUR LIF3             " << endl;
		cout << endl;
		cout << "    11) Return to Main Menu      " << endl;
		cout << endl << endl;



		cin >> songChoice;

		switch (songChoice)
		{
		case 1:
		{
		firstSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|           Despacito - Luis Fonsi           |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play Despacito.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto firstSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause Despacito.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume Despacito.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto firstSong;

				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause Despacito.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop Despacito.mp3", 0, 0, 0);
				goto secondSong;
			}



		}
		case 2:
		{
		secondSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|           I'm The One - DJ Khaled          |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play I'mtheOne.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto secondSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause I'mtheOne.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume I'mtheOne.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto secondSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause I'mtheOne.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop I'mtheOne.mp3", 0, 0, 0);
				goto thirdSong;
			}

		}
		case 3:
		{
		thirdSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|       That's What I Like - Bruno Mars      |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play That'swhatilike.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto thirdSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause That'swhatilike.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume That'swhatilike.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto thirdSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause That'swhatilike.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop That'swhatilike.mp3", 0, 0, 0);
				goto fourthSong;
			}
		}
		case 4:
		{
		fourthSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|          Shape of You - Ed Sheeran         |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play ShapeOfYou.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto fourthSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause ShapeOfYou.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume ShapeOfYou.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto fourthSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause ShapeOfYou.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("pause ShapeOfYou.mp3", 0, 0, 0);
				goto fifthSong;
			}
		}
		case 5:
		{
		fifthSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|           Humble - Kendrick Lamar          |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play Humble.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto fifthSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause Humble.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume Humble.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto fifthSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause Humble.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop Humble.mp3", 0, 0, 0);
				goto sixthSong;
			}
		}
		case 6:
		{
		sixthSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|              Mask Off - Future             |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play MaskOff.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto sixthSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause MaskOff.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume MaskOff.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto sixthSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause MaskOff.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop MaskOff.mp3", 0, 0, 0);
				goto seventhSong;
			}
		}
		case 7:
		{

		seventhSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|  Something Just Like This - Chainsmokers   |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play SomethingJustLikeThis.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto seventhSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause SomethingJustLikeThis.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume SomethingJustLikeThis.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto seventhSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause SomethingJustLikeThis.mp3", 0, 0, 0);
				goto songMenu;
			}
			else if (action == 3)
			{
				mciSendString("stop SomethingJustLikeThis.mp3", 0, 0, 0);
				goto eigthSong;

			}
		}
		case 8:
		{
		eigthSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|                 Stay - Zedd                |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play Stay.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto eigthSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause Stay.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume Stay.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto eigthSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause Stay.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop Stay.mp3", 0, 0, 0);
				goto ninthSong;
			}

		}
		case 9:
		{
		ninthSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|        Congratulations - Post Malone       |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play Congratulations.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "	3.Skip To Next Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 3)
			{
				cout << "Invalid " << endl;
				goto ninthSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause Congratulations.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume Congratulations.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto ninthSong;
				}
				else
				{
					goto songMenu;
				}
			}
			else if (action == 2)
			{
				mciSendString("pause Congratulations.mp3", 0, 0, 0);
				goto songMenu;
			}
			else
			{
				mciSendString("stop Congratulations.mp3", 0, 0, 0);
				goto tenthSong;
			}
		}
		case 10:
		{
		tenthSong:
			int action;
			cout << " ____________________________________________" << endl;
			cout << "|Playing:                                    |" << endl;
			cout << "|                                            |" << endl;
			cout << "|         XO TOUR Lif3 - Lil Uzi Vert        |" << endl;
			cout << "|                                            |" << endl;
			cout << "|____________________________________________|" << endl;
			cout << endl;
			mciSendString("play XoTourLif3.mp3", 0, 0, 0);
			cout << "	1.Pause." << endl;
			cout << "	2.Choose Another Song" << endl;
			cout << "              ";
			cin >> action;
			cout << endl;

			if (cin.fail() || action < 0 || action > 2)
			{
				cout << "Invalid " << endl;
				goto tenthSong;
			}

			if (action == 1)
			{
				int shift1;
				mciSendString("pause XoTourLif3.mp3", 0, 0, 0);
				cout << endl;
				cout << "You can resume or go to the song menu" << endl;
				cout << "1. RESUME" << endl;
				cout << "2. Menu" << endl;
				cout << endl;

				cin >> shift1;
				//input validation
				if (shift1 == 1)
				{
					mciSendString("resume XoTourLif3.mp3", 0, 0, 0);
					cout << "Returning to song menu" << endl;
					cout << endl;
					goto tenthSong;
				}
				else
				{
					goto songMenu;
				}
			}
			if (action == 2)
			{
				mciSendString("pause XoTourLif3.mp3", 0, 0, 0);
				goto songMenu;
			}
		}
		case 11:
		{
			goto mainMenu;
		}
		}

	}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 8:		// CASE 8 ENTERS THE USER INTO THE EFFICENCY CALCULATOR
	{
					cout << endl;
					cout << "Hash Table efficency for this run of the program:" << endl;
					cout << "__________________________________________________" << endl;
					cout << "there were " << songHash.searches << " searches done, and they took " << songHash.searchE << " operations."<<endl;
					cout << "there were " << songHash.additions << " additions done, and they took " << songHash.addE << " operations."<<endl;
					cout << "there were " << songHash.searches << " searches done, and they took " << songHash.searchE << " operations."<<endl;
					cout << "there were " << songHash.collisions << " collisions." << endl;
					cout << songHash.numPreMod << " of the collisions would not be removed by changing The current prime." << endl << endl;
					
					cout << "BST efficency for this run of the program:" << endl;
					cout << "__________________________________________________" << endl;
					cout << "there were " << songTree.searches << " searches done, and they took " << songTree.searchE << " operations." << endl;
					cout << "there were " << songTree.additions << " additions done, and they took " << songTree.addE << " operations." << endl;
					cout << "there were " << songTree.searches << " searches done, and they took " << songTree.searchE << " operations." << endl;
					cout << endl << endl;
					cout << "//////////////////////////////////////////////////////" << endl << endl;
					goto mainMenu;
	}



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	case 9:		// CASE 9 QUITS THE PROGRAM
	{
					cout << "////////////////////////////////////////////////////////" << endl;
					char quit;
					cout << "Are you sure you want to Quit? (Y/N)" << endl;
					cout << "             ";
					cin >> quit;

					if (quit == 'Y' || quit == 'y')
					{
						songTree.saveInOrder();
						exit(0);
					}
					else if (quit == 'N' || quit == 'n')
					{
						cout << endl;
						goto mainMenu;
					}
	}

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	default:	// DEFAULT CASE PROVIDES INPUT VALIDATION
	{
					cout << "////////////////////////////////////////////////////////" << endl;
					cin.ignore();
					cout << "Invalid Selection. Try again" << endl;
					goto getInput;
	}
	}

		return 0;
	}
}
