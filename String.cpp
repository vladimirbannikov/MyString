#include "mystd.h"

mystd::MyString::
MyString(size_t sz, char ch):sz(sz){
    str = new char[sz];
    memset(str, ch, sz);
}

mystd::MyString::
MyString(const MyString& s):sz(s.sz){
    str = new char[sz];
    memcpy(str,s.str,sz);
}

mystd::MyString::
MyString(const std::initializer_list<char>& lst){
    sz = lst.size();
    str = new char[sz];
    std::copy(lst.begin(), lst.end(), str);
}

mystd::MyString::
MyString(size_t sz){
    this->sz = sz;
    str = new char[sz];
    memset(str, '\0', sz);
}

mystd::MyString::
~MyString(){
    delete[] str;
}

mystd::MyString &mystd::MyString::
operator=(const mystd::MyString &s) {
    if(this == &s) return *this;
    MyString copy_s = s;
    swap(copy_s);
    return *this;
}

void mystd::MyString::
swap(MyString& s){
    std::swap(str, s.str);
    std::swap(sz,s.sz);
}
