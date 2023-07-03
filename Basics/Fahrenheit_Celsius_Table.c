//print fahrenheit and celsius table
#include<stdio.h>
int main()
{
    int fahr;
    for(fahr=0;fahr<=300;fahr+=20)
    printf("%3d  %6d\n", fahr, (fahr-32)*(5)/(9));
    return 0;
}