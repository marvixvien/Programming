/*Write a programe in C to store all values of Fibonacci Sequence up to a given term N in an Array. 
  Use Recursion to Generate the Fibonacci Sequence.*/
#include<stdio.h>
#include<stdlib.h>
int fibonacci(int n)
{
    if(n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}
int main()
{
    int *parr, i, n;
    printf("\nEnter the Number of Terms : ");
    scanf("%d", &n);
    parr = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        *(parr + i) = fibonacci(i);
        printf("| %d | ", *(parr + i));
    }
    printf("\n");
    return 0;    
}