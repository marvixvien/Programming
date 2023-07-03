#include<stdio.h>
#include<math.h>
float main()
{
    double base, index;
    printf("Enter the value of Base and Index : ");
    scanf("%f %f", &base, &index);
    printf("%f to the power %f is : %f \n", base , index, pow(base, index));
    return 0;
}