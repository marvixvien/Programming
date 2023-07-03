#include<stdio.h>
main()
{
	int n, num, digit, sum = 0, rev = 0;
	printf("Input the Number : ");
	scanf("%d", &num);
	n=num;
	do
	{
		digit = num % 10;
		sum += digit;
		rev =rev*10 + digit;
		num /= 10;
	}while(num != 0);
	printf("Sum of the Digits of the Number = %d\n", sum);
	printf("Reverse of the Number = %d\n", rev);
	if(n == rev)
	   printf("The Number is a Palindrome");
	else
	   printf("The Number is not a Palindrome");

}