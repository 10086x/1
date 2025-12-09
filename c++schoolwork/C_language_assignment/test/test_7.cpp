#include <stdio.h>

int main() {
    printf("1000以内的所有阿姆斯特朗数");
    for (int num = 1; num < 1000; num++) {
        int a = num;
        int sum = 0;
        
        while (a != 0) {
            int d = a % 10;
            sum += d * d * d;
            a /= 10;
        }
        
        if (sum == num) {
            printf("%d ", num);
        }
    }
    
    printf("\n");
    return 0;
}
