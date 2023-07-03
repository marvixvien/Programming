#include<stdio.h>
int main()
{
	int i, j, k, n;
	printf("Enter the number of lines \n");
	scanf("%d", &n);
	k=n-1;
	for(i=0;i<n;i++)
	{
	    for(j=1;j<=k;j++)
		{
			printf(" ");
		}
		for(j=65+i;j>=65;j--)
		{
			printf("%c", j);
		}
		for(j=66;j<=65+i;j++)
		{
			printf("%c", j);
		}
		printf("\n");
	k--;
	}
	
}