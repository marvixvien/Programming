#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXLen 80
int main()
{
    FILE *fp;
    char name[MAXLen];
    int acc;
    float balance;
    fp = fopen("myfile5.txt", "w");
    if(fp == NULL)
    {
        printf("\nCannot open File\n");
        exit(1);
    }
    do
    {
        printf("\nEnter Customer Name (press only Enter to end) : ");
        gets(name);
        if(strlen(name) == 0)
            break;
        printf("\nEnter Customer Account Number : ");
        scanf("%d", &acc);
        printf("\nEnter Customer Account Balance : ");
        scanf("%f", &balance);
        fprintf(fp, "Customer Name : %s\nCustomer Account Number : %d\nCustomer Balance : %f\n", name, acc, balance);
    }while(1);
    fclose(fp);
    return 0;
}