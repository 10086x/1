#include <iostream>
#include <windows.h> // Windows平台编码设置
using namespace std;

// 设置控制台UTF-8编码的初始化函数
void initConsoleUTF8() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8代码页
#endif
}

int main() {
    initConsoleUTF8(); // 初始化控制台编码
    
    // 你的代码从这里开始
    cout << "中文字符测试" << endl;
    
    return 0;
}
