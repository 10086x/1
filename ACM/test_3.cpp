#include <stdio.h>


int main() {
    unsigned long int num;
    scanf("%lu", &num);
    
    
    unsigned long int b1 = (num >> 56) & 0xFF;  
    unsigned long int b2 = (num >> 48) & 0xFF;  
    unsigned long int b3 = (num >> 40) & 0xFF;
    unsigned long int b4 = (num >> 32) & 0xFF;
    unsigned long int b5 = (num >> 24) & 0xFF;
    unsigned long int b6 = (num >> 16) & 0xFF;
    unsigned long int b7 = (num >> 8)  & 0xFF;  
    unsigned long int b8 = num & 0xFF;         

  
    long int new_num = (b8 << 56) |  
                       (b7 << 48) |  
                       (b3 << 40) |
                       (b4 << 32) |
                       (b5 << 24) |
                       (b6 << 16) |
                       (b2 << 8)  |  
                       b1;          

    printf("%lx\n", new_num);
    return 0;
}

