#ifndef BANNIKOV_V_MYSTRING_MYSTD_H
#define BANNIKOV_V_MYSTRING_MYSTD_H
#include <cstring>
#include <algorithm>
#include <string>
#include <compare>
#include <ostream>
#include <istream>

namespace mystd{

    class MyString{
    protected:
        char *str = nullptr; //c_str (actually it's implemented with a list of chars)
        uint16_t sz = 0; //size
        uint16_t cap = 0;

        void fillFields(uint16_t sz_, uint16_t capacity_);

        char compareStr(const char *sen1, uint16_t sen1Size, const char *sen2, uint16_t sen2Size) const;

    public:

        MyString() = default; //default constructor

        MyString(uint16_t sz, char ch); //init class with sz of characters

        MyString(const char sen[], uint16_t len); //init class with count characters of  “char string”

        explicit MyString(const char sen[]);

        MyString(const MyString& s); //copy constructor

        explicit MyString(const std::string& s);

        MyString(MyString&& s) noexcept;// move constructor

        MyString(const std::initializer_list<char>& lst); //initializer list constructor

        explicit MyString(uint16_t sz); //init class with sz of '\0'

        ~MyString(); //destructor

        MyString& operator=(const MyString& s); //copy assignment

        MyString& operator=(const char sen[]);

        MyString& operator=(const std::string& s);

        MyString& operator=(char c);

        MyString& operator=(MyString&& s); //move assigment

        void swap(MyString& s); // swap function for copy-and-swap idiom

        MyString operator+(MyString& s);

        MyString operator+(const char sen[]);

        MyString operator+(const std::string& s);

        MyString& operator+=(const char sen[]);

        MyString& operator+=(MyString& s);

        MyString& operator+=(const std::string& s);

        char operator[](uint16_t index);

        bool operator==(const char sen[]) const;

        bool operator!=(const char sen[]) const;

        std::weak_ordering operator<=>(const char sen[]) const;

        bool operator==(const MyString &s) const;

        bool operator!=(const MyString &s) const;

        std::weak_ordering operator<=>(const MyString &s) const;

        uint16_t size() const;

        uint16_t length() const;

        const char* data() const; //переделать, чтобы избежать утечки памяти (можно добавить поле - char* tempBuff)

        const char* c_str() const;

        bool empty() const;

        uint16_t capacity() const;

        void shrink_to_fit();

        void clear();

        friend std::basic_ostream<char>& operator<<(std::basic_ostream<char>& out, const MyString& s);

        friend std::basic_istream<char>& operator>>(std::basic_istream<char>& in, MyString& s); //переделать
    };
}

#endif
