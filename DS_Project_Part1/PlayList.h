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
	PlayList() : name(""), music(LinkedList<Music>()) , Id(-1){}

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
	void quickSort(Node<Music>*, Node<Music>*);
	Node<Music>* partition(Node<Music>*, Node<Music>*);
	void swap(Node<Music>*, Node<Music>*);
 };

