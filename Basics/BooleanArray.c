#include<stdio.h>
#include<stdbool.h>
int main()
{
	bool B[2] = {true, false};
	for(int i = 0; i < 2; i++)
			printf("| %d | \n", B[i]);
	return 0;
}
