#pragma once
#include "String.h"
#include "iostream"
using namespace std;
class MyString
{
public:
	int len(const std::string &string);
	string substr(const string& string, int start, int len);
};

