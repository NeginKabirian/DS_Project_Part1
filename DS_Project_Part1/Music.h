#pragma once
#include <iostream>
using namespace std;
class Music {
private:
	static int Id;
	const string name;
	int year;
	string lyrics;
public:
	Music(string _name ,int _year ,string lyrics) : name(_name) , year(year) , lyrics(lyrics){}
};