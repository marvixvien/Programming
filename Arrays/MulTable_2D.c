#include<stdio.h>
int main()
{
	int row, column, product[10][10];
	int i, j;
	printf(" Multiplication Table \n\n");
	printf("     ");
	for (column = 1; column <= 10; column++)
	printf("%4d", column);
	printf("\n-----------------------------------------------\n");
	for(i=0;i<10;i++)
	{
		row = i + 1;
		printf("\n%3d |", row);
		for(j=0;j<10;j++)
		{
			column = j + 1;
			product[i][j] = row * column;
			printf("%4d", product[i][j]);
		}
		printf("\n");
	}
    return 0;
}