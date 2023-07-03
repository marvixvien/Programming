//Using indirection operator on left
#include<stdio.h>
void main()
{
    int num, result, *preresult = NULL; //pointer declared
    preresult = &result;
    printf("Enter a Number : ");
    scanf("%d", &num);
    *preresult = num * num; //Value pointed bt Preresult
    printf("Square of the number = %d\n", *preresult);
} 