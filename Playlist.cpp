#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Playlist.hpp"
using namespace std;

Playlist::Playlist() {
	list = new DLL();
	readList("MyListOfSongs.txt");
	list->printList();
	cout << endl;
	interface();
}

Playlist::Playlist(string s) {
	list = new DLL();

//	/*****************************************************************************************/
//	// (5 pts) Step 1:  list->push(title, artist, min, sec);
//	// Write the Push Method in your DLL.cpp.  The push method must include a case for
//	//creating the very first node in the list.
//	// It should take as input a string for the song's title, a string for the artist an int for
//	// the song's minutes in duration, and an int for the song's seconds in duration.  It
//	//returns nothing.
//	//To test, save and run your code.  If you get a message saying, Done Reading File,  it's
//	//possible your push method works, but you won't know for sure until you complete Step 2
//	//(Below)
//
	readList(s);  // uncomment this line to test the push method you wrote in the DLL.cpp file.
//
//
//
///*****************************************************************************************/
//	//( 6 pts) Step 2: list->printList();
//	// write the printList method in the DLL.cpp.  Th printList method should loop through
//	//all the nodes in your list and print out the content.
//	//Once you have finished writing printList, test it by uncommenting out the list->printlist()
//	//call, above.  Below is what your output should look like if you've done this successfully.
//
//	//You should get:
//	/* Let it Be, Beatles................3:11
//	Rock Around The Clock, Bill Haley................3:59
//	Don't Be Cruel, Elvis Presley ................4:43
//	Blueberry Hill, Fats Domino................4:58
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Black Magic Woman, Santana................3:16
//	La Bamba, Richie Valens ................3:29
//	Margaritaville, Jimmy Buffett................2:55
//	*/
	list->printList();  // uncomment out this line to test your printlist method.
//
	cout << endl;
///*****************************************************************************************/
//	// (5 pts) Step 3:  list->pop();
	//Write the method list->pop();  This method removes the last node from the list
//	// and returns the Song object (aka the data in the last node).
//	// NOTE:  THIS METHOD SHOULD NOT TRAVERSE THE ENTIRE LIST!!!!
//
//	//When written, uncomment out the code below.
	 list->pop();
	 list->printList();
	cout << endl;
	 list->pop();
	 list->printList();


//	// YOu should get:
//	/*Let it Be, Beatles................3:11
//	Rock Around The Clock, Bill Haley................3:59
//	Don't Be Cruel, Elvis Presley ................4:43
//	Blueberry Hill, Fats Domino................4:58
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Black Magic Woman, Santana................3:16
//	La Bamba, Richie Valens ................3:29
//
//	Let it Be, Beatles................3:11
//	Rock Around The Clock, Bill Haley................3:59
//	Don't Be Cruel, Elvis Presley ................4:43
//	Blueberry Hill, Fats Domino................4:58
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Black Magic Woman, Santana................3:16
//	*/
//
	cout << endl;
///*****************************************************************************************/
//	/*(10 pts) Step 4:  Write the method list->remove(title);
//	 * This Method goes through your list, finds a title, and removes that node from the list.  It
//	 * must work for the first node and the last node, as well as any node in  the list.
//	 * To Test:  Uncomment out the code below:
//	 *
//	 *
//	 *
//	 */
	list->remove("Don't Be Cruel");  // removes from middle of list
	cout << endl;
	list->printList();
	list->remove("Black Magic Woman");  // removes last
	cout << endl;
	list->printList();
	list->remove("Let it Be");  // removes first.
	cout << endl;
	list->printList();
//
//
//	/*  You should get:
//	 * Removing: Don't Be Cruel, Elvis Presley ................4:43
//
//	Let it Be, Beatles................3:11
//	Rock Around The Clock, Bill Haley................3:59
//	Blueberry Hill, Fats Domino................4:58
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Black Magic Woman, Santana................3:16
//
//	Removing: Black Magic Woman, Santana................3:16
//
//	Let it Be, Beatles................3:11
//	Rock Around The Clock, Bill Haley................3:59
//	Blueberry Hill, Fats Domino................4:58
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//
//	Removing: Let it Be, Beatles................3:11
//
//	Rock Around The Clock, Bill Haley................3:59
//	Blueberry Hill, Fats Domino................4:58
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	 */
//
//
///*****************************************************************************************/
//	/* Step 4.5:  Just uncomment the code below to add the songs back (albeit at the end)
//	 * After removing and popping, the list is getting a bit short
//	 */
//
	cout << endl;
	list->push("Don't Be Cruel", "Elvis Presley", 4,43);
	list->push("Black Magic Woman", "Santana", 3,16);
	list->push("Let it Be", "Beatles", 3, 11);
	list->printList();
//
//
//	/* Now the list should be:
//	 * Rock Around The Clock, Bill Haley................3:59
//		Blueberry Hill, Fats Domino................4:58
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Don't Be Cruel, Elvis Presley................4:43
//		Black Magic Woman, Santana................3:16
//		Let it Be, Beatles................3:11
//	 */
//
//
//
//
//
//
///*****************************************************************************************/
//	/* (10 pts)Step 5:  Write the method moveUp(title).  This method goes through the list, finds
//	 * the node with the title, and moves it up one place in the list.  If it is the first
//	 * song in the list, it moves it to the end of the list.
//	 * Once you have it written, uncomment out the code below:
//	 */
//
	//list->push("Great Balls of Fire", "Jerry Lee Lewis", 1, 07);
	cout << "Moving Great Balls of Fire  up one" << endl << endl;
	list->moveUp("Great Balls of Fire");
	list->printList();
	cout << "Moving Great Balls of Fire  up one" << endl << endl;
	list->moveUp("Great Balls of Fire");
	list->printList();
	cout << "Moving Great Balls of Fire  up one" << endl<< endl;
	list->moveUp("Great Balls of Fire");
	list->printList();
//
//
//	/* YOur output should be:
//	 * Moving Great Balls of Fire  up one
//
//	Rock Around The Clock, Bill Haley................3:59
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Blueberry Hill, Fats Domino................4:58
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Don't Be Cruel, Elvis Presley................4:43
//	Black Magic Woman, Santana................3:16
//	Let it Be, Beatles................3:11
//
//	Moving Great Balls of Fire  up one
//
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	Rock Around The Clock, Bill Haley................3:59
//	Blueberry Hill, Fats Domino................4:58
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Don't Be Cruel, Elvis Presley................4:43
//	Black Magic Woman, Santana................3:16
//	Let it Be, Beatles................3:11
//
//	Moving Great Balls of Fire  up one
//
//	Rock Around The Clock, Bill Haley................3:59
//	Blueberry Hill, Fats Domino................4:58
//	Jonny B Good, Chuck Berry................3:14
//	Bad Moon Rising, Credence Clearwater Revival................6:O9
//	Don't Be Cruel, Elvis Presley................4:43
//	Black Magic Woman, Santana................3:16
//	Let it Be, Beatles................3:11
//	Great Balls of Fire, Jerry Lee Lewis................1:O7
//	*/
//
//
//
//
//
//
//
//
//
//
//
//	/*****************************************************************************************/
//
//	/* (10 pts) Step 6:  Write the method moveDown(title).  This method goes through the list, finds
//	 * the node with the title, and moves it down one place in the list.  If it is the last
//	 * song in the list, it moves it to the front of the list.
//	 * Once you have it written, uncomment out the code below:
//	 */
//
	cout << "Moving Black Magic Woman  down one" << endl << endl;
	list->moveDown("Black Magic Woman");
	list->printList();
	cout << "Moving Black Magic Woman  down one" << endl << endl;
	list->moveDown("Black Magic Woman");
	list->printList();
	cout << "Moving Black Magic Woman  down one" << endl<< endl;
	list->moveDown("Black Magic Woman");
	list->printList();
//
//	/* YOur output should be:
//	 * Moving Black Magic Woman  down one
//
//		Rock Around The Clock, Bill Haley................3:59
//		Blueberry Hill, Fats Domino................4:58
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Don't Be Cruel, Elvis Presley................4:43
//		Let it Be, Beatles................3:11
//		Black Magic Woman, Santana................3:16
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//
//		Moving Black Magic Woman  down one
//
//		Rock Around The Clock, Bill Haley................3:59
//		Blueberry Hill, Fats Domino................4:58
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Don't Be Cruel, Elvis Presley................4:43
//		Let it Be, Beatles................3:11
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//		Black Magic Woman, Santana................3:16
//
//		Moving Black Magic Woman  down one
//
//		Black Magic Woman, Santana................3:16
//		Rock Around The Clock, Bill Haley................3:59
//		Blueberry Hill, Fats Domino................4:58
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Don't Be Cruel, Elvis Presley................4:43
//		Let it Be, Beatles................3:11
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//	 *
//	 */
//
//
//
//
//
//
//
///*****************************************************************************************/
//
//	/* (7 pts) Step 7:  Write the method listDuration(int *tm, int *ts)
//	 * Note that this method takes as input two pointers to integers.  It is using call by
//	 * pointer (largely so you get to practice call by pointer).  The method sums the minutes
//	 * and the seconds of each song in the playlist to determine the total number of minutes and
//	 * seconds.  It retursn nothing (void) but the input parameters are modified to hold these
//	 * totals.
//	 *
//	 * Once you have it written, uncomment out the code below:
//	 */
//
//
	list->printList();
	int mintot = 0;
	int sectot = 0;
	list->listDuration(&mintot, &sectot);
	mintot += sectot/60;
	sectot = sectot%60;
	int hr = 0;
	if (mintot>=60) {
		hr = mintot/60;
		mintot %= 60;
	}
	cout << "The total playlist time is ";
	hr>0?cout<<hr<<":":cout<<" ";
	cout<< mintot<<":";
	sectot<10?cout<<"0"<<sectot:cout<<sectot;
	cout << endl<<flush;
//
//
//
//	/* YOur output should be:
//	 *
//	 * Black Magic Woman, Santana................3:16
//		Rock Around The Clock, Bill Haley................3:59
//		Blueberry Hill, Fats Domino................4:58
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Don't Be Cruel, Elvis Presley................4:43
//		Let it Be, Beatles................3:11
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//
//		The total playlist time is  30:37
//	 *
//	 */
//
//
//
//
//
//
///*****************************************************************************************/
//
//	/* (20 pts) Step 8:  Write the method makeRandom()
//	 * There are many, many ways to write this method, and each is fine (unless it doesn't result
//	 * in a random list.
//	 * The method should randomly rearrange your play list so that the nodes are reordered in a new,
//	 * random order.
//	 *
//	 * Once you have it written, uncomment out the code below:
//	 */
//
//

	list->makeRandom();
	list->printList();
	cout << "***************" << endl;
	list->makeRandom();
	list->printList();
//
//
//
//	/* YOur output might be something like this (note - yours will be different because it's RANDOM!):
//	 *
//		Let it Be, Beatles................3:11
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//		Blueberry Hill, Fats Domino................4:58
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Black Magic Woman, Santana................3:16
//		Rock Around The Clock, Bill Haley................3:59
//		Don't Be Cruel, Elvis Presley................4:43
//
//		***************
//		Black Magic Woman, Santana................3:16
//		Don't Be Cruel, Elvis Presley................4:43
//		Blueberry Hill, Fats Domino................4:58
//		Let it Be, Beatles................3:11
//		Rock Around The Clock, Bill Haley................3:59
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//		Jonny B Good, Chuck Berry................3:14
//
//	 *
//	 */
//
//
//
//
//
//
///*****************************************************************************************/
//
//	/* (7 pts) Step 9:  Write the destructor for the list.  This should remove all the nodes in the list
//	 * from the heap.  This will allow us to create a new list.
//	 * Note: the results of this are that your program doesn't crash - there really isn't any
//	 * see-able output from this.
//	 *
//	 *
//	 * Once you have it written, uncomment out the code below:
//	 */
//
//
//
//	/* your output should be...
//	 * Yep, deleted
//	 */
//
//
///*****************************************************************************************/
//
//	/* Step 9.5:  Uncomment out the code below to read in a new, longer list
//	 */
//
	list = new DLL();
	readList("MyListOfSongs.txt");
	list->printList();
	cout << endl;
//
//
//	/* If successful, you should get this:
//	 * *********DONE READING**************************
//
//		Let it Be, Beatles................3:11
//		Rock Around The Clock, Bill Haley................3:59
//		Don't Be Cruel, Elvis Presley................4:43
//		Blueberry Hill, Fats Domino................4:58
//		Great Balls of Fire, Jerry Lee Lewis................1:O7
//		Jonny B Good, Chuck Berry................3:14
//		Bad Moon Rising, Credence Clearwater Revival................6:O9
//		Black Magic Woman, Santana................3:16
//		La Bamba, Richie Valens................3:29
//		Margaritaville, Jimmy Buffett................2:55
//		Reaper, Sia................3:39
//		Good Life, OneRepublic................4:13
//		I Can't Wait, Nu Shooz................5:26
//		The King of Wishful Thinking, Go West................4:O1
//		i, Kendrick Lamar................3:52
//		I Wanna Get Better, Bleachers................3:24
//		Be Fine, Madeon................3:28
//		Ain't No Easy Way, Black Rebel Motorcycle Club................2:36
//		Antisocial, Ed Sheeran and Travis Scott................2:41
//		Gossip Folks, Missy Elliot and Ludacris................3:54
//		Purple Hat, Sofi Tukker................2:58
//		99, Barns Courtney................3:19
//		Born To Be Yours, Vibe2Vibe................3:14
//		Send Me on My Way, Rusted Root................4:23
//		Dreams, The Cranberries................4:31
//		This Old Heart of Mine, The Isley Brothers................2:55
//		Sing It Out Loud, OMI................3:41
//		Punching in a Dream, The Naked And Famous................3:58
//		Harder To Breather, Maroon 5................2:52
//		Where the Rivers Flow, Sons of Maria................3:O3
//		Still Not a Player, Big Pun Joe................3:56
//		Train, Brick+Mortar................3:O5
//		17, Zhavia Ward................2:46
//		Critical Mistakes, 888................3:20
//		Good News, K.Flay................3:31
//		Love is Alive, Louis The Child and Elohim................2:50
//	 */
//
//
///*****************************************************************************************/
//
//	/* (15 pts) Step 10:  Uncomment out the code below to play with the interface.
//	 * Make sure you:
//	 * 1) add at least 2 songs (and print the list after each add)
//	 * 2) remove at least 2 songs (and print the list after each remove)
//	 * 3) Move up at least twice (and print)
//	 * 4) Move down at least twice (and print)
//	 * 5) Randomize twice (and print)
//	 * 6) find the lists duration
//	 * 7) play around, if you want :-)
//	 *
//	 *
//	*/
//
//
	interface();
//
//
//	/* Your output should go here */



}

void Playlist::interface() {
	int choice=0;
	while (choice != 8) {
		cout << "What do you want to do?" <<endl<< flush;
		cout <<"Enter:" << endl<< flush;
		cout <<"\t1 for adding song"<<endl<< flush;
		cout <<"\t2 for removing a song" << endl<< flush;
		cout <<"\t3 for moving a song up in the list" << endl<< flush;
		cout <<"\t4 for moving a song down in the list" << endl<< flush;
		cout <<"\t5 for randomly shuffling the list" << endl<< flush;
		cout <<"\t6 for creating a brand new list" <<endl<< flush;
		cout <<"\t7 for getting the playlist's time duration"<< endl<<flush;
		cout <<"\t8 for exit" <<endl<< flush;

		cin >> choice;
		if (choice ==1) {
			addSong();
		}
		else if (choice == 2) {
			removeSong();
		}
		else if (choice == 3) {
			moveUp();
		}
		else if (choice == 4) {
			moveDown();
		}
		else if (choice ==5) {
			list->makeRandom();
			list->printList();
		}

		else if (choice ==6){
			makeNewList();
		}

		else if (choice ==7){
			getDuration();
		}
		else if (choice == 8) {
			ByeNow();
		}
	}
}

void Playlist::makeNewList() {
	cout << "Enter the name of the list you wish to enter:" <<endl << flush;
	string newlist = getTitle();
	delete list;
	list = new DLL();
	readList(newlist);
	list->printList();
}

void Playlist::getDuration() {
	int mintot = 0;
	int sectot = 0;
	list->listDuration(&mintot, &sectot);
	mintot += sectot/60;
	sectot = sectot%60;
	int hr = 0;
	if (mintot>=60) {
		hr = mintot/60;
		mintot %= 60;
	}
	cout << "The total playlist time is ";
	hr>0?cout<<hr<<":":cout<<" ";
	cout<< mintot<<":";
	sectot<10?cout<<"0"<<sectot:cout<<sectot;
	cout << endl<<flush;
	return;
}


void Playlist::moveUp() {
	cout<<"Moving a Song Up:" <<endl;
	cout << "Enter the title of the song you wish to move up in the list:" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->moveUp(title);
		list->printList();
	}
}
string Playlist::getTitle() {
	string song = "";
	while (song == "") {
	    getline(cin, song);
	}
	string title;
	title = strip(song);
	return title;

}
void Playlist::moveDown() {
	cout<<"Moving a Song Down:" <<endl;
	cout << "Enter the title of the song you wish to move down in the list:" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->moveDown(title);
		list->printList();
	}
}
void Playlist::removeSong() {
	cout<<"Removing a song:" <<endl;
	cout << "Enter the title of the song you wish to remove" <<endl << flush;
	string title = getTitle();

	if (title.length() >0) {
		list->remove(title);
		list->printList();
	}
}

void Playlist::addSong() {
	cout<<"Adding a song:" <<endl;
	cout << "Enter the song's info as follows: title, artist(s), min:sec" <<endl << flush;
	string song = "";
    while (song == "") {
    	getline(cin, song);
    }
	string artist;
	string title;
	string mins;
	string secs;
	title = strip(song);
	artist = strip(song);
	mins = strip(song);
	stringstream tmp(mins);
	int min = 0;
	tmp>>min;
	secs = song;
	stringstream tmp2(secs);
	int sec = 0;
	tmp2>>sec;
		//cout << title<<":::"<<artist<<":::"<<mins<<":::"<<secs<<":::"<<endl;
	if (title.length() >0) {
		list->push(title, artist, min, sec);
		list->printList();
	}

}
void Playlist::ByeNow() {
	cout << "Bye Now!" << endl;
	return;
}

string Playlist::strip(string &s) {
	const char* WhiteSpace = " \t\v\r\n";
	size_t start = s.find_first_not_of(WhiteSpace);
	const char* EndChar = ":,\n";
	size_t end = s.find_first_of(EndChar);
	string s2;
	int len = s.length();
	if (start<end){
		s2=s.substr(start,end-start);
		s = s.substr(end+1,len-end+1);
	}
	return s2;

}
void Playlist::readList(string f) {
	ifstream file(f.c_str());
	string songstr;
	string artist;
	string title;
	string mins;
	string secs;
	while (!file.eof()) {
		getline(file,songstr);
		//cout << songstr<<endl;
		title = strip(songstr);
		artist = strip(songstr);
		mins = strip(songstr);
		stringstream tmp(mins);
		int min = 0;
		tmp>>min;
		secs = songstr;
		stringstream tmp2(secs);
		int sec = 0;
		tmp2>>sec;
		//cout << title<<":::"<<artist<<":::"<<mins<<":::"<<secs<<":::"<<endl;
		if (title.length() >0) {
			list->push(title, artist, min, sec);
		}
	}
	cout <<"*********DONE READING**************************"<<endl<<endl;
	return;
}



