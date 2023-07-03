/*Allocating memory during Runtime*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, n, i, sum = 0;
    float avg;
    printf("\nEnter the total number of Students : ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("\nMemory Allocation was not possible\n");
        exit(1);
    }
    for (i = 0; i < n; i++)
    {
        printf("\nEnter marks of student %d : ", (i + 1));
        scanf("%d", p + i);
        sum = sum + *(p + i);
    }
    avg = (float)sum / n;
    printf("\nAverage marks = %f\n", avg);
    free(p);
    return 0;
}