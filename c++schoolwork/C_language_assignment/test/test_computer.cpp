#include <stdio.h>
int main() {
    printf("short: %zu bits\n", sizeof(short) * 8);
    printf("int: %zu bits\n", sizeof(int) * 8);
    printf("long: %zu bits\n", sizeof(long) * 8);
    printf("long long: %zu bits\n", sizeof(long long) * 8);
    return 0;
}

