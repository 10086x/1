#include <iostream>
#include <windows.h> // Windows骞冲彴缂栫爜璁剧疆
using namespace std;

// 璁剧疆鎺у埗鍙癠TF-8缂栫爜鐨勫垵濮嬪寲鍑芥暟
void initConsoleUTF8() {
#ifdef _WIN32
    SetConsoleOutputCP(65001); // UTF-8浠ｇ爜椤?
#endif
}

int main() {
    initConsoleUTF8(); // 鍒濆鍖栨帶鍒跺彴缂栫爜
    
    // 浣犵殑浠ｇ爜浠庤繖閲屽紑濮?
    cout << "涓枃瀛楃娴嬭瘯" << endl;
    
    return 0;
}
