#include <iostream>
#include "mystd.h"
int main() {
    mystd::MyString str1("abcqweytqrweyqrw1111111111111111111111111111111111111111e");
    str1 = "qwerty";
    std::cout << str1.capacity() << std::endl;
    str1.shrink_to_fit();
    std::cout << str1.capacity() << std::endl;
    return 0;
}
