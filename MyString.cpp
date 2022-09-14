#include "mystd.h"

void mystd::MyString::
fillFields(size_t sz_, size_t capacity_) {
    this->sz = sz_;
    this->capacity = capacity_;
    this->str = new char[capacity];
}

mystd::MyString::
MyString(size_t sz, char ch){
    fillFields(sz, sz + 1);
    memset(str, ch, sz);
}

mystd::MyString::
MyString(const MyString& s){
    fillFields(s.sz, s.capacity);
    memcpy(str,s.str,capacity);
}

mystd::MyString::
MyString(const char sen[], size_t len){
    size_t minSize = std::min(strlen(sen), len);
    fillFields(minSize, minSize + 1);
    memcpy(str, sen, sz);
}

mystd::MyString::
MyString(const char sen[]):
        MyString(sen, strlen(sen)){}

mystd::MyString::
MyString(const std::initializer_list<char>& lst) {
    fillFields(lst.size(), lst.size() + 1);
    std::copy(lst.begin(), lst.end(), str);
}

mystd::MyString::
MyString(size_t sz): MyString(sz, '\0'){}

mystd::MyString::
~MyString(){
    delete[] str;
}

mystd::MyString &mystd::MyString::
operator=(const mystd::MyString &s) {
    if(this == &s) return *this;
    MyString copy_s(s);
    swap(copy_s);
    return *this;
}

void mystd::MyString::
swap(MyString& s){
    std::swap(str, s.str);
    std::swap(sz,s.sz);
    std::swap(capacity, s.capacity);
}
