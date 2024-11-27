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
	Singer(string _name) : name(_name){
		Id = ++GId;
	}
	Singer(const Singer& other) {
		Id = other.Id;
		name = other.name;
		
	}
	//Singer()
	int getId() {
		return Id;
	}
};