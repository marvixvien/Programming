#include<stdio.h>
int main()
{
	int p, q, i, j, a[10][10], b[10][10];
	printf("Enter Number of Rows and Columns : \n");
	scanf("%d  %d", &p, &q);
	printf("Enter a %d X %d Matrix : \n", p, q);
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("a[%d][%d] = ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
	}
	printf("\n The Entered Matrix Is : \n");
	for(i=0;i<p;i++)
	{
		printf("\n");
		for(j=0;j<q;j++)
		{
			printf("  %d  ", a[i][j]);
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
		    b[j][i] = a[i][j];
	    }
	}
	printf("\nThe Transpose of the Matrix is : \n");
	for(i=0;i<q;i++)
	{  
		printf("\n");
		for(j=0;j<p;j++)
		{
			printf("  %d  ", b[i][j]);

    	}
	}		
	printf("\n");
	return 0;
}
