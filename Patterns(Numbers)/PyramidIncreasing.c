#include<stdio.h>
int main()
{
	int i,k,l,m,n,p;
	printf("Enter the lines : ");
	scanf("%d",&n);
	for(l=1;l<=n;l++)
	{
		for(i=1;i<=n-l;i++)
		  printf("   ");
		m=l;
		for(p=1;p<=l;p++)
		{
			printf("%3d",m);
			m++;
		}
		m=m-2;
		for(k=1;k<l;k++)
		{
			printf("%3d",m);
			m--;
		}
		printf("\n");
	}
}