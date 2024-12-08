#pragma once
#include "String.h"
#include "iostream"
using namespace std;
class MyString
{
public:
	int len(const std::string &string);
	string substr(const string& string, int start, int len);
	bool equal(const string&, const string&);
	bool smaller(const string&, const string&);
};

