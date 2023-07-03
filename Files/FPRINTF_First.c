#include<stdio.h>
#include<stdlib.h>
int main ()
{
    FILE *fp;
    int acc;
    float balance;
    fp = fopen("myfile3.txt", "w");
    if(fp == NULL)
    {
        printf("\nCannot open File");
        exit(1);
    }
    do
    {
        printf("\nEnter Coustomer Account Number (press 0 to end) : ");
        scanf("%d", &acc);
        if(acc == 0)
            break;
        printf("\nEnter Customer Account Balance : ");
        scanf("%f", &balance);
        fprintf(fp, "Customer Number : %4d | Customer Balance : %5.2f\n", acc, balance);
    }while(1);
    fclose(fp);
    return 0;
}