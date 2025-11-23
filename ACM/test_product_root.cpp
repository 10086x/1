#include<stdio.h>

int calculate_product_root(int num) {
    while(num >= 10) {
        int product = 1;
        while(num > 0) {
            int digit = num % 10;
            product *= (digit == 0 ? 1 : digit);
            num /= 10;
        }
        num = product;
    }
    return num;
}

int main() {
    int counts[10] = {0}; // counts[1] to counts[9] will be used
    
    for(int i = 1; i <= 1000; i++) {
        int root = calculate_product_root(i);
        if(root >= 1 && root <= 9) {
            counts[root]++;
        }
    }
    
    printf("在1到1000中，数字乘积根为1~9的正整数的个数分别为：\n");
    for(int i = 1; i <= 9; i++) {
        printf("数字乘积根为%d的正整数个数为：%d\n", i, counts[i]);
    }
    
    return 0;
}
