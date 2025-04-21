#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8编码
    int n;
    cout << "请输入自然数n: ";
    cin >> n;
    
    int start = n * n - n + 1;  // 计算连续奇数的起始值
    cout << n << "^3 = ";
    
    for (int i = 0; i < n; i++) {
        cout << start + 2 * i;
        if (i != n - 1) cout << "+";
    }
    
    cout << endl;
    return 0;
}
