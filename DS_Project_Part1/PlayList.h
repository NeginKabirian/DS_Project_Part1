#pragma once
#include <iostream>
#include"LinkedList.h"
class PlayList
{
	static int GId;
	int Id;
	const string name;
	LinkedList<Music> music;
};

