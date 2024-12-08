#pragma once
#include <iostream>
#include"LinkedList.h"
#include "Music.h"
using namespace std;
class Singer {
	static int GId;
	int Id;
	string name;
	LinkedList<Music> music;
public:
	Singer(string _name) : name(_name),music(LinkedList<Music>()){
		Id = ++GId;
	}
	Singer() : name(""), music(LinkedList<Music>()) {}
	int getId() {
		return Id;
	}
	LinkedList<Music>& getMusic() {
		return music;
	}
	void printAllInfo() {
		cout << "Singer : " << name<<endl;
		cout << "music :"<<endl;
		music.print();
	}
	void print() {
		music.print();
	}
};