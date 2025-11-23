#include <iostream>
#include <cstring>
using namespace std;

typedef struct note {
    int length;   // 当前栈中元素个数
    char *num;    // 栈底指针
    char *tail;   // 栈顶指针
} stdf, *stdet;

// 初始化栈
void initnum(stdf &sdf, int a) {
    sdf.length = 0;
    sdf.num = new char[a];
    sdf.tail = sdf.num;
}

// 压栈
int poshnum(stdf &sdf, char ch) {
    *sdf.tail = ch;
    sdf.tail++;
    sdf.length++;
    return 1;
}

// 出栈
int outnum(stdf &sdf, char &x) {
    if (sdf.length == 0) return 0;
    sdf.tail--;
    x = *sdf.tail;
    sdf.length--;
    return 1;
}

// 判空
int selectnum(stdf sdf) {
    return sdf.length != 0;
}

// 获取第一个（栈底）元素
char firstnum(stdf sdf) {
    if (sdf.length == 0) return 0;
    return *sdf.num;
}

// 判断是否为回文
bool isPalindrome(const char *numd) {
    int len = strlen(numd);
    stdf sdf;
    initnum(sdf, len);

    int mid = len / 2;
    for (int i = 0; i < mid; i++) {
        poshnum(sdf, numd[i]);
    }

    int start = (len % 2 == 0) ? mid : mid + 1;
    char temp;
    for (int i = start; i < len; i++) {
        if (!outnum(sdf, temp)) return false;
        if (temp != numd[i]) return false;
    }

    delete[] sdf.num;
    return true;
}

int main() {
    char numd[100];
    cout << "请输入一个数字串：";
    cin >> numd;

    if (isPalindrome(numd))
        cout << numd << " 是回文数！" << endl;
    else
        cout << numd << " 不是回文数！" << endl;

    return 0;
}
