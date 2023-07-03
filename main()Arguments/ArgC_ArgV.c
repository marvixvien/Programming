#include<stdio.h>
#include<stdlib.h>
void main(int argc, char* argv[])
{
    int x, y, z;
    if(argc == 3)
    {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
        z = x + y;
        printf("\nResult = %d.\n", z);
    }
    else 
    printf("\nIncorrect Argument Number!\n");
}