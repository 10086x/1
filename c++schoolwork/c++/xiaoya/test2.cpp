#include <iostream>

void stringCopy(const char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    str2[i] = '\0';
}
}

int main() {
    const char* str1 = "Hello, World!\0This part should not be copied";
    char str2[50]; 
    stringCopy(str1, str2);
    
    std::cout << "原始字符串 str1: " << str1 << std::endl;
    std::cout << "复制后的字符串 str2: " << str2 << std::endl;
    
    return 0;
}