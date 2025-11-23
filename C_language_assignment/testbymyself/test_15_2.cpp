#include <stdio.h>

// 计算数字的乘积根（1-9之间的数字）
int getProductRoot(int num) {
    int product;
    
    do {
        product = 1;
        while (num > 0) {
            int digit = num % 10;
            if (digit != 0) {  // 忽略0
                product *= digit;
            }
            num /= 10;
        }
        num = product;  // 准备下一次迭代
    } while (product > 9);  // 直到得到1位数
    
    return product;
}

void countProductRoots(int counts[10]) {
    for (int i = 1; i < 1000; i++) {
        int root = getProductRoot(i);
        counts[root]++;
    }
}

int main() {
    int counts[10] = {0};  // counts[0]不使用
    
    countProductRoots(counts);
    
    printf("在1到1000中，数字乘积根为1~9的正整数的个数分别为：\n");
    for (int i = 1; i < 10; i++) {
        printf("%d: %d\n", i, counts[i]);
    }
    
    return 0;
}