#include<stdio.h>
double power(float base, float pow)
{
    double i=1;
    if(pow >= 0)
    {
        while(pow--)
        {
           i *= base; 
        }
    }
    else
    { 
        while(pow++)
        {
            i /= base;
        }
    }
    return i;
}
float main()
{
    float b, p;
    printf("Input Base and Index : ");
    scanf("%f %f", &b, &p);
    printf("%f to the power %f is : %f\n", b, p, power(b,p));
    return 0;
}