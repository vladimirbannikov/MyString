#include <iostream>
#include "mystd.h"
int main() {
    mystd::MyString str;
    mystd::MyString str1(3, '!');
    char sen1[] = "asdasdasdasd";
    mystd::MyString str2("MyString");
   // std::cout << str2.data();
    //std::cout << str2;
    //std::string Str2(str2.data());
    //std::cout << Str2 << Str2;
    str2.insert(0, "12345", 10);
    std::cout << str2.c_str();
    str2.erase(1, 0);
    return 0;
}
