#include <stdio.h>

int main() {
    int n, i, j;

    // Isize
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int matrix[n][n];

    // Elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    //Diagonal elements
    printf("Diagonal elements are:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");

    return 0;
}
