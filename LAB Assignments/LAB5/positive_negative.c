#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    const char* result = (n > 0) ? "Positive" : (n < 0) ? "Negative" : "Zero";
    printf("The number is: %s\n", result); 
    return 0;
}
