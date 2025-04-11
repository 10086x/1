#include <stdio.h>
#include <stdint.h>

int main() {
    uint64_t num;
    // 输入长整型数（十六进制格式，如1122334455667788）
    scanf("%llx", &num);

    // 提取各字节
    uint8_t b1 = (num >> 56) & 0xFF;  // 最高8位
    uint8_t b2 = (num >> 48) & 0xFF;  // 次高8位
    uint8_t b3 = (num >> 40) & 0xFF;
    uint8_t b4 = (num >> 32) & 0xFF;
    uint8_t b5 = (num >> 24) & 0xFF;
    uint8_t b6 = (num >> 16) & 0xFF;
    uint8_t b7 = (num >> 8)  & 0xFF;  // 次低8位
    uint8_t b8 = num & 0xFF;          // 最低8位

    // 重组数值，交换字节位置
    uint64_t new_num = ((uint64_t)b8 << 56) |  // 原最低8位放到最高
                       ((uint64_t)b7 << 48) |  // 原次低8位放到次高
                       ((uint64_t)b3 << 40) |
                       ((uint64_t)b4 << 32) |
                       ((uint64_t)b5 << 24) |
                       ((uint64_t)b6 << 16) |
                       ((uint64_t)b2 << 8)  |  // 原次高8位放到次低
                       (uint64_t)b1;          // 原最高8位放到最低

    // 输出十六进制结果，补前导零至16位
    printf("%016llx\n", new_num);
    return 0;
}
