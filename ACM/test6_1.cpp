#include <stdio.h>
#include <string.h>

int main() {
    int need[100];
    int last = 0;  // 阿姆斯特朗数计数器
    
    for (int i = 0; i <= 1000; i++) {
        char h[5];  // 4位数+终止符足够
        int sum = 0;
        
        // 获取数字位数
        sprintf(h, "%d", i);
        int now = strlen(h);
        
        // 分解各位数字并计算立方和
        int d = i;
        for (int b = 0; b < now; b++) {
            int digit = d % 10;  // 直接获取最后一位
            sum += digit * digit * digit;
            d /= 10;  // 移除最后一位
        }
        
        // 存储符合条件的数
        if (sum == i) {
            need[last] = i;
            last++;  // 先存储后自增
        }
    }
    
    // 输出结果
    for (int g = 0; g < last; g++) {
        printf("%d ", need[g]);
    }
    return 0;
}
