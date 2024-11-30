#pragma once
#include <iostream>
using namespace std;
class Music {
private:
	int Id;
	static int GId;
	string name;
	int year;
	string lyrics;
public:
	Music(string _name, int _year, string _lyrics) : name(_name), year(_year), lyrics(_lyrics) {
		Id = ++GId;
	}
	string getLyrics() {
		return lyrics;
	}
	string getName() {
		return name;
	}
};
