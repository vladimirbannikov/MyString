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
MyString(const std::string& s): MyString(s.c_str(), s.size()){}

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

mystd::MyString &mystd::MyString::
operator=(const char sen[]){
    MyString copy_s(sen);
    swap(copy_s);
    return *this;
}

mystd::MyString &mystd::MyString::
operator=(const std::string& s) {
    return (*this = s.c_str());
}

mystd::MyString &mystd::MyString::
operator=(char c) {
    char *cTemp = &c;
    return (*this = cTemp);
}

void mystd::MyString::
swap(MyString& s){
    std::swap(str, s.str);
    std::swap(sz,s.sz);
    std::swap(capacity, s.capacity);
}

mystd::MyString mystd::MyString::
operator+(const char *sen) {
    MyString copy_s(this->sz + strlen(sen));
    memcpy(copy_s.str, this->str, this->sz);
    memcpy(copy_s.str + this->sz, sen, strlen(sen));
    return copy_s;
}

mystd::MyString mystd::MyString::
operator+(MyString& s){
    return (*this + s.str);
}

mystd::MyString mystd::MyString::
operator+(const std::string& s){
    return (*this + s.c_str());
}

mystd::MyString &mystd::MyString::
operator+=(const char *sen) {
    MyString copy_s(this->sz + strlen(sen));
    memcpy(copy_s.str, this->str, this->sz);
    memcpy(copy_s.str + this->sz, sen, strlen(sen));
    swap(copy_s);
    return *this;
}

mystd::MyString &mystd::MyString::
operator+=(MyString& s){
    return (*this += s.str);
}

mystd::MyString &mystd::MyString::
operator+=(const std::string& s){
    return (*this += s.c_str());
}

char mystd::MyString::
operator[](size_t index) { // there are no indexes less than 0 with type size_t
    if(index >= this->sz)
        return '\0';
    else return this->str[index];
}
