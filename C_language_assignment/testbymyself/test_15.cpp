#include<stdio.h>

#include<string.h>
#include<stdlib.h>
int List(int m) {
    int product = 1;
    while (m > 0) {
        int digit = m % 10;
        if (digit != 0) {  // 忽略0
            product *= digit;
        }
        m /= 10;
    }
    return product;
}
void ste(int str[10]) {
    for(int i=1; i<=10000; i++){
        int m=List(i);
        while(1){
            if(m>9){
                m=List(m);
            }else{
                str[m]++;
                break;
            }
        }
    }
}
int main() {
    int str[10] = {0};
    ste(str);
    printf("在1到1000中，数字乘积根为1~9的正整数的个数分别为：\n");
    for (int i = 1; i < 10; i++) {
        printf("数字乘积根为%d的正整数个数为：%d\n", i, str[i]);
    }
    return 0;
}
