#include <stdio.h>

int main() {
    char c, s[100], m[100];
    c = 'c';
    printf("input string:\n");
    scanf("%s", s);  
    getchar();
    
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            m[j] = s[i];
            j++;
        }
    }
    m[j] = '\0';
    
    printf("\nResult: %s\n", m);
    return 0;
}
