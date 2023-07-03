#include<stdio.h>
void floor(int a, int b)
{
	int result;
	float c;
	c = a/b;
	if(c >= 0)
		result = (int)c;
	else
		result = (int)c - 1;
	printf("a // b = %d\n", result);
}
int main()
{
	float a, b, result;
	printf("\nEnter a : ");
	scanf("%f", &a);
	printf("\nEnter b : ");
	scanf("%f", &b);
	floor(a,b);
	return 0;
}