#pragma once
#include <iostream>
#include"LinkedList.h"
#include "Music.h"
using namespace std;
class Singer {
	static int GId;
	int Id;
	const string name;
	LinkedList<Music> music;
public:
	Singer(string _name) : name(_name){
		Id = ++GId;
	}
};