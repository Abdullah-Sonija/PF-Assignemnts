#include <stdio.h>

int main() {
    int num, count = 0;

    // Input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Process
    while (num != 0) {
        // Bitwise AND the number with 1 to check if the least significant bit is 1
        if (num & 1) {
            count++;
        }
        // Right shift the number by 1 to check the next bit
        num >>= 1;
    }

    // Output
    printf("The number of 1s in the binary representation is: %d\n", count);
    return 0;
}
