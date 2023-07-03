#include<stdio.h>
int main()
{
   int max, a, b;
    printf("\nEnter two numbers: ");
    scanf("%d %d",&a,&b);
    max = (a > b) ? a: b;
     while (1)
     { 
        if (max % a== 0 && max % b== 0)            
		 { 
            printf("The LCM of %d and %d is %d.", a, b, max); 
            break; 
         } 
        ++max; 
     }
  return 0; 
}