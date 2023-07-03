#include<stdio.h>
int prime(int x);
main()
{
   int res,lr;
   printf("Enter a no.:-");
   scanf("%d", & lr);
   /* calling function  */
   res=prime(lr);             
   if(res==0)
       printf("not prime");
   else
       printf("prime");
 }
 /*     called function    */
 int prime(int x)
{
       int st,i=1,p;
       do
      {

       st=(x%prime(x-i));
	   i=i+1;
	   p=x-i;
        if(st==0)
        return(0);  
      }
       while(p>=2);
       return(x);
}