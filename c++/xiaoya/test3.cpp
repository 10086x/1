#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cout << "请输入一个字符串：";
    cin >> str;
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    if (str == reversed) {
        cout << "\"" << str << "\" 是回文串" << endl;
    } else {
        cout << "\"" << str << "\" 不是回文串" << endl;
    }
    
    return 0;
}