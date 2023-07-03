#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *parrA = NULL, *parrB = NULL, n, m, o = 0, i = 0, j = 0;
    printf("\nEnter the size of A array : ");
    scanf("%d", &n);
    parrA = (int *)malloc(n * sizeof(int));    
    printf("\nEnter the Elements of array A(Half of it's Size) : \n");
    for (i = 0; i < n/2; i++)
    {
        scanf("%d", (parrA + i));
    }
    printf("\nEnter the size of B array(Please Note that the size should be or less than the half of array A) : ");
    scanf("%d", &m);
    parrB = (int *)malloc(m * sizeof(int));
    printf("\nEnter the Elements of array B : \n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", (parrB + i));
    }
    for (i = 0; i < n/2; i++)
    {
        *(parrA + o) = *(parrA + i);
        o++;
    }
    for (i = 0; i < m; i++)
    {
        *(parrA + o) = *(parrB + i);
        o++;
    }
    printf("\nThe Merged Array is : ");
    for (i = 0; i < n; i++)
        printf("\nArraar A[%d] = %d", i, *(parrA + i));
    
    printf("\n");
    return 0;
}