
#include "DNode.hpp"
#include "DLL.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

//Check Playlist.cpp for instructions of what to write here and how to test it


	DLL::DLL(){  // constructor - initializes an empty list
		last = NULL;
		first = NULL;
		numSongs = 0;
	}
	DLL::DLL(string t, string l, int m, int s){  // constructor, initializes a list with one new node with data x
		DNode *n = new DNode (t,l,m,s);
		first = n;
		last = NULL;
		first->next = last;
		numSongs = 1;
	}
	void DLL::push(string n, string a, int m, int s) {  // does what you'd think
            DNode *newSong = new DNode(n,a,m,s);
            if(first==NULL){
            	first = newSong;
            	last = newSong;
            	first->prev = NULL;
            	last -> next = NULL;
			}else {
				DNode *temporary = first;
				while(temporary->next != NULL) {
					temporary = temporary->next;
				}
				temporary->next = newSong;
				last = newSong;
				last->prev = temporary;
				newSong->next = NULL;
			}
			numSongs++;
    }


	Song *DLL::pop() {
		//does what you'd think
		DNode *temporary = last;
		Song *info = temporary->song;
		last = last->prev;
		delete temporary;
		last->next = NULL;
		numSongs--;
		return info;
	}

	void DLL::printList() {
		DNode *temporary = first;
		while(temporary != NULL) {
			temporary->song->printSong();
			temporary = temporary->next;
		}
	}

	void DLL::moveUp(string s) {
		DNode *current = first;
		while(current != NULL) {
			if(current -> song -> title == s) {
				break;
			}
			current = current->next;
		}
		if(current == first) {
			first = current->next;
			first->prev = NULL;
			last->next = current;
			current->prev = last;
			current->next = NULL;
			last = current;
		}else if(current->next == NULL){
			DNode *swap = current -> prev;
			DNode *previous = current->prev-> prev;
			current->prev = previous;
			current->next = swap;
			swap->next = NULL;
			swap->prev = current;
			previous->next = current;
		}else if(current->prev == first){
			DNode *swap = current -> prev;
			DNode *next2 = current -> next;
			current->prev = NULL;
			current->next = swap;
			swap->next = next2;
			swap->prev = current;
			next2->prev = swap;
			first = current;
		}else{
			DNode *swap = current -> prev;
			DNode *previous = current->prev-> prev;
			DNode *next1 = current -> next;
			current->prev = previous;
			current->next = swap;
			swap->next = next1;
			swap->prev = current;
			previous->next = current;
			next1->prev = swap;
		}
	}

	void DLL::listDuration(int *tm, int *ts) {
		DNode *current = first;
		while(current != NULL) {
			*tm += current->song->min;
			*ts += current->song->sec;
			current = current->next;
		}
	}

	void DLL::moveDown(string s) {
		DNode *current = first;
		while(current != NULL) {
			if(current -> song -> title == s) {
				break;
			}
			current = current->next;
		}
		if(current == first) {
			DNode *swap = current ->next;
			DNode *next1 = current->next->next;
			first = swap;
			swap->prev = NULL;
			swap->next = current;
			current->prev = swap;
			current->next = next1;
			next1->prev = current;
		}else if(current == last){
			last = current->prev;
			last->next = NULL;
			first->prev = current;
			current->next = first;
			current->prev = NULL;
			first = current;
		}else if(current->next == last){
			DNode *swap = current -> next;
			DNode *previous = current -> prev;
			current->next = NULL;
			current->prev = swap;
			swap->next = current;
			swap->prev = previous;
			previous->next = swap;
			last = current;
		}else{
			DNode *swap = current -> next;
			DNode *previous = current->prev;
			DNode *next1 = current -> next -> next;
			current->prev = swap;
			current->next = next1;
			swap->next = current;
			swap->prev = previous;
			previous->next = swap;
			next1->prev = current;
		}
	}

	void DLL::makeRandom() {
		srand(time(NULL));
		int y = numSongs - 1;
		int random;
		for(int i = 0;i<y;i++) {
			random = rand()%y;
			DNode *current = removeRand(random);
			push(current->song->title, current->song->artist, current->song->min, current->song->sec);
		}
	}

	DNode* DLL::removeRand(int x) {
		DNode *current = first;
		while(current != NULL && x>0) {
			current = current->next;
			x--;
		}
		if(current == first) {
			first = current -> next;
			first->prev = NULL;
		}else if(current == last) {
			last = current->prev;
			last->next = NULL;
		}else {
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		//current = current->next; //is this doing anything?
		numSongs--;
		return current;
	}

	int DLL::remove(string s) {  
// note that the int returned is the index - this is standard for a remove, but we won't be using it.
		DNode *current = first;
		int index = 0;
		while(current != NULL) {
			if (current -> song -> title == s) {
				cout << "Removing " << s << endl;
				if(current == first) {
					first = current -> next;
					first->prev = NULL;
				}else if(current == last) {
					last = current->prev;
					last->next = NULL;
				}else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				current = current->next;
				numSongs--;
			}else {
				current = current -> next;
				index ++;
			}
		}
		return index;
		}


	DLL::~DLL(){
		DNode *current = first;
		while(current != NULL) {
			DNode *next = current -> next;
			delete current;
			current = next;
		}
		first = NULL;
		last = NULL;
	}
