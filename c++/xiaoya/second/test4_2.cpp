#include <iostream>
using namespace std;

void input(char *a)
{
    cout << "请输入一个字符串：";
    cin.getline(a, 100);  // 使用getline正确读取一行字符串
}

void removeChar(char *a, char c)
{
    char *b = a;  // 用于遍历原字符串
    char *d = a;  // 用于构建新字符串（不包含要删除的字符）
    
    while (*b)  // 遍历整个字符串
    {
        if (*b != c)  // 如果当前字符不是要删除的字符
        {
            *d = *b;  // 保留该字符
            d++;      // 移动目标指针
        }
        // 如果是要删除的字符，直接跳过不保留
        b++;  // 移动源字符串指针
    }
    *d = '\0';  // 添加字符串结束符
}

void select(char *a)
{
    removeChar(a, 'c');  // 直接调用删除函数删除所有'c'
}

int main()
{
    char *a = new char[100];
    input(a);
    select(a);
    cout << "处理后的字符串: " << a;
    delete[] a;  // 释放动态分配的内存
    return 0;
}
