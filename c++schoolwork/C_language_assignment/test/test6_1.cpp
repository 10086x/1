#include <stdio.h>
#include <string.h>

#define MAX_NUM 1000
#define MAX_ARMSTRONG_NUMBERS 10  // More than enough space

/**
 * Finds and prints all Armstrong numbers between 0 and MAX_NUM.
 * An Armstrong number is a number that equals the sum of its digits' cubes.
 */
int main() {
    int armstrong_numbers[MAX_ARMSTRONG_NUMBERS];
    int count = 0;  // Count of found Armstrong numbers
    
    for (int i = 0; i <= MAX_NUM; i++) {
        char num_str[5];  // Enough for 4-digit numbers + null terminator
        int sum = 0;
        
        // Convert number to string to get digit count
        sprintf(num_str, "%d", i);
        int digit_count = strlen(num_str);
        
        // Calculate sum of cubes of digits
        int temp = i;
        for (int digit_pos = 0; digit_pos < digit_count; digit_pos++) {
            int digit = temp % 10;  // Get last digit
            sum += digit * digit * digit;
            temp /= 10;  // Remove last digit
        }
        
        // Store if Armstrong number found
        if (sum == i) {
            armstrong_numbers[count] = i;
            count++;
        }
    }
    
    // Print all found Armstrong numbers
    printf("Armstrong numbers between 0 and %d: ", MAX_NUM);
    for (int i = 0; i < count; i++) {
        printf("%d ", armstrong_numbers[i]);
    }
    printf("\n");
    
    return 0;
}
