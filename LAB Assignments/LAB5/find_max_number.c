#include <stdio.h>
int main() {
    int n1, n2, max;
    printf("Enter the first number: ");
    scanf("%d", &n1);
    printf("Enter the second number: ");
    scanf("%d", &n2);
    max = (n1 > n2) ? n1 : n2;
    printf("The maximum of %d and %d is: %d\n", n1, n2, max);
    return 0;
}
