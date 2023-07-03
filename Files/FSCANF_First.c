#include<stdio.h>
#include<stdlib.h>
#define MAXLen 80
int main()
{
    FILE *fp;
    int acc;
    float balance;
    fp = fopen("myfile3.txt", "a+");
    if(fp == NULL)
    {
        printf("\nCannot Open File.\n");
        exit(1);
    }
    while(fscanf(fp, "%d %f"))
    fclose(fp);
    return 0;
}