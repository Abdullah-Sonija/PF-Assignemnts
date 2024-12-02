#include <stdio.h>
#include <stdlib.h>

int main() {
    char *num = NULL;
    char *iterator;
    int ch;
    size_t size = 0;

    printf("Enter the number: ");
    
    while ((ch = getchar()) != '\n' && ch != EOF) {
        num = (char *)realloc(num, size + 1);
        if (num == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        num[size++] = ch;
    }

    // Null-terminate the string
    num = (char *)realloc(num, size + 1);
    num[size] = '\0';

    iterator = num;

    while (*iterator != '\0') {
        printf("%c", *iterator);
        iterator++;
    }

    free(num);

    return 0;
}
