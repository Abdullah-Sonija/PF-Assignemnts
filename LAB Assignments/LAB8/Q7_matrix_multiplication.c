#include <stdio.h>

//Input Function
void input(int matrix[3][3], const char *name)
{
    int i, j;
    printf("Enter Elements of %s [3x3] matrix:\n", name);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d ", &matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix1[3][3], matrix2[3][3], result[3][3]={0};
    int m=0, i, j, k;

    //Input
    input(matrix1, "first");
    input(matrix2, "second");


    //Multiplication
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<3;k++)
            {
                result[i][j]+=matrix1[i][k]*matrix2[k][j];
            }
        }
    }

    //Output
    printf("Resultant matrix:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}