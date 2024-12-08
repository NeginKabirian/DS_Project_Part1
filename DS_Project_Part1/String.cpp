#include "String.h"

int MyString::len(const std::string &str)
{
    int size = 0;
    for (auto i = str.begin(); i != str.end() ; ++i) {
        size++;
    }
    return size;
}

string MyString::substr(const string& str, int start, int len)
{
    string newStr;
     int size =  this->len(str);
    if (start < 0 || start >= size){
        return ""; 
    }
    if (len == -1 || start + len > size) {
        len = size - start;
    }
    for (int i = 0; i < len; ++i) {
        newStr += str[start + i];
    }
    return newStr;
}

bool MyString::equal(const string& sA, const string& sB)
{
    if (len(sA) != len(sB)) {
        return false;
    }
    auto j = sB.begin();
    auto i = sA.begin();
    while (i != sA.end() && j != sB.end()) {
        if ( *i != *j) {
            return false;
            }
        i++;
        j++;
   }
    return true;
}

bool MyString::smaller(const string& sA, const string& sB)
{
    auto j = sB.begin();
    auto i = sA.begin();
    while (i != sA.end() && j != sB.end()) {

       if (*i < *j) {
            return true;
        }
        else if(*i > *j){
                return false;
        }
       i++;
       j++;
    }
    return len(sA) < len(sB);
}
