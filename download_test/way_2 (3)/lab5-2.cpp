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
    SetConsoleOutputCP(65001); // 璁剧疆鎺у埗鍙拌緭鍑轰负UTF-8缂栫爜
    cout << "1000浠ュ唴鐨勯樋濮嗘柉鐗规湕鏁版湁锛? << endl;
    for (int i = 1; i < 1000; i++) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
