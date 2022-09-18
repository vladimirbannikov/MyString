#include "mystd.h"

void mystd::MyString::
fillFields(uint16_t sz_, uint16_t capacity_) {
    this->sz = sz_;
    this->cap = capacity_;
    this->str = new char[cap];
}

mystd::MyString::
MyString(uint16_t sz, char ch){
    fillFields(sz, sz + 1);
    memset(str, ch, sz);
}

mystd::MyString::
MyString(const MyString& s){
    fillFields(s.sz, s.cap);
    memcpy(str,s.str,cap);
}

mystd::MyString::
MyString(const char sen[], uint16_t len){
    uint16_t minSize = std::min((uint16_t)strlen(sen), len);
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
MyString(uint16_t sz): MyString(sz, '\0'){}

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
    std::swap(cap, s.cap);
}

mystd::MyString mystd::MyString::
operator+(const char *sen) {
    uint16_t senLength = strlen(sen);
    MyString copy_s;
    if(senLength + this->sz >= UINT16_MAX){
        copy_s.fillFields(UINT16_MAX - 1, UINT16_MAX);
        senLength = UINT16_MAX - this->sz - 1;
    }
    else copy_s.fillFields(senLength + this->sz, senLength + this->sz + 1);
    memcpy(copy_s.str, this->str, this->sz);
    memcpy(copy_s.str + this->sz, sen, senLength);
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
operator[](uint16_t index) { // there are no indexes less than 0 with type uint16_t
    if(index >= this->sz)
        return '\0';
    else return this->str[index];
}

char mystd::MyString::
compareStr(const char *sen1, uint16_t sen1Size, const char *sen2, uint16_t sen2Size) const {
    if(sen1Size > sen2Size) return 1;
    else if(sen1Size < sen2Size) return -1;
    else{
        for(uint16_t i = 0; i < sen1Size; i++){
            if(sen1[i] > sen2[i]) return 1;
            else if(sen1[i] < sen2[i]) return -1;
        }
    }
    return 0;
}

bool mystd::MyString::
operator==(const char *sen) const{
    char comparison = compareStr(this->str, this->sz, sen, strlen(sen));
    return comparison == 0;
}

bool mystd::MyString::
operator!=(const char *sen) const{
    return !(*this == sen);
}

std::weak_ordering mystd::MyString::
operator<=>(const char *sen) const {
    char comparison = compareStr(this->str, this->sz, sen, strlen(sen));
    if(comparison == 0) return std::weak_ordering::equivalent;
    return comparison > 0 ? std::weak_ordering::greater: std::weak_ordering::less;
}

bool mystd::MyString::
operator==(const mystd::MyString &s) const {
    return (*this == s.str);
}

bool mystd::MyString::
operator!=(const mystd::MyString &s) const {
    return (*this != s.str);
}

std::weak_ordering mystd::MyString::
operator<=>(const mystd::MyString &s) const {
    return (*this <=> s.str);
}

uint16_t mystd::MyString::size() const {
    return sz;
}

uint16_t mystd::MyString::length() const {
    return sz;
}

const char *mystd::MyString::c_str() const {
    return this->str;
}

const char* mystd::MyString::data() const {
    char* temp = new char[this->sz];
    memcpy(temp, this->str, sz);
    return temp;
}

bool mystd::MyString::empty() const {
    return sz == 0;
}

uint16_t mystd::MyString::capacity() const {
    return cap;
}

void mystd::MyString::shrink_to_fit() {
    cap = sz + 1;
    char temp[cap];
    memcpy(temp, str, sz);
    delete[] str;
    str = new char[cap];
    memcpy(str, temp, sz);
}

void mystd::MyString::clear() {
    delete[] str;
    str = nullptr;
    cap = 0;
    sz = 0;
}

std::basic_ostream<char> &mystd::
operator<<(std::basic_ostream<char> &out, const mystd::MyString &s) {
    out.write(s.str, s.sz);
    return out;
}

std::basic_istream<char>& mystd::
operator>>(std::basic_istream<char> &in, mystd::MyString &s) {
    delete[] s.str;
    s.str = new char[UINT16_MAX];
    in.getline(s.str, UINT16_MAX - 1, '\n');
    s.sz = strlen(s.str);
    s.shrink_to_fit();
    return in;
}



