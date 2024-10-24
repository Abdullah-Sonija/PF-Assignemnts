#include <stdio.h>
int main()
{
	int row, col;
	
	//Input size
	printf("Enter the number of rows of the matrix: ");
	scanf("%d", &row);
	printf("Enter the number of columns of the matrix: ");
	scanf("%d", &col);
	
	//Matrix array 
	int m[row][col];

	//Input elements
	int i, j;
	printf("Enter the elements of the matrix:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Element[%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
	}

    //Finding maximum
    int max=m[0][0];
    int max_row=0;
    int max_col=0;

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(m[i][j]>max)
            {
                max=m[i][j];
                max_row=i;
                max_col=j;
            }
        }
    }

    //Output
    printf("Maximun Element %d is at (%d, %d).\n", max, max_row+1, max_col+1);

    return 0;
}