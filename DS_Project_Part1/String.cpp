#include "String.h"

int MyString::len(const std::string &str)
{
    int size = 0;
    for (auto i = str.begin(); i != str.end() ; ++i) {
        size++;
    }
    cout <<endl<< "size :" << size<<" ";
    return size;
}

string MyString::substr(const string& str, int start, int len)
{
    string newStr;
    
    if (start < 0 || start >= str.size()) {
        return ""; 
    }
    if (len == -1 || start + len > str.size()) {
        len = str.size() - start;
    }
    for (int i = 0; i < len; ++i) {
        newStr += str[start + i];
    }
    return newStr;
}
