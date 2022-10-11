#include <iostream>
#include "mystd.h"
int main() {
    mystd::MyString str;
    //mystd::MyString str1("Str");
    //char sen1[] = "asdasdasdasd";
    //mystd::MyString str1(1.2, 'a');
    //std::string str2(1.2, 'a');
    //mystd::MyString str2("MyStringyString");
   // std::cout << str2.data();
    //std::cout << str2;
    //std::string Str2(str2.data());
    //std::cout << Str2 << Str2;
    //str2.insert(8, "12345", 7);
    //std::cout << str2.c_str() << std::endl;
    //str2.replace(3, 5, "");
    //std::cout << str2.c_str();
    //int i = str2.find(str1.data(), 0);
    //std::cout << str2.substr(5);
    //std::cout << i;

    mystd::MyString str1("St123123123r");
    mystd::MyString str2("Str");
    str1 = str2;
    return 0;
}
