#include <stdio.h>
#include <string.h>

int main() {
    int need[100];
    int last = 0;  // 记录水仙花数的个数
    
    
    for (int i = 0; i <= 1000; i++) {
        char h[5];  // 4位数字+结束符
        int sum = 0;
        
        // 将数字转换为字符串
        sprintf(h, "%d", i);
        int now = strlen(h);
        
        // 计算各位数字的立方和
        int d = i;
        for (int b = 0; b < now; b++) {
            int digit = d % 10;  // 取得最后一位数字
            sum += digit * digit * digit;
            d /= 10;  // 去掉最后一位数字
        }
        
        // 判断是否为水仙花数
        if (sum == i) {
            need[last] = i;
            last++;  // 记录找到的水仙花数
        }
    }
    
    // 输出所有找到的水仙花数
    for (int g = 0; g < last; g++) {
        printf("%d ", need[g]);
    }
    return 0;
}
