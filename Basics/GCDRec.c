#include<stdio.h>
int gcd(int i, int j)
{
    int rem;
    rem = i % j;
    if(rem == 0)
        return j;
    else
        return (gcd(j,rem));
}
int main()
{
   int i,j;
   printf("\n Enter two integers : ");
   scanf("%d %d",&i, &j);
   printf("\nGCD of %d & %d is = %d\n", i , j, gcd(i,j));
   return 0;
}