#include<stdio.h>
void insertion (int a[], int n, int posI, int key)
{
	int index = posI - 1 , i = n - 1;
	while(i >= index)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[index] = key;
}
void deletion  (int a[], int n, int posD)
{
	int loc = posD - 1, i = n - 1;
	while(loc <= i)
	{
		a[loc] = a[loc + 1];
		loc++;
	} 
}
void display   (int a[], int n)
{
	int i;
	printf("\nThe element of the Array : \n");
	for(i=0;i<n;i++)
	{
		printf(" %3d,  ", a[i]);
	}
}
void main ()
{
	int a[20], i, posI, key, posD, n;
	printf("\nEnter how many element to insert into the Array[] : ");
	scanf("%d", &n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the Array[%d] : ", i);
		scanf("%d", &a[i]);
	}
	printf("\nThe Array is : \n");
	display(a,n);
	printf("\nInsert another element : \n");
	printf("\nEnter the position where you want to insert the element :");
	scanf("%d", &posI);
	printf("\nEnter the element you want to enter at %d position : ",posI);
	scanf("%d", &key);
	insertion(a,n,posI,key);
	n = n + 1;
	printf("\nAfter Insertion :\n");
	display(a,n);
	printf("\nDelete another element : \n");
    printf("\nEnter the position where you want to delete the element : ");
	scanf("%d", &posD);
	deletion(a,n,posD);
	n = n - 1;
	printf("\nAfter deletion the Array[] is  : \n");
	display(a,n);
	printf("\n\n");
}