#include <stdio.h>
int main() {
    char a = getchar();
    if (a != '\n') {  // 检查是否不是换行符
        printf("2\n");
    }
    return 0;
}
