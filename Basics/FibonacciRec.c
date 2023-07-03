#include<stdio.h>
int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else    
        return(fibonacci(n-1) + fibonacci(n-2));
}
int main()
{
    int n, i = 0, res;
    printf("\nEnter the number of Terms : ");
    scanf("%d", &n);
    printf("\nFibonacci Series : \n");
    for(i = 0; i < n; i++)
    {
        res = fibonacci(i);
        printf("| %d ", res);
    }
    printf("\n");
    return 0;
}