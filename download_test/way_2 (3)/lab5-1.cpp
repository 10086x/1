#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001); // 璁剧疆鎺у埗鍙拌緭鍑轰负UTF-8缂栫爜
    int n;
    cout << "璇疯緭鍏ヨ嚜鐒舵暟n: ";
    cin >> n;
    
    int start = n * n - n + 1;  // 璁＄畻杩炵画濂囨暟鐨勮捣濮嬪€?
    cout << n << "^3 = ";
    
    for (int i = 0; i < n; i++) {
        cout << start + 2 * i;
        if (i != n - 1) cout << "+";
    }
    
    cout << endl;
    return 0;
}
