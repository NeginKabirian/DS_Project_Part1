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
	PlayList(string _name) : name(_name), music(LinkedList<Music>()) {
		Id = GId++;
	}
	PlayList() : name(""), music(LinkedList<Music>()){}

	int getId() {
		return Id;
	}
	LinkedList<Music>& getMusic() {
		return music;
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

