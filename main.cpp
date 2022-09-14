#include <iostream>
#include "mystd.h"
int main() {
    mystd::MyString str;
    mystd::MyString str1(3, '!');
    str = str1;
    str = str;
    mystd::MyString str2("My string");
    return 0;
}
