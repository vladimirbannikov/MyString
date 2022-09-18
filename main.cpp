#include <iostream>
#include "mystd.h"
int main() {
    mystd::MyString str;
    mystd::MyString str1(3, '!');
    char sen1[] = "asdasdasdasd";
    str = str1;
    str = str;
    str = sen1;
    mystd::MyString str2("My string");
    //mystd::MyString str3 = str2 + sen1;
    //str3 += sen1;
    std::string Str1 = "asdasdasdasc";
    str2 = Str1;
    char y = str[-3];
    bool i = (str2 < str2);
    std::string data("asd");
    const char* s = data.data();
    str2.clear();
    std::cin >> str2;
    std::cout << str2;
    std::string Str2(str2.data());
    std::cout << Str2 << Str2;
    return 0;
}
