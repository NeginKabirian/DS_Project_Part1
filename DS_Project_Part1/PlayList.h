#pragma once
#include <iostream>
#include"LinkedList.h"
class PlayList
{
	static int GId;
	int Id;
	string name;
	LinkedList<Music> music;
public:
	PlayList(string _name = "", LinkedList<Music> _music = LinkedList<Music>()) : name(_name), music(_music) {
		Id = ++GId;
	}

	int getId() {
		return Id;
	}
	void printAllInfo() {
		cout << "PlayList : " << name << endl;
		cout << "music :" << endl;
		music.print();
	}
	void print() {
		music.print();
	}
 };

