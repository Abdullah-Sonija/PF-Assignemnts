#include<stdio.h>
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
	int t[col][row];

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
	
	//Transpose
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			t[j][i]=m[i][j];
		}
	}

	//Output
	printf("Transposed matrix:\n");
	for(i=0;i<col;i++)
	{
		for(j=0;j<row;j++)
		{
			printf("%d ", t[i][j]);
		}
		printf("\n");
	}
	return 0;
}	

