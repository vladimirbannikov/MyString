#include <iostream>
#include "mystd.h"
int main() {
    mystd::MyString str;
    mystd::MyString str1(3, '!');
    char sen1 = 'a';
    str = str1;
    str = str;
    str = sen1;
    mystd::MyString str2("My string");
    //mystd::MyString str3 = str2 + sen1;
    //str3 += sen1;
    std::string Str1 = "asdasjdhaskdh";
    str2 = Str1;
    char y = str[-3];
    return 0;
}
