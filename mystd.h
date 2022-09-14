#ifndef BANNIKOV_V_MYSTRING_MYSTD_H
#define BANNIKOV_V_MYSTRING_MYSTD_H
#include <cstring>
#include <algorithm>

namespace mystd{

    class MyString{
    protected:
        char *str = nullptr; //c_str
        size_t sz = 0; //size
        size_t capacity = 0;

        void fillFields(size_t sz_, size_t capacity_);

    public:

        MyString() = default; //default constructor

        MyString(size_t sz, char ch); //init class with sz of characters

        MyString(const char sen[], size_t len); //init class with count characters of  “char string”

        explicit MyString(const char sen[]);

        MyString(const MyString& s); //copy constructor

        MyString(MyString&& s) noexcept;// move constructor

        MyString(const std::initializer_list<char>& lst); //initializer list constructor

        explicit MyString(size_t sz); //init class with sz of '\0'

        ~MyString(); //destructor

        MyString& operator=(const MyString& s); //copy assignment

        MyString& operator=(MyString&& s); //move assigment

        void swap(MyString& s); // swap function for copy-and-swap idiom

    };
}

#endif
