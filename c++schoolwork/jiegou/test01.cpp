///八皇后问题
#include <iostream>
#include <cstring>
using namespace std;
#define N 8
int count1 = 0; // 记录解的个数

typedef struct note {
    int length;   // 当前栈中元素个数
    char *num;    // 栈底指针
    char *tail;   // 栈顶指针
} stdf, *stdet;
void popint(stdf &sdf, int &x) {
    if (sdf.length == 0) return;
    sdf.tail--;
    x = *sdf.tail;
    sdf.length--;
}
void inputint(stdf &sdf, int x) {
    *sdf.tail = x;
    sdf.tail++;
    sdf.length++;
}
void initint(stdf &sdf, int a) {
    sdf.length = 0;
    sdf.num = new char[a];
    sdf.tail = sdf.num;
}
bool check(int i, int place[]) {
    int j = 0;
    for (j = 0; j < i; j++) {
        
        if (place[j] == sd[i] || abs(place[j] - sd[i]) == abs(j - i)) {
            return false;
        }
    }
    return true;
}

int main(){
    stdf sdf;
    initint(sdf, N);
    int place[N]={0};
    do {
        int i = 0;
        int sd[65]={0};
        for (i = 0; i < sdf.length; i++) {
            sd[i] = sdf.num[i];
        }
    }while (sdf.length < N);
    
}
