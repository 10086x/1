#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

bool isArmstrong(int num) {
    int original = num;
    int sum = 0;
    
    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, 3);
        num /= 10;
    }
    
    return sum == original;
}

int main() {
    SetConsoleOutputCP(65001); // 设置控制台输出为UTF-8编码
    cout << "1000以内的阿姆斯特朗数有：" << endl;
    for (int i = 1; i < 1000; i++) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
