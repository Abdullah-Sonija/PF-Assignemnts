#include <stdio.h>

int main() {
    int size, i, max = 0;
    
    printf("Enter how many numbers you want to enter: ");
    scanf("%d", &size);
    
    int array[size];

    // Input
    for (i = 0; i < size; i++) {
        printf("Enter the Element %d: ", i + 1);
        scanf("%d", &array[i]);
        if (array[i] > max) {
            max = array[i];
        }
    }

    // Process
    
    int freq[max + 1];
    for (i = 0; i <= max; i++) {
        freq[i] = 0;
    }

    
    for (i = 0; i < size; i++) {
        freq[array[i]]++;
    }

    // Check for duplicates
    for (i = 0; i <= max; i++) {
        if (freq[i] > 1) {
            printf("Number %d occurs more than once\n", i);
        }
    }

    return 0;
}
