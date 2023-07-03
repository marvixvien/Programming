#include<stdio.h>
int main()
 {
   int i,j,k,rem=0;
   char ans;
   do
   {
   printf("\n enter two integers ");
   scanf("%d %d",&i,&j);
   if(j>i)
      {
          k=i;
          i=j;
          j=k;

      }
         rem=i%j;
    while(rem != 0)
      {
          i=j;
          j=rem;
          rem=i%j;
      }
    printf("the gcd is %d",j);
    printf("\ndo you like to continue?  ");
    scanf(" %c",&ans);
    }
   while(ans=='y' || ans=='Y');
 }
