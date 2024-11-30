#pragma once
#include <iostream>
using namespace std;
#include <string>
class Music {
private:
	int Id;
	static int GId;
	string name;
	int year;
	string lyrics;
	int* SuffixArray;
	char** substr;
	void mergeSort(int, int);
	void merge(int,int,int);
	bool strcomp(int ,int);
	int len(char*);
	/*~Music();*/
public:
	Music(string _name, int _year,string _lyrics) : name(_name), year(_year), lyrics(_lyrics) {
		Id = ++GId;
		SuffixArray = nullptr;
		substr = nullptr;
		build_SuffixArray();
	}
	string getLyrics()const {
		return lyrics;
	}
	string getName()const {
		return name;
	}
	void print()const {
		cout << endl;
		cout << "name : " << name << endl;
		cout << "year : " << year << endl;
		cout << "lyrics : " << lyrics << endl;
	}
	void build_SuffixArray();
};
