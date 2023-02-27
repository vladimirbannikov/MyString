#ifndef BANNIKOV_V_MYSTRING_MYSTD_H
#define BANNIKOV_V_MYSTRING_MYSTD_H
#include <cstring>
#include <algorithm>
#include <string>
#include <compare>
#include <ostream>
#include <istream>
#include <memory>

namespace mystd{

    class MyString{
    protected:
        char *str = nullptr; //c_str
        size_t sz = 0; //size
        size_t cap = 0; //capacity

        void fillFields(size_t sz_, size_t capacity_);

        char compareStr(const char *sen1, size_t sen1Size, const char *sen2, size_t sen2Size) const;

        void swap(MyString& s); 

    public:

        MyString() = default; 

        MyString(size_t sz, char ch); 

        MyString(const char sen[], size_t len); 

        explicit MyString(const char sen[]);

        MyString(const MyString& s); 

        explicit MyString(const std::string& s);

        MyString(MyString&& s) noexcept;

        MyString(const std::initializer_list<char>& lst); 

        explicit MyString(size_t sz); 

        ~MyString(); 

        MyString& operator=(const MyString& s); 

        MyString& operator=(const char sen[]);

        MyString& operator=(const std::string& s);

        MyString& operator=(char c);

        MyString& operator=(MyString&& s); 

        MyString operator+(MyString& s);

        MyString operator+(const char sen[]);

        MyString operator+(const std::string& s);

        MyString& operator+=(const char sen[]);

        MyString& operator+=(MyString& s);

        MyString& operator+=(const std::string& s);

        char operator[](size_t index);

        bool operator==(const char sen[]) const;

        bool operator!=(const char sen[]) const;

        std::weak_ordering operator<=>(const char sen[]) const;

        bool operator==(const MyString &s) const;

        bool operator!=(const MyString &s) const;

        std::weak_ordering operator<=>(const MyString &s) const; 

        size_t size() const;

        size_t length() const;

        const char* data() const; 

        const char* c_str() const;

        bool empty() const;

        size_t capacity() const;

        void shrink_to_fit();

        void clear();

        friend std::basic_ostream<char>& operator<<(std::basic_ostream<char>& out, const MyString& s);

        friend std::basic_istream<char>& operator>>(std::basic_istream<char>& in, MyString& s); 

        int insert(size_t index, size_t count, char c);

        int insert(size_t index, const char sen[]);

        int insert(size_t index, const char sen[], size_t count);

        int insert(size_t index, const std::string& s);

        int insert(size_t index, const std::string& s, size_t count);

        int erase(size_t index, size_t count);

        int append(const char sen[], size_t index, size_t count);

        int append(const char sen[]);

        int append(size_t count, char c);

        int append(const std::string& s);

        int append(const std::string& s, size_t index, size_t count);

        int replace(size_t index, size_t count, const char sen[]);

        int replace(size_t index, size_t count, const std::string& s);

        const char* substr(size_t index, size_t count);

        const char* substr(size_t index);

        size_t find(const char sen[], size_t index);

        size_t find(const char sen[]);

        size_t find(const std::string& s, size_t index);

        size_t find(const std::string& s);
    };
}

#endif
