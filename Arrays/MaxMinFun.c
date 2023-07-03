#include<stdio.h>
int max_min(int[],int);
int main()
{
	int a[20], n, i;
	printf("Enter the Limit : ");
	scanf("%d", &n);
	printf("Enter the Elements : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	max_min(a,n);
	return 0;
}
int max_min(int a[], int n)
{
	int i, max, min;
	max = a[0];
	min = a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
		else if(a[i]<min)
		{
			min = a[i];
		}
	}
	printf("The Maximum element is : %d.\nThe Minimum element is : %d.", max, min);
	return 0;
}
