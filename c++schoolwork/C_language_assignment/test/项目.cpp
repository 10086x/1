#include <stdio.h>

void printTopLeft() {
    printf("左上角格式：\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = i; j <= 9; j++) {
            printf("%d*%d=%-2d ", i, j, i*j);
        }
        printf("\n");
    }
}

void printTopRight() {
    printf("右上角格式：\n");
    for (int i = 1; i <= 9; i++) {
        for (int k = 1; k < i; k++) {
            printf("        ");      
        }
        for (int j = i; j <= 9; j++) {
            printf("%d*%d=%-2d ", i, j, i*j);
        }
        printf("\n");
    }
}

void printBottomLeft() {
    printf("左下角格式：\n");
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%-2d ", j, i, j*i);
        }
        printf("\n");
    }
}

void printBottomRight() {
    printf("右下角格式：\n");
    for (int i = 1; i <= 9; i++) {
        for (int k = 1; k <= 9 - i; k++) {
            printf("        ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d*%d=%-2d ", j, i, j*i);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("请选择格式(1 2 3 4 其他-退出): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: printTopLeft(); break;
        case 2: printTopRight(); break;
        case 3: printBottomLeft(); break;
        case 4: printBottomRight(); break;
        default: printf("输入错误，程序退出。\n"); return 0;
    }
    
    return 0;
}

