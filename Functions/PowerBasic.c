#include<stdio.h>
int power(int base, int pow)
{
    int i, p;
    p = 1;
    for(i=1;i<=pow;++i)
    p = p * base;
    return p;
}
int main()
{
    int i;
    for(i=0;i<10;++i)
    printf("%3d  %3d  %3d\n", i, power(2,i), power(-3,i));
    return 0;
}