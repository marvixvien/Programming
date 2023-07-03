/*Use of Array of Function Pointers*/
#include<stdio.h>
double add(float a, float b);
double sub(float a, float b);
double mul(float a, float b);
double div(float a, float b);
void main()
{
    int choice;
    float num1, num2;
    double (*pcalculate[4])(float, float) = {add, sub, mul, div}; 
    /*Array of Pointer to a Function type elements declared*/
    /*Array elements initialised with these function names :- add, sub, mul, div.*/
    printf("Enter the first number : ");
    scanf("%f", &num1);
    printf("Enter the second number : ");
    scanf("%f", &num2);
    printf("\n<0>Addition. \n<1>Subtraction. \n<2>Multiplication. \n<3>Division.\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    printf("\nThe result is %lf.\n\n", pcalculate[choice](num1,num2));/*Function called through Pointer*/
}

double add(float a, float b)
{
    return (a+b);
}
double sub(float a, float b)
{
    return (a-b);
}
double mul(float a, float b)
{
    return (a*b);
}
double div(float a, float b)
{
    return (a/b);
}