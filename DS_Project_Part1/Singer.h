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
	/*Singer() : name(""), music() {
		Id = -1;
	}*/
	Singer(string _name="", LinkedList<Music> _music = LinkedList<Music>()) : name(_name), music(_music) {
		Id = ++GId;
	}
	/*Singer(string _name = " ") : name(_name){
		Id = ++GId;
	}*/
	/*Singer(const Singer& other) {
		Id = other.Id;
		name = other.name;
		GId = other.GId;
	}*/
	//Singer()
	int getId() {
		return Id;
	}
	void print() {
		music.print();
	}
};